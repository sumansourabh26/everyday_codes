#lang racket
(define (phi n)
  (phil n 1 0))

(define (phil n counter total)
  (if ( > n counter)(if (=(gcd n counter) 1) (phil n (+ counter 1)(+ total 1))
                        (phil n (+ counter 1) total))
      total))