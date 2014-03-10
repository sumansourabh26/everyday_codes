
#lang racket
(define(make-account balance)
  (define (withdraw amount)
    (let ((expected (- balance amount)))
      (if(>= expected 0)(begin(set! balance expected)
                              balance)
         "ghanta bhikhari")))
  (define(deposit x)
    (begin(set! balance (+ balance x))
          balance))
  (define (show)
    (withdraw 0))
  (define(dispatch m)
    (cond[(eq? m 'withdraw) withdraw ]
         [(eq? m 'deposit) deposit]
         [(eq? m 'show) (show)]
         [else (error "ache se de instruction")]))
  dispatch)

(define account%
  (class object%
    (init bal)
    (init holder)
    (init-field (accholder holder))    
    (init-field (balance bal))
    (define/public (withdraw amount)
      (if(> amount balance)("you have not enough balance for transaction")
         (begin (set! balance (- balance amount))
                balance)))
    (define/public (show-info) (begin(display accholder)(newline)(display balance)))
    (super-new)))
(define sec-account%
  (class account%
    (inherit-field balance)
    (inherit-field accholder)
    (super-new)
    (init passwd)
    (init-field (password passwd))
    (define/override (withdraw amount pw)
      (if(eq? pw password) (if(>= balance amount) 
                              (begin (set! balance (- balance amount))
                                     balance)
                              (error "jitni chadar hai utna hi per phalaya kar"))
         (error "password bhul gaya kya")))))


(define processor%
  (class object%
    (init mem-size)
    (init inst-set)
    (init reg-name)
    (init-field (size mem-size))
    (init-field (reg-list reg-name))
    (init-field (instructions inst-set))
    (define memory
    
    (define (load r val)
      (set! r val))
    (define (store m val)
      (set! (
    
    (define (do-it program)
      (cond [ (eq? (car program) 'load) (load (cadr program) val)]
            [ (eq? (car program) 'store)(store (cadr program) val)]
    
    ;(define(store 
    (define/public (execute prog)
      (if (null? prog) "Done"
          (begin (do-it (car prog))
                 
                 (execute (cdr prog)))))))

(define as2013
  (new processor% 
       [mem-size 32]
       [reg-name (list 'r1 'r2 'r3 'r4)]
       [inst-set (list (list 'add (λ(x y)(+ x y)))
                       (list 'mul (λ(x y)(* x y)))
                       (list 'incr (λ(x) (+ x 1))))])) 

