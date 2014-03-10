#lang racket

(define-syntax for 
  (syntax-rules ( : )
    [(for init : bexp : change : statements)
     (begin
       init
       (define(loop)
         (cond[bexp (begin
                      statements
                      change
                      (loop))]))
       (loop))]))

(define-syntax while
  (syntax-rules ( : )
    [ (while bexp : statements)
      (begin
        (define(loop)
          (cond[bexp statements
                     (loop)]))
        (loop))]))

(for (begin 
       (define sum 0)
       (define i 0)) :
  (<= i 10) :
  (set! i (+ i 1)) :
  (set! sum (+ sum i)))

(define-syntax m-or 
  (syntax-rules (  )
    [(m-or arg) arg]
    [(m-or arg  rest ...)(or arg (m-or rest ...))]))

(define (sieve n)
  (define vec (make-vector (+ n 1) #t))
  
  (begin  (for (begin
                 (define i 2)
                 (define j 2))
            : (<= i n)                   ;cpu time: 32766 real time: 33282 gc time: 4112
            : (set! i (+ i 1))
            : (for (set! j (* 2 i))
                :  (<= j n)
                :  (set! j (+ j i))
                :  (vector-set! vec (- j 1) #f)))
          (for (set! i 2) 
            :  (< i n)
            :  (set! i (+ i 1))
            :  (cond[(vector-ref vec i) (begin (display (+ i 1))
                                               (newline))]))))

(define (prime? n)
  (define a 2)
  (define(prime?h n)
    (if(<= a (sqrt n))
       (cond[(=(remainder n a)0) #f]
            [else(begin (set! a (+ a 1))
                        (prime?h n))])
       #t))
  (prime?h n))

(define(prime-l n)
  (define b 2)
  (for(set! b 2)
    : (<= b n )
    : (set! b (+ b 1))
    : (cond[(prime? b) (begin (display b)
                              (newline)) ]
           [else ""])))