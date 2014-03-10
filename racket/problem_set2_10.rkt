#lang racket
(define (gc n)
  (if(= n 1) '((0)(1))
     (append(map(λ(x)(append x (list 1) )) (gc(- n 1)))
            (map(λ(x)(append x (list 0) )) (gc(- n 1)))
            )))