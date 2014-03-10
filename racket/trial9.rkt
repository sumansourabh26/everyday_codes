#lang racket

(define (make-account balance)
  (define (withdraw amount)
    (if (>= balance amount)
        (begin (set! balance (- balance amount))
               balance)
        "Insufficient funds"))
  (define (deposit amount)
    (set! balance (+ balance amount))
    balance)
  (define (dispatch m)
    (cond ((eq? m 'withdraw) withdraw)
          ((eq? m 'deposit) deposit)
          (else (error "Unknown request -- MAKE-ACCOUNT"
                       ))))
  dispatch)

(define(make-accumulator sum)
  (λ(x)
    (begin (set! sum (+ sum x))
           sum)))

(define(make-monitored f)
  (define count 0)
  (define (call?)
    count)
  (define (reset-count)
    (begin(set! count 0)
          "its 0"))
  (define (func lst)
    (begin(set! count (+ count 1))
          (apply f lst)))
  (define (dispatch . m)
    (cond ((eq? (car m) 'how-many-calls) (call?))
          ((eq? (car m) 'reset-count) (reset-count))
          (else (func m)
                )))
  dispatch)