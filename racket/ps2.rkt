#lang racket

;;;;;;;;;powerset;;;;;;;;;

(define (powerset l)
  (foldr(λ(x y)
          (append y 
                  (map (λ(t) (cons x t))
                       y)))
        '(())
        l))

;(define (vec-powerset l)
;  (define size (length l))
;  (define table (make-vector (+ 1 size) #f))
;  (vector-set! table size '())
;  (define (power l)
;    (cond [(vector-ref size table)(vector-ref size table)]
;          [(begin (set! 

;;;;;;;;inits;;;;;;;;;;;;;

(define(inits l)
  (foldr(λ(x y)
          (cons '() (map (λ(t) (cons x t))
                         y)))
        '(())
        l))

;;;;;;;;matrices;;;;;;;;;;
(define (transpose l)
  (foldr (λ(x y)
           (map(λ(a b)(cons a b)) x y))
         (make-list (length (car l)) '())
         l))
(define (mult l1 l2)
  (define new-l2 (transpose l2))
  (foldr (λ(x y)
           (cons (foldr (λ( a b)(cons (apply + (map (λ( u v)(* u v)) x a)) b)) '() new-l2)
                 y))
         '()
         l1))
;;;;;;;
