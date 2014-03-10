#lang racket

; (define size 100) defines a private field. This initializes the size
; field of all  objects to 100. Now the only way  of changing the size
; field is through a method.
 
; A  field  defined  through  a  define  can  be  given  a  per-object
; initialization through a init.

;     (init x)
;     (define size x) 

; A field  introduced a  define is  private in the  sense it  can't be
; accessed with a get-field or set with a set-field!

; (field [size 100]) defines a public field. This initializes the size
; field  of  all  objects  to  100.  It  can  be  given  a  per-object
; initialization through a init.

;     (init x)
;     (field [size x]) 

; A field introduced through a  field can be accessed with a get-field
; and set through a set-field!

; An init-field  can be given a  default initialization as  well as be
; given a per-object initialization during object creation. It defines
; a public field.

;;;;;;;;;Creation of a protected account without inheritence ;;;;;;;;;

;(define account% 
;  (class object% 
;    (init passwd)            ; passwd and bal will be initialised during object creation
;    (define password passwd) 
;    (init ach)
;    (init-field [account-holder ach])   ; This necessarily has to be a per-object initialization
;    (init bal)
;    (init-field [balance 0])
;    (init-field (balance 10000)) ; balance is public and password is private. 
                                 ; If instead of bal we had a constant, then 
                                 ; this would have meant a class initialization
;    (super-new)
;    (define/public (show) balance)
;    (define/public (withdraw amount)
;      (if (<= amount balance)
;          (begin
;            (set! balance (- balance amount))
;            balance)
;          "Insufficient funds"))
;    (define/public (deposit amount)
;      (begin
;        (set! balance (+ balance amount))
;        balance))
;    (display (show))))

;; (define my-account 
;;   (new account%
;;        [balance 0]
;;        [passwd "%&%^%&***"]
;;        [ach 'Vinayak])) ; initialize passwd, override the default value
		           ; of balance

;(get-field account-holder my-account)  
;(set-field! account-holder my-account `AS)  
;(send my-account show)
;(send my-account withdraw 100)

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(define account% 
  (class object% 
    (init-field account-holder)   
    (init-field balance)
    (super-new)
    (define/public (show) balance)
    (define/public (withdraw amount)
      (if (<= amount balance)
          (begin
            (set! balance (- balance amount))
            balance)
          "Insufficient funds"))
    (define/public (deposit amount)
      (begin
        (set! balance (+ balance amount))
        balance))))

(define my-account 
  (new account% 
       [account-holder 'AS] 
       [balance  10000]));  initialize  passwd, override  the  default
		         ; value of balance

(define protected-account%
  (class account% 
    (init passwd)
    (init acholder)
    (init bal)
    (define password passwd)
    (super-new [account-holder acholder] [balance bal])
    (display this)
    (define/override (withdraw amount passd)
      (cond[(string=? passd password) (super withdraw amount)]
           [else "Wrong Password"]))))

(define pa (make-object protected-account% "hfksdah" 'AS 10000))