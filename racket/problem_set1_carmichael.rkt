#lang racket
(define (is-coprime a b)(=(gcd a b) 1))

(define (prime n)
   (prime-h n 2))
(define (prime-h n r)
      (cond((=(remainder n r) 0) #f )
             ((> r (sqrt n)) #t)
             ((not(=(remainder n r)0)) (prime-h n (+ r 1)))))

          
(define (expmod x y n)
  (if(= y 1)
     (modulo x n)
     (modulo(* (sqr(expmod x (quotient y 2) n)) (if(odd? y) x 1)) n)))

(define (carmichael n)
  (carmichael-h n 3 ))

(define (carmichael-hh a now )
  (cond((= now a) #t)
       ((is-coprime a now)(if(=(expmod now (- a  1) a) 1)
                             (carmichael-hh a (+ now 1))
                             #f))
       ((not(is-coprime a now)) (carmichael-hh a (+ now 1)))))

(define(carmichael-h n present)
  (if(= n 0) 
     (- present 1)
     (if(prime present)
        (carmichael-h n (+ present 1))
        (if(carmichael-hh present 2)
           (carmichael-h (- n 1) (+ present 1))
           (carmichael-h n (+ present 1))))))