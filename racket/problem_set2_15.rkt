#lang racket

(define(feverytwo l1 l2)
  (if(null? l1) '()
     (append (map (λ(t)(cons (car l1)t))l2)(feverytwo (cdr l1)l2))))


(define(cprod l)
  (foldr(λ(x y)
          (feverytwo x y))
        '(())
        l))
