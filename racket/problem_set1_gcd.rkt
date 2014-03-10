#lang racket
(define (find a b)
  (let* ([g (gcd a b)])
  (if (= a g) 
      (cons 1 0)
      (cons (cdr (find b (modulo a b))) 
            (- (car (find b (modulo a b))) (* (cdr (find b (modulo a b))) (quotient a b))))))) 