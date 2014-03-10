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
(struct node (ltree rtree) #:transparent)
(struct leaf () #:transparent)

(define ex (node (node (leaf) (node (leaf) (leaf))) (leaf)))
(define ex1 (node (leaf) (node (leaf) (leaf))))

(define(list-upto n)
  (if (= n 0) '(0)
      (cons n (list-upto (- n 1)))))

(define (all-tree b)
  (cond[(= b 0) (list(leaf))]
       [else(concat(lc(lc(node x y) : x <- (all-tree t) y <- (all-tree (- b (+ 1 t)))) : t <- (list-upto (- b 1))))]))

(define(reflect t)
  (cond[(leaf? t) t ]
       [else(node (reflect(node-rtree t))(reflect(node-ltree t)))])) 

(define(all-sym-tree n)
  (lc (node t (reflect t)) : t <- (all-tree (/ (- n 1) 2))))
