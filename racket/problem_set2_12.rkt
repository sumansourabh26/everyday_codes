#lang racket
(define (shuffle l1 l2)
  (let((combination (append l1 l2)))
    (foldr(λ(x y) (insert-everywhere x y)) '(()) combination)))

(define(insert-everywhere2 r l)
  (foldr(λ(x y)(if(null?(car y))(list(list r)(list x))
                  (cons(append(list r x)(cdr(car y))) (map(λ(t)(cons x t))y))))
        '(())
        l))