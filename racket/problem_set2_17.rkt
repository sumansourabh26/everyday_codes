#lang racket
(define(power l)
  (foldr(λ(x y)
          (append (map (λ(t)(cons x t)) y) y))
        '(())
        l))

(define(lcs l1 l2)
  (define(largest-same l1 l2)
     (foldr(λ(x y)
          (foldr(λ(a b)
                  (if(and(equal? x a )(>(length x)(length b)))x b)) y
                     l2))
          '()
          l1))
  (largest-same(power l1)(power l2)))
                       