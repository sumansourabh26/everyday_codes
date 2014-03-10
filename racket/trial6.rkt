#lang racket
(define(eq? l1 l2)
  (if(= (length l1)(length l2))
     (cond [(null? l1) #t]
           [(=(car l1)(car l2)) (eq? (cdr l1)(cdr l2))]
           [(not(=(car l1)(car l2))) #f])
     #f))

(define(calculate f)
  
