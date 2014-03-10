#lang racket
(define (concat l) (foldr append `() l))

(define-syntax lc
  (syntax-rules (: <- @)
    [(lc exp : var <- lexp) (map (lambda (var) exp) lexp)]
    [(lc exp : @ guard) (if guard (list exp) `())]
    [(lc exp : @ guard qualifier ...) 
     (concat (lc (lc exp : qualifier ...) : guard))]
    [(lc exp : var <- lexp qualifier ...) 
     (concat (lc (lc exp :  qualifier ... ) : var <- lexp))]))

(define (perm l)
  ( foldr (λ(x y)
            (foldr (a b)
                   (cons (foldr(λ(c d)
                                 () 
                                 '(())
                                 a)
                   '(())
                   y)