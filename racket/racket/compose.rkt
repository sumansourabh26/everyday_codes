#lang racket
(define (compose f g)
(lambda (x)
(f (g x))))
(define (thrice f)
(compose (compose f f) f))
(define (identity x) x)
(define (repeated f n)
(if (= n 0)
identity
(compose f (repeated f (- n 1)))))
(define (add1 x)
  (+ x 1))