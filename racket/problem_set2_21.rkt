#lang racket
(define(sum-max l)
  (cdr(foldr(λ(x y)
          (cons (max x (+(car y)x)) (max x (+(car y)x) (cdr y))))
            (cons 0 0)
            l))) 