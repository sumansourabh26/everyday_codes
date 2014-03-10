#lang racket
(require racket/mpair)

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;QUESTION 1;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(define (im->m l)
  (if(null? l)(mlist)
     (mappend (mlist (car l))
              (im->m (cdr l)))))

(define storable%
  (class object%
    (super-new)
    (define/public (read)(error"should be overridden"))
    (define/public (write)(error"should be overridden"))
    (define/public (print)(error"should be overridden"))))


(define register-bank%
  (class storable%
    
    (init l)
    (init-field (registers l))
    (super-new)
    
    (define/override(read r)
      (mcdr (massoc r registers)))
    (define/override(write r val)
      (set-mcdr! (massoc r registers) val))
    (define/override(print)
      (display registers))))

(define memory%
  (class storable%
    (init m)
    (init-field (memory m))
    (super-new)
    
    (define/override (read n)
      (vector-ref memory n))
    (define/override (write n value)
      (vector-set! memory n value))
    (define/override (print)
      (display memory))))

(define processor% 
  (class object% 
    (init mem-size)
    (init reg-names)
    (init inst-set)
    (init-field (memory-size mem-size ))
    (init-field (register-name (im->m reg-names )))
    (init-field (instructions inst-set ))
    (super-new)
    (define register (make-object register-bank% (mmap(λ(x)(mcons x 0))register-name)))
    (define memory (make-object memory% (make-vector memory-size 0)))
    
    (define/public(execute prog)
      (if(null? prog ) "done"
         (begin(let((single-program (car prog)))
                 (cond[(eq?(car single-program)'load)
                       (send register write (second single-program)(third single-program))]
                      [(eq?(car single-program)'store)
                       (send memory write (second single-program)
                             (send register read (third single-program)))]
                      [else (send register write (cadr single-program)
                                  (apply (cadr(assoc (car single-program) instructions))
                                         (map(λ(x)(send register read x))(cdr single-program))))]))
               
               
               (display "Memory")(newline)
               (send memory print)(newline)
               (display "registers")(newline)
               (send register print)
               (newline)
               (execute (cdr prog)))))))

(define as2013
  (new processor%
       [mem-size 32]
       [reg-names (list 'r1 'r2 'r3 'r4)]
       [inst-set (list (list 'add (λ(x y z)(+ x y z)))
                       (list 'mul (λ(x y)(* x y)))
                       (list 'incr (λ(x)(+ x 1))))]))

;:::::::::::::::::::::::::::::::::::::::::::::::::QUESTION 2:::::::::::::::::::::::::::::::::::::::::::


(define account%
  (class object%
    (init passwd)
    (init balance)
    (init interest-rate)
    ;(init holder)
    (define password passwd)
    ;(init-field (accholder holder))    
    (define bal balance)
    (init-field (rate interest-rate))
    (define dues 0)
    
    (send this-timer take-account (λ()(pay-interest)))
    
    (define/public (deposit amount)
      (if(> amount 0)
         (set! bal (+ bal amount))
         "go home...you are drunk"))
    
    
    (define/public (withdraw amount passwd)
      (if(eq? passwd password)
         (if(< bal amount) "not enough balance" (set! bal (- bal amount)))
         "incorrect password"))
    
    (define/public (show passwd) (if(eq? passwd password)(begin(display bal)(newline))
                                    "incorrect password"))
    
    (define (pay-interest) (set! bal (* (+ 1 rate)bal)))
    
    (define/public (clear-outstanding)
      (if(>= bal dues)(begin (set! bal (- bal dues))
                             (set! dues 0))
         (begin (set! dues (- dues bal))
                (set! bal 0))))
    
    (define/public (interest-due) (set! dues (* 1.2 dues)))
    
    (define/public (make-purchase amount) (set! dues (+ dues amount)))
    
    (define/public (check-passwd passwd) (eq? passwd password))
    (super-new)))

(define joint-account%
  (class object%
    (init account)
    (init passwd)
    (init new-passwd)
    (super-new)
    
    (cond[(not(send account check-passwd passwd))  "incorrect password"])
    
    (init-field (parent account))
    (define new-password new-passwd)
    (define old-password passwd)
    
    (define/public (withdraw amount passwd)
      (if (eq? passwd new-password)
          (send parent withdraw amount old-password)
          "wrong password"))
    
    (define/public (deposit amount passwd)
      (if (eq? passwd new-password)
          (send parent deposit amount old-password)
          "wrong password"))))


(define credit-card%
  (class object%
    (init acct)
    (init passwd)
    (super-new)
    (cond[(not(send acct check-passwd passwd))  "incorrect password"])
    
    (init-field (parent acct))
    (define password passwd)
    
    (send this-timer take-card this)
    (define/public (make-purchase amount)
      (send parent make-purchase amount))
    
    (define/public (clear-outstanding-amount)
      (send parent clear-outstanding))
    
    (define/public (interest-due)
      (send parent interest-due))
    ))

(define (map1 pro l)
  (cond [(not(null? l)) (begin (pro (car l))
                               (map1 pro (cdr l)))]))

(define timer%
  (class object% 
    (init accounts)
    (init cards)
    (init-field (interests-list accounts))
    (init-field (card-list cards))
    (super-new)
    (define timer-password "personal")
    
    (define/public (take-account interests)
      (set! interests-list (cons interests interests-list)))
    (define/public (take-card card)
      (set! card-list (cons card card-list)))
    
    (define/public (process-accounts-tick)
      (map1 (λ(x)(x)) interests-list))
    
    (define/public (process-credit-card-tick)
      (map1 (λ(x)(send x interest-due )) card-list))))
(define this-timer (new timer% (accounts '()) (cards '())))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;COMPLETE;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;





