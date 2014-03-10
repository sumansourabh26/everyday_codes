#lang racket
(require racket/mpair)

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
    
    ;(define/public (pay-interest-timer passwd)(if(eq? passwd "personal")
    ;                                            (pay-interest)
    ;                                             "the execution of intersest is a matter of authority of bank, you are not allowed to make interest yourself"))
    
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
    (define/public (show pw)
      (if (eq? pw new-password)
          (send parent show old-password)
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

(define my-account (new account% (passwd "amitabha") 
                                 (balance 1000) 
                                 (interest-rate 0.05)))
(define my-card (new credit-card% (acct my-account) 
                                  (passwd "amitabha")))
(define another-account (new account% (passwd "abcd")
                                      (balance 5000) 
                                      (interest-rate 0.1)))
(define another-card (new credit-card% (acct another-account) 
                                       (passwd "abcd")))
(define jnt-account (new joint-account% (account my-account) 
                                        (passwd "amitabha") 
                                        (new-passwd "xyz")))
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;Direct withdrawals
(send my-account withdraw 200 "amitabha")
(send my-account show "amitabha")
(send jnt-account withdraw 200 "amitabha")
(send jnt-account show "xyz")
(send this-timer process-accounts-tick)
(send my-account show "amitabha")
(send another-account show "abcd")


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;Credit card transactions
(send my-card make-purchase 100)
(send this-timer process-credit-card-tick)
(send my-card clear-outstanding-amount)
(send my-account show "amitabha")

(send my-card make-purchase 50)
(send another-card make-purchase 1000)
(send another-card clear-outstanding-amount) 
(send this-timer process-credit-card-tick)
(send my-account show "amitabha")
(send my-card clear-outstanding-amount)
(send another-account show "abcd")
(send my-account show "amitabha")
