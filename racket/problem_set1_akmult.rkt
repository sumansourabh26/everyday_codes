#lang racket
(define (akmult_ x y)
  (cond [(or(= x 0)(= y 0)) 0]
        [(= x 1) y]
        [else (* 2 (+(akmult_ (quotient x 2) y) (*(remainder x 2) (/ y 2))))]))