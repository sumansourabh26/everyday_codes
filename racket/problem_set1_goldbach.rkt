#lang racket

(define (check_prime n)
  (check1 n 2 1))

(define (check1 a b c)
  (cond((= c 0) #f)
       ((= b (- a 1)) #t)
       (else (check1 a (+ b 1) (remainder a b)))))

(define (goldbach a)
  (goldbach1 a 2))

(define(goldbach1 a b)
  (if (and (check_prime b) (check_prime (- a b)))
      (cons b (- a b))
      (goldbach1 a (+ b 1))))