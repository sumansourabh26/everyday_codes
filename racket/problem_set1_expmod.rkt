#lang racket
(define (expmod x y n)
  (if(= y 0) 1
     (modulo(* (sqr(expmod x (quotient y 2) n)) (if(odd? y) x 1)) n)))