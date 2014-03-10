#lang racket
(define (expmod x y n)
  (if(= y 0) 1
     (modulo(* (sqr(expmod x (quotient y 2) n)) (if(odd? y) x 1)) n)))

(define (find a b)
  (let* ([g (gcd a b)])
    (if (= a g) 
        (cons 1 0)
        (cons (cdr (find b (modulo a b))) 
              (- (car (find b (modulo a b))) (* (cdr (find b (modulo a b))) (quotient a b))))))) 


(define(decode p q e c)
  (let*((n (* p q))
        (phi (*(- p 1)(- q 1)))
        (d (if (> e phi) (car (find e phi))
               (car (find phi e)))))
    (expmod c d n)))
  