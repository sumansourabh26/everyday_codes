#lang racket
(define len 8)
(struct node (ltree rtree) #:transparent)
(struct leaf (val) #:transparent)



(define(half l)
  (let((lr (/(length l)2)))
    (define(half-h r l)
      (if(> r lr)'()
         (cons (car l)(half-h (+ r 1)(cdr l)))))
    (half-h 1 l)))

(define(allsame? l)
  (cond[(null? (cdr l))#t]
       [(=(car l)(car(cdr l))) (allsame? (cdr l))]
       [else #f]))

(define(tobintree l)
  (cond[(null? (cdr l))(leaf (car l))]
       [(allsame? l)(if(=(car l)1)
                       (leaf 1)
                       (leaf 0))]
       [else (node(tobintree (half l))
                  (tobintree (reverse(half(reverse l)))))]))
;;;;;;;;;;;;;;;;Q2
(define(optimise t)
  (if(and(leaf? (node-rtree t))
         (leaf? (node-ltree t))
         (=(leaf-val (node-rtree t))
           (leaf-val(node-ltree t))))
     (leaf(leaf-val(node-ltree t)))
     t))
(define(bitwise-or t1 t2)
  (cond[(leaf? t2)(if(=(leaf-val t2)1) (leaf 1) t1)]
       [(leaf? t1)(if(=(leaf-val t1)1) (leaf 1) t2)]
       [else (optimise(node(bitwise-or(node-ltree t1)
                                      (node-ltree t2))
                           (bitwise-or(node-rtree t1)
                                      (node-rtree t2))))]))
(define(bitwise-and t1 t2)
  (cond[(leaf? t2)(if(=(leaf-val t2)0) (leaf 0) t1)]
       [(leaf? t1)(if(=(leaf-val t1)0) (leaf 0) t2)]
       [else (optimise(node(bitwise-and(node-ltree t1)
                                       (node-ltree t2))
                           (bitwise-and(node-rtree t1)
                                       (node-rtree t2))))]))
(define(value? i bt)
  (define(value-h i l t)
    (cond[(leaf? t)(leaf-val t)]
         [(> i  (/ l 2))(value-h (- i (/ l 2)) (/ l 2)(node-rtree t))]
         [(<= i (/ l 2))(value-h i (/ l 2)(node-ltree t))]))
  (value-h i 8 bt))


