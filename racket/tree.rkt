#lang racket
(define (concat l) (foldr append `() l))
(define-syntax lc
  (syntax-rules (: <- @)
    [(lc exp : var <- lexp) (map (lambda (var) exp) lexp)]
    [(lc exp : @ guard) (if guard (list exp) `())]
    [(lc exp : @ guard qualifier ...)
     (concat (lc (lc exp : qualifier ...) : guard))]
    [(lc exp : var <- lexp qualifier ...)
     (concat (lc (lc exp : qualifier ... ) : var <- lexp))]))

(struct node(val ltree rtree)#:transparent)
(struct nulltree() #:transparent)

(define t4 (node 2(node 1 (nulltree) (nulltree))
                 (node 3 (nulltree) (nulltree))))
(define t6 (node 6 (nulltree) (nulltree)))
(define t7 (node 2 (node 7 (nulltree) (nulltree))
                 (node 9 (nulltree) (nulltree))))
(define t8 (node 8 (node 7 (nulltree) (nulltree))
                 (node 9 (nulltree) (nulltree))))
(define t10 (node 12 (node 11 (nulltree) (nulltree))
                  (node 13 (nulltree) (nulltree))))
(define t11 (node 16 (node 15 (nulltree) (nulltree))
                  (node 17 (nulltree) (nulltree))))
(define t9 (node 14 t10 t11))
(define t3 (node 10 t8 t9))
(define t5 (node 5 (nulltree) (nulltree)))
(define t2 (node 4 t4 t5))
(define t1 (node 6 t2 t3))

(define(flatten t)
  (cond[(nulltree? t) '()]
       [else (append (flatten(node-ltree t))
                     (cons (node-val t)(flatten(node-rtree t))))]))

(define(insert r t)
  (cond[(nulltree? t)(node r (nulltree)(nulltree))]
       [(<=(node-val t) r)(node (node-val t)
                                (node-ltree t)
                                (insert r (node-rtree t)))]
       [(>(node-val t) r)(node (node-val t)
                               (insert r (node-ltree t))
                               (node-rtree t))]))

(define (search x t)
  (cond ((nulltree? t) #f)
        ((= x (node-val t)) #t)
        ((<= x (node-val t)) (search x (node-ltree t)))
        ((> x (node-val t)) (search x (node-rtree t)))))

(define(createtree set)
  (cond[(null? set)(nulltree)]
       [else(let*((left (lc x : x <- (cdr set) @ (<= x (car set))))
                  (rt   (lc x : x <- (cdr set) @ (> x (car set)))))
              (node (car set)(createtree left)(createtree rt)))]))

(define (createtree2 set)
  (if (null? set) (nulltree)
      (let* ([l (lc x : x <- (cdr set) @ (<= x (car set)))]
             [r (lc x : x <- (cdr set) @ (> x (car set)))])
        (node (car set) (createtree2 l) (createtree2 r)))))

(define(delete r t)
  (cond[(nulltree? t)t]
       [(> r(node-val t))(node (node-val t)
                               (node-ltree t)
                               (delete r (node-rtree t)))]
       [(= r(node-val t))(join (node-ltree t)
                               (node-rtree t))]
       [(<= r(node-val t))(node(node-val t)
                               (delete r (node-ltree t))
                               (node-rtree t))]))

(define(join lt rt)
  (cond[(nulltree? lt)rt]
       [(nulltree? rt)lt]
       [(join lt rt)])); not made correctly, to be done later

(struct bnode (ltree rtree) #:transparent)
(struct leaf (val) #:transparent)

(define example-huffman (bnode
                         (leaf 'A)
                         (bnode
                          (bnode (leaf 'B)
                                 (bnode (leaf 'C)
                                        (leaf 'D)))
                          (bnode
                           (bnode (leaf 'E)
                                  (leaf 'F))
                           (bnode (leaf 'G)
                                  (leaf 'H))))))

(define(decode t l)
  (define(decode-h t1 l)
    (cond[(and(not(leaf? t1))(null? l)) "subsequent list is not correct"]
         [(leaf? t1)(if(null? l)
                       (list(leaf-val t1))
                       (cons(leaf-val t1)(decode t l)))]
         [(=(car l)0)(decode-h (bnode-ltree t1)(cdr l))]
         [(=(car l)1)(decode-h (bnode-rtree t1)(cdr l))]))
  (decode-h t l))

(define(lookup t)
  (if(leaf? t)
     (list (list(leaf-val t)))
     (list (map (λ(x)(append(list 0) x)) (lookup (bnode-ltree t)))
           (map (λ(x)(append(list 1) x)) (lookup (bnode-rtree t))))))

(define initial-list (list (cons 'H 1) (cons 'G 1)
                           (cons 'F 1) (cons 'E 1)
                           (cons 'D 1) (cons 'C 1)
                           (cons 'B 3) (cons 'A 9)))

(define (convert-initial-list l)
  (map (lambda (x) (cons (leaf (car x)) (cdr x))) l))


