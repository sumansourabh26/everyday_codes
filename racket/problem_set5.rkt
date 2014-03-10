#lang racket

(define(foldr f base l)
  (if (null? l) base
      (f (car l) (foldr f base(cdr l)))))

(define(init l)
  (foldr(λ(x y)
          (cons '() (map (λ(t)(cons x t)) y))) '(()) l))

(define(tail l)
  (foldr(λ(x y)(append (list x) (car y))) '(()) l))
          