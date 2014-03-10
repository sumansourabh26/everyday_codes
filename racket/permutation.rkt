#lang racket
(define(insert-everywhere r l)
  (foldr(λ(x y)(if(null?(car y)) (list(list r x)(list x r))
                  (cons(append(list r x)(cdr(car y))) (map(λ(t)(cons x t))y))))
        '(())
        l))

(define(perm l)
  (foldr(λ(x y)
          (if(null?(car y)) (list(list x))
             (car(map(λ(t)(insert-everywhere x t))y))))
        '(())
        l))