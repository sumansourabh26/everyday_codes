#lang racket

(define(empty-mat n)
  (if(= n 1) '(())
     (cons '()(empty-mat(- n 1)))))
(define(transpose m)
  (let((size (length (car m))))
    (foldr(λ(x y)(map cons x y)) (empty-mat size )  m)))

(define(extract a b l)
  (cond[(and(not(= b 1)) (= a 1))(cons (car l)(extract a (- b 1) (cdr l)))]
       [(and(> a 1)(> b 1))(extract (- a 1)(- b 1) (cdr l))]
       [(= b 1) (list(car l))]))

(define(rowcheck? l)
  (foldr(λ(x y)
          (and(and(= 45(foldr + 0 x))(= 362880(foldr * 1 x)))
              y))
        #t
        l))

(define(sudoku l)
  (and[rowcheck? l]
      [rowcheck? (transpose l)]
      [