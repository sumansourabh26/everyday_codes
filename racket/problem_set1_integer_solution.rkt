#lang racket
(define (gcd1 d e)
  (if (= (remainder d e) 0) e (gcd1 e (- d (*(quotient d e) e)))))

(define (has_solution a b c)
  (if (=(remainder c (gcd1 a b)) 0) #t #f ))
