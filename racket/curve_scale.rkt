#lang racket
(define((scale rx ry)curve)
  (λ(t)(make-point (* rx(x-of (curve t)))(* ry(y-of (curve t))))))