#lang racket
(define(rotate-pi/2 curve)
  (λ(t)(make-point (* -1 (y-of (curve t)))(x-of (curve t))))) 