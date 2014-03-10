#lang racket
(define (triangle n)
  (if(= n 1) 1
     (+(triangle (- n 1))(add2 n)(add (- n 1)))))

(define (add n)
  (if (> n 0) (+  n (add(- n 2))) 0))
(define (add2 n)
  (if (> n 0) (+ n (add2(- n 1))) 0)) 