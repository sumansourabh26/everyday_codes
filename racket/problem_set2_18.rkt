#lang racket

(define (concat l) (foldr append `() l))

(define(list-upto r)
  (if (= r 1)(list(list 1))
      (cons (list r) (list-upto (- r 1)))))

(define(perm n r)
  (define(permu n r)
    (let(( list-upto-n (list-upto n)))
      (if(= r 1)(list list-upto-n)
         (map(λ(x)
               (map(λ(t)(append x t))(perm n (- r 1)))) list-upto-n))))
  (concat(permu n r)))