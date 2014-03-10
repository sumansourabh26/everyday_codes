#lang racket
(define(mem-fib range)
  (define fib-vec 
    (make-vector range #f))
  (define(init)
    (begin
      (vector-set! fib-vec 0 0)
      (vector-set! fib-vec 1 1)))
  (define(fib n)
    (cond [(vector-ref fib-vec n)(vector-ref fib-vec n)]
          [else(begin(vector-set! fib-vec n (+(fib (- n 1))(fib (- n 2))))
                     (vector-ref fib-vec n))]))
  (init)
  fib)

(define(make-2d-vector r c)
  (build-vector r (λ(x)(make-vector c #f))))
(define(2d-vector-ref vec r c)
  (vector-ref (vector-ref vec r) c))
(define(2d-vector-set! vec r c val)
  (vector-set! (vector-ref vec r) c val))

(define(memo-lcs l1 l2)
  (define table (make-2d-vector (length l1)(length l2)))
  (define(h l1 l2)
    (let*((n1 (- (length l1)1))
          (n2 (- (length l2)1)))
      (cond[(or(null? l1)(null? l2)) '()]
           [(2d-vector-ref table n1 n2)(2d-vector-ref table n1 n2)]
           [else(let* ([value (cond[(=(car l1)(car l2)) (cons (car l1)(h (cdr l1)(cdr l2)))]
                                  [else (let* ([res1 (h l1 (cdr l2))]
                                               [res2 (h (cdr l1) l2)])
                                          (if( >= (length res1)(length res2)) res1 res2))])])
                  (begin(2d-vector-set! table n1 n2 value)
                        value))])))
  (h l1 l2))