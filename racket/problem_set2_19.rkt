#lang racket
(define (concat l) (foldr append `() l))

(define(list-upto r)
  (if (= r 1)(list(list 1))
      (cons (list r) (list-upto (- r 1)))))

(define(choose n r)
  (let((list-upto-n n))
    (if(= r 1) list-upto-n
       (foldr(λ(x y)
               (append (map (λ(t)(cons x t ))(choose n (- r 1))) y))
             '(())
             list-upto-n))))
       