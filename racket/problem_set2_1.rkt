#lang racket
;...........................1.1
(define(f0 start end)
  (if(> start end)0
     (+ (if(=(remainder start 13)0)
           start
           0)
        (f0 (+ start 1) end))))


;method 2

(define(f0- start end)
  (let((q1 (quotient end 13))
       (q2 (quotient start 13)))
    (* 13(-(f0-h q1)(f0-h q2)))))

(define(f0-h n)
  (/ (* n (+ n 1))2))

;............................1.2
(define(f1 a b)
  (if(> a b) 0
     (+(if(even? a) 0 (* a a))
       (f1 (+ a 1) b))))

;...........................1.3

(define(f2 a b)
  (if(> a b) 1
     (*(if(=(remainder a 3)0)(fact a) 1)
       (f2 (+ a 1) b))))

(define (fact n)
  (fact-h n 1))
(define(fact-h n pro)
  (if(= n 1) pro
     (fact-h (- n 1)(* n pro))))
;...........................1.4

(define(f3 a b)
  (if(> a b) 0
     (+(if(prime? a 2) (* a a) 0)
       (f3 (+ a 2) b))))
(define(prime? n r)
  (cond[(> r (sqrt n)) #t]
       [(=(remainder n r)0) #f]
       [else (prime? n (+ r 1))]))
;...........................1.5
(define(filter-accumulate bool-cond op ll ul id)
  (if(> ll ul) id
     (if(bool-cond ll)(op ll (filter-accumulate bool-cond op (+ ll 1) ul id))
        (filter-accumulate bool-cond op (+ ll 1) ul id))))

(define(f1- ll ul)
  (filter-accumulate(λ(x)(not(even? x))) 
                    (λ(x y)(+(sqr x) y))
                    ll ul 0))

(define(f2- l1 l2)
  (filter-accumulate(λ(x)(=(remainder x 3)0))
                    (λ(x y)(*(fact x) y))
                    l1 l2 1))

