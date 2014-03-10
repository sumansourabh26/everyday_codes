#lang racket
(define(circle r)
  (λ(t)(make-point (* r (cos(* pi t))) (* r (sin(*  pi t))))))