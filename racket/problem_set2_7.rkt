#lang racket

(define(foldr f base l)
  (if (null? l) base
      (f (car l) (foldr f base(cdr l)))))



(define(rle l)
  (foldr(λ(x y)
          (if(null? (car y))(list(list x 1))
             (if(= x (car(car y)))
                (cons (list x (+ 1 (car(cdr(car y))))) (cdr y))
                (cons (list x 1)y))))
          '(())
          l))
  