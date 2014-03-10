#lang racket
(define (rle l)
  (foldr (λ(x y)
           (cond [(null? (car y))(list(list x 1))]
                 [(= x (caar y))
                  (cons (list x(+(cadar y)1)) (cdr y))]
                 [else (cons(list x 1) y)])) '(()) l))

(define (list-range min max)
  (if (= min max) (list min)
      (cons min (list-range (+ min 1 ) max))))
(define (where-small f a b)
  (let ((value-list (map (λ(x)(cons(f x) x) )(list-range a b))))
    (cdar(sort value-list (λ(x y)(< (car x)(car y)))))))

(define(make-monitered f)
  (define count 0)
  (λ x 
    (cond[(equal? (car x) 'how-many-calls)count]
         ((equal? (car x) 'reset-count) (set! count 0))
         [else(begin(display(apply f x))
                    (set! count (+ count 1)))])))

(define(gc r)
  (cond[(= r 1)(list (list 0)(list 1))]
       [else(let ((last (gc (- r 1))))
              (append (map (λ(x)(cons 1 x))last) (map (λ(x)(cons 0 x))last)))]))

(define(summand n)
  (define(helper i)
    (if(= i n) (map(λ(x)(cons i x))(summand 0))
       (append (map(λ(x)(cons i x))(summand (- n i)))(helper (+ 1 i)))))
  (if (= n 0)'(())
      (helper 1)))

(define(choose n r)
  (define my-list (cdr(build-list (+ n 1) (λ(x)x))))
  (define(helper l s)
    (cond[(<(length l)s) '()]
         [(= s 0)'(())]
         [else(append (map  (λ(x)(cons (car l) x)) (helper (cdr l)(- s 1)))
                      (helper (cdr l) s))]))
  (helper my-list r))

(struct dir (info fdlist) #:transparent)
(struct file(info contents)#:transparent)
(define thistree
  (dir
   (cons "as" 1024)
   (list (dir
          (cons "cs613" 1024)
          (list (file (cons "quiz" 4246) "junk")
                (file (cons "tut" 7226) "junk")
                (dir (cons "2004" 1024)
                     (list (file (cons "quiz" 576) "junk")
                           (file (cons "tut" 345) "junk")))))
         (dir (cons "cs152" 1024)
              (list (file (cons "quiz1" 4532) "junk")
                    (file (cons "quiz2" 1234) "junk")
                    (file (cons "tut" 1223) "junk")))
         (dir (cons "cs154" 1024)
              (list (file (cons "tut1" 459) "junk")
                    (file (cons "tut2" 782) "junk"))))))
(define(findtree path tree)
  (cond[(=(length path)1) tree]
       ; [((=(length path)2) ]
       [else(findtree (cdr path)
                      (car(filter (λ(x)(or (if (dir? x) (λ(x) (equal?(cadr path)(car(dir-info x))))
                                            #f)
                                           (if(file? x) (λ(x)(equal? (cadr path)(car(file-info x))))
                                              #f)
                                           #f))
                                  (dir-fdlist tree))))]))

(struct node (ltree rtree) #:transparent)
(struct leaf (val) #:transparent)
(define (to-bintree l)
  (cond[(andmap(λ(x)(= x 1)) l) (leaf 1)]
       [(andmap(λ(x)(= x 0)) l) (leaf 0)]
       [else(let* ((size (/(length l)2)))
              (node(to-bintree (take l size))
                   (to-bintree (drop l size))))]))
(define t1 (to-bintree (list 1 1 1 0 0 0 0 1)))
(define t2 (to-bintree (list 0 1 1 1 0 1 0 0 )))
(define (bitwise-or t1 t2)
  (cond[(and(leaf? t1)(leaf? t2)) (cond[(>(+(leaf-val t1)(leaf-val t2))0) (leaf 1)]
                                       [else (leaf 0)])]
       [(leaf? t1) (cond[(= (leaf-val t1)1)(leaf 1)]
                        [(node? t2)(node (bitwise-or t1 (node-ltree t2))
                                         (bitwise-or t1 (node-rtree t2)))])]
       [(leaf? t2) (cond[(= (leaf-val t2)1) (leaf 1)]
                        [(node? t1)(node (bitwise-or t2 (node-ltree t1))
                                         (bitwise-or t2 (node-rtree t1)))])]
       [else(node(bitwise-or(node-ltree t1)(node-ltree t2))
                 (bitwise-or(node-rtree t1)(node-rtree t2)))]))

(define(value? length index t)
  (cond[(leaf? t)(leaf-val t)]
       [(> index (/ length 2))(value? (/ length 2) (- index (/ length 2)) (node-rtree t))]
       [(<= index (/ length 2))(value? (/ length 2) index (node-ltree t))]))

