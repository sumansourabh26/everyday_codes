#lang racket
(define (make-account balance passwd)
  (define (withdraw amount)
    (if (>= balance amount)
        (begin (set! balance (- balance amount))
               balance)
        "Insufficient funds"))
  (define (deposit amount)
    (set! balance (+ balance amount))
    balance)
  (define (make-joint newpass)
    (set! pass newpass))
  (define (show)(deposit 0))
  (define (dispatch m pw)
    (cond [(eq? pw pass)
           (cond[(eq? m 'make-joint) make-joint]
                [(eq? m 'withdraw) withdraw]
                [(eq? m 'deposit) deposit]
                [(eq? m 'show) (show)]
                [else (error "Unknown request -- MAKE-ACCOUNT"
                             )])]
          [else (error "wrong password")]))
  (define pass 0)
  (begin (set! pass passwd)
         dispatch))

(define(make-joint account newpass oldpass)
  ((account 'make-joint oldpass)newpass))

;;;;;;;;;;;;make-monitered f Q6
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
;;;;;;;Q1
(define state1 (cons 0 #f))
(define(to-decimal lst)
  (define (to-decimal-h l)
    (cond[(null? l)(car state1)]
         [else (let ((a (car l))
                     (b (cdr l)))
                 (cond[(= a -2) (begin (set! state1 (cons(car state1) 1))
                                       (to-decimal-h b))]
                      [(not(cdr state1))(begin (set! state1 (cons(+(* (car state1)10)a) #f))
                                               (to-decimal-h b))]
                      [else        (begin (set! state1 (cons(+(car state1)(/ a (expt 10 (cdr state1))))
                                                            (+ 1 (cdr state1))))
                                          (to-decimal-h b))]
                      ))]))
  (to-decimal-h (map (λ(x)(-(char->integer x)48)) lst)))
;;;;;;;;;Q2
(define state2 (list 0 0 0))
(define (system )
  (let ((a (read)))
    (begin (set! state2 (list (second state2)(third state2) a))
           (display (+ (first state2)(second state2)(third state2)))
           (newline)
           (system))))

;;;;;;;;;Q6

(define state3 1)
(define (f x)
  (cond [(= state3 2) (begin (set! state3 1)
                             0)]
        [(= x 0) (begin (set! state3 2)
                        0) ]
        [(= x 1) (begin (set! state3 2)
                        1)]))


