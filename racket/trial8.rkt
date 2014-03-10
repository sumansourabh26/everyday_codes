#lang racket
(define(sum l)
  (foldr + 0 l))

(define(list-upto n)
  (if (= n 1) (list n)
      (cons n (list-upto (- n 1)))))

(define(prime? a)
  (define(prime?h r)
    (if(> r (sqrt a)) #t
       (if(=(remainder a r)0) #f
          (prime?h (+ r 1)))))
  (prime?h 2))


(define(prime n)
  (define(prime-h r now)
    (if(= r n) (- now 1)
       (if(prime? now)(prime-h (+ r 1)(+ now 1))
          (prime-h r(+ now 1)))))
  (prime-h 0 2))

(define(digits-of n)
  (if(= n 0) '()
     (cons (remainder n 10)(digits-of (quotient n 10)))))


(define(factorial n)
  (if (= n 1) 1
      (* n (factorial(- n 1)))))