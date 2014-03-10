#lang racket
(require racket/mpair)
(define storable%
  (class object%
    (super-new)
    (define/public (read) (error "Should be overridden"))
    (define/public (write) (error "Should be overridden"))
    (define/public (print) (error "Should be overridden"))))
(define register-bank%
  (class storable%
    (init regi-list)
    (define rnames regi-list)
    (super-new)
    (define/override ( write register-name change-val)
      (set-mcdr! (massoc register-name rnames) change-val)
      )
    (define/override ( read register-name)
      (mcdr (massoc register-name rnames)))
    (define/override (print)
      rnames)))
(define memory%
  (class storable%
    (init memo-size)
    (define memory-vec (make-vector memo-size 0))
    (super-new)
    (define/override (read no)
      (vector-ref memory-vec no))
    (define/override (write no change-val)
      (vector-set! memory-vec no change-val))
    (define/override (print)
      memory-vec)))
(define processor%
  (class object%
    
    (init mem-size)
    (define mem (new memory%
                     (memo-size mem-size)))
    (init reg-names)
    (define (make-names l1)
      (define (help l ans)
        (if (null? l) ans
            (help (cdr l) (mcons (mcons (car l) 0) ans))))
      (mreverse (help l1 '{})))
    (define b (make-names reg-names))
    (define reg-bank (new register-bank%
                          [regi-list b]))
    (init inst-set)
    (define oper-list inst-set)
    (super-new)
    
    (define (rest l1)
      (define (help l)
        (cond [(null? l) (error "wrong prog")]
              [(equal? (caar l) (car l1)) 
               (send reg-bank write (cadr l1) ((cadar l) 
                                               (send reg-bank read (cadr l1))
                                               (send reg-bank read (caddr l1))))]
              [else (help (cdr l))]))
      (help oper-list))
    (define/public (execute prog)
      (if (null? prog) "Done"
          (begin (let* ((first (car prog)))
                   (cond [(equal? (car first) 'load) 
                          (send reg-bank write (cadr first)
                                (caddr first))]
                         [(equal? (car first) 'store) 
                          (send mem write (cadr first)
                                (caddr first))]
                         [else (rest first)]))
                 (display "Memory:")
                 (newline)
                 (send mem print)
                 (display "Registers:")
                 (newline)
                 (send reg-bank print)
                 (execute (cdr prog)))))
    
    (define (get-arguments l1)
      (cond [(not (null? l1)) (car l1) (get-arguments (cdr l1))]))))
(define as2013
  (new processor%
       [mem-size 32]
       [reg-names (list 'r1 'r2 'r3 'r4)]
       [inst-set (list (list 'add (lambda (val1 val2)
                                    (+ val1 val2)))
                       (list 'mul (lambda (val1 val2)
                                    (* val1 val2)))
                       (list 'incr (lambda (val)
                                     (+ val 1))))]))
(define sample-prog (list
                     (list 'load 'r2 15) ;Put in register r2 the number 15
                     (list 'load 'r1 5)
                     (list 'store 1 'r1)
                     (list 'add 'r1 'r2) ;Add r1 and r2, the result goes to r1
                     (list 'load 'r3 2) ;Put in register r3 the number 2
                     (list 'mul 'r3 'r2) ;Multiply r3 and r2, the result goes to r3
                     (list 'add 'r1 'r3) ;Add r1 and r3, the result goes to r1
                     (list 'store 1 'r1)))
(send as2013 execute sample-prog)