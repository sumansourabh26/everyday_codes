#lang racket
(struct gnode (val lst) #:transparent)
(define a (gnode 1 (list(gnode 2 (list (gnode 3 (list (gnode 5 '())
                                                      (gnode 6 '())))
                                       (gnode 4 '())))
                        (gnode 7 '())
                        (gnode 8 (list (gnode 9 '())
                                       (gnode 10 '()))))))

(define (concat l) (foldr append `() l))

(define(atlevel t n)
  (cond[(= n 1)(list(gnode-val t))]
       [else(concat (map(λ(x) (atlevel x (- n 1)))(gnode-lst t)))]))
                               