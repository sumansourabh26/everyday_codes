#lang racket

; The point is that the state consists of a pair of things, the partial number
; and another which says whetherv we are before a decimal point or not


(define (char->number c)
  (- (char->integer c) 48))

(define state (cons #f 0))

(define (to-decimal l)
  (cond [(null? l) (cdr state)]
        [(char=? (car l) #\.) (begin
                                (set! state (cons 0 (cdr state)))
                                (to-decimal (cdr l)))]
        [else (cond [(car state) 
                     (begin
                       (set! state (cons (+ 1 (car state))
                                         (+ (cdr state)  (* (char->number (car l)) 
                                                            (/ 1 (expt 10 (+ 1 (car state))))))))
                       (to-decimal (cdr l)))]
                    [else 
                     (begin (set! state (cons #f (+ (* 10 (cdr state)) (char->number (car l)))))
                            (to-decimal (cdr l)))])]))

(define state1 `(0 0 0))

(define (sum-of-last-three)
  (let ([x (read)])
    (set! state1 (list (cadr state1) (caddr state1) x))
    (display (+ (car state1) (cadr state1) (caddr state1)))
    (sum-of-last-three)))

;problem 6: 

(define state2 `end)

(define (f x)
  (cond [(eq? state2 `end)
         (if (= x 0)
             (begin
               (set! state2 `seen-an-input)
               0)
             (begin
               (set! state2 `seen-an-input)
               1))]
        [else 
         (begin
           (set! state2 `end)
           0)]))


(define (make-account balance)
  (define (joint-account new-password)
    
    (define (withdraw amount passwd)
      (cond [(equal? passwd new-password)
             (if (>= balance amount)
                 (begin (set! balance (- balance amount))
                        balance)
                 "Insufficient funds")]
            [else "Wrong joint account password"]))
    
    (define (deposit amount)
      (set! balance (+ balance amount))
      balance)    
    
    (define (dispatch m)
      (cond ((eq? m `withdraw) withdraw)
            ((eq? m `deposit) deposit)
            (else "Unknown request")))
    
    dispatch)
  
  ;-----------------------
  
  (define (original-account password)
    
    (define (withdraw amount passwd)
      (cond [(equal? passwd password)
             (if (>= balance amount)
                 (begin (set! balance (- balance amount))
                        balance)
                 "Insufficient funds")]
            [else "Wrong original account password"]))
    
    (define (deposit amount)
      (set! balance (+ balance amount))
      balance)
    
    (define (make-joint passoriginal passjoint)
      (cond [(equal? passoriginal password)
             (joint-account passjoint)]
            [else "Wrong original account password while making joint account"]))
    
    (define (dispatch m)
      (cond ((eq? m `withdraw) withdraw)
            ((eq? m `deposit) deposit)
            ((eq? m `make-joint) make-joint)
            (else "Unknown request")))
    dispatch)
  
  original-account)

(define peter-account ((make-account 100000) "retep"))
(define paul-account ((peter-account `make-joint) "retep" "laup"))
((paul-account `withdraw) 100 "laup")
((paul-account `withdraw) 100 "retep")
((peter-account `withdraw) 100 "retep")
((peter-account `withdraw) 100 "laup") 
