#lang racket
(define(transpose l)
  (if(null? (car l))'()
     (append (list(foldr(λ(x y)
                          (cons (car x) y))
                        '() l))
             (transpose (map(λ(x)(cdr x))l)))))

(define(mult l1 l2)
  (if(null? l1) 0
     (+ (*(car l1)(car l2))(mult(cdr l1)(cdr l2)))))

(define(matmult a b)
  (define(h l1 l2)
    (foldr(λ(x y)
            (append 
             (list(foldr(λ(x1 y1)
                          (cons (mult x1 x) y1))
                        '() l2))
             y))
          '() l1))
  (h a (transpose b)))

(define(flatten l)
  (map(λ(x)(if(list? x) (flatten x)
              x))l))