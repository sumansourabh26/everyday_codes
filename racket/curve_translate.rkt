#lang racket
(define((translate a b) curve)
  (λ(t)(make-point (+ a (x-of (curve t))) (+ b (y-of (curve t))))))