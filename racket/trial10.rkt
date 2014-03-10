#lang racket
(define x 1)
(define (f x)
  (define a 4)
  (define(g x)
  (+ a 100))
  (+ x (g 1)))
