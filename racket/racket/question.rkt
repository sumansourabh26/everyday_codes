#lang racket
;question 1
(define (equ a b c) 
  (cond ( (= (modulo c (gcad a b)) 0) #t) 
        ( else #f)))
(define (gcad a b)
  ( if (= 0 (modulo a b)) b ( gcad b (modulo a b))))
(define (eq a b c) 
  (if (> a b) (equ a b c ) (equ b a c)))
;question 2
(define (sub x y) 
  (sub-c x y 0))
(define (sub-c x y c)
   (let* (( a (remainder x 10))
       (b (remainder y 10))
       (sub-single (- a b c)))
  (if  (= y 0) (- x c)
      (if (< sub-single 0) (convert (sub-c (quotient x 10) (quotient y 10) 1) (+ sub-single 10))
          (convert (sub-c (quotient x 10) (quotient y 10) 0) sub-single)))))
(define (convert x y ) 
  (+ (* 10 x ) y))
;question 3
(define (ak-mult x y) 
  (if (= x 1) y
      (if (even x) (* 2 (ak-mult (quotient x 2) y))
          (+(* 2 (ak-mult (quotient x 2) y)) y ))))
;question 4
(define (div x y) 
  (if ( < x y) (cons 0 x)
      (let ((a  (* 2 (car (div (quotient x 2) y))))
            (b  (* 2 (cdr (div (quotient x 2) y)))))
       (if (even x) (if (< b y) (cons a b)
                        (cons (+ a 1) (- b y)))
           (if (< (+ b 1) y) (cons a ( + b 1)) 
               (cons (+ a 1) (-(+ b 1) y)))))))
;question 6
(define (modexp x y n)
  (cond ((= y 0) 1)
        (else 
   (if ( even y) 
      (remainder (* (modexp x (quotient y 2) n) 
                  (modexp x (quotient y 2) n))
               n)
      (remainder (* x
                  (modexp x (quotient y 2) n) 
                  (modexp x (quotient y 2) n))
               n)))))
                 
  (define (even x) 
    ( if (= (remainder x 2)0) 
         #t
         #f))
                 
                 