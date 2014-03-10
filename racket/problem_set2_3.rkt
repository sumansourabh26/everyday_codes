#lang racket
(define(power l)
  (foldr(λ(x y)
          (append (map (λ(t)(cons x t)) y) y))
        '(())
        l))

