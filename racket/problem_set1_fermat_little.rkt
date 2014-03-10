#lang racket

(define (expmod x y n)
  (if(= y 1)
     (modulo x n)
     (modulo(* (sqr(expmod x (quotient y 2) n)) (if(odd? y) x 1)) n)))

(define(is-prime n)
  (is-prime-h n 0))

(define(is-prime-h n counter)
  (define a (random 1000))
  (if (= counter 200) #t
     
      (if(=(expmod a n n) (modulo a n))
         (is-prime-h n (+ 1 counter))
         #f))) 