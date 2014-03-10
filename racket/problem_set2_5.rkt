#lang racket
(define(empty-mat n)
  (if(= n 1) '(())
     (cons '()(empty-mat(- n 1)))))

(define(transpose m)
  (let((size (length (car m))))
    (foldr(λ(x y)(map cons x y)) (empty-mat size )  m)))

(define(product x y)
  (if(null? x) 0
     (+(*(car x)(car y))(product (cdr x)(cdr y)))))


(define(matmult m1 m2)
  (let((m2- (transpose m2)))
    (foldr(λ(x y)
            (cons (map (λ(t)(product x t )) m2-) y)) '() m1)))
