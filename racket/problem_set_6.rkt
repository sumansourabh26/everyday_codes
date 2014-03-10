#lang racket

(define(foldr f base l)
  (if (null? l) base
      (f (car l) (foldr f base(cdr l)))))

(define(point r l)
  (cond((null? l) 0)
       ((= r 1) (car l))
       ((point (- r 1)(cdr l)))))

(define(evaluate x l)
  (evaluateh x (reverse l)))
(define(evaluateh x l)
  (let((size (-(length l)1)))
    (if (= size -1) 0
        (+(* (car l) (expt x size))(evaluateh x (cdr l))))))

(define(add poly1 poly2)
  (if (null? poly1) '()
      (cons (+ (car poly1)(car poly2))(add (cdr poly1)(cdr poly2)))))

(define(split n)
  (define (split-h l)
    (if(> l n)'()
       (cons (list l (- n l))(split-h (+ l 1)))))
  (split-h 0))

(define(horner x coffs)
  (foldr (λ(y z)(+ y (* x z))) 0 coffs))

(define(power n poly1 poly2)
  (define(power-h coff- p1 p2)
    (if(null? coff-) 0
       (if(or(null? p1)(null? p2)) 0
          (+ (* (point(+ (car(car coff-)) 1 )p1) (point ( + ( point 2 ( car coff-) ) 1 ) p2))
             (power-h (cdr coff-)  p1  p2)))))
  (power-h (split n) poly1 poly2))

(define(multiply p1 p2)
  (let((degree (+(length p1)(length p2)(- 2)))) 
    (define(multiply-h n p1 p2)
      (if (> n degree)'()
          (cons(power n p1 p2)(multiply-h (+ n 1) p1 p2))))
    (multiply-h 0 p1 p2)))
           
           
           