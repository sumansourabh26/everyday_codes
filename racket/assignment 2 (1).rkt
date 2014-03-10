#lang racket

(define n 4)
(define m 8)
(define k 4)
(define l 3)
(define bias (- (expt 2 (- k 1)) 1))
; Returns a pair of carry and sum (carry.sum)
; carry = (a &amp; b) | (b &amp; c) | (a &amp; c)
; sum = a ^ b ^ c
(define (bit-adder a b c)
  (cons (bitwise-ior (bitwise-and a b)
                     (bitwise-and b c)
                     (bitwise-and a c))
        (bitwise-xor a b c)))

; Returns a pair of borrow and subtraction (borrow-out.sub)
; Does m - n - borrow-in
; borrow-out = (m' &amp; borrow-in) | (n &amp; (m ^ borrow-in)')
; sub = m ^ n ^ borrow-in
(define (bit-subtractor m n borrow-in)
  (cons (bitwise-ior (bitwise-and (bitwise-not m) borrow-in)
                     (bitwise-and n (bitwise-not (bitwise-xor m borrow-in))))
        (bitwise-xor m n borrow-in)))

;------------------------------------------------------------------------------------------------------------------------------------------------------------------------
;problem 1
(define (b2u-n a)
  (define (b2u-helper a i)
    (if (null? a) 0
        (+ (* (car a) (expt 2 i)) (b2u-helper (cdr a) (- i 1)))))
  (if (= (length a) n) (b2u-helper a (- n 1))
      (error "not of right length")))

(define  (u2b-n a)
  (define (u2b-helper i)
    (cond ((= i 1) '(1))
          ((= i 0) '(0))
          (else (cons (remainder i 2) (u2b-helper (quotient i 2))))))
  (if (and (< a (expt 2 n)) (>= a 0))
      (let ((bin (u2b-helper a)))
        (reverse (append bin (zero (- n (length bin)))))) 
      (error "not in right range")))

(define (zero N)
  (if (= N 0) '()
      (cons 0 (zero (- N 1)))))
;-----------------------------------------------------------------------------------------------------------------------------------------------------------------------         
;problem 2
(define (b2s-n a)
  (define (b2s-h a i)
    (if (null? a) 0
        (+ (* (car a) (expt 2 i)) (b2s-h (cdr a) (- i 1)))))
  (if (= (length a) n) (- (b2s-h (cdr a) (- n 2)) (* (expt 2 (- n 1)) (car a)))
      (error "not of right lenght")))

(define (s2b-n a)
  (if (and (< a (expt 2 (- n 1))) (>= a (-  (expt 2 (- n 1)))))
      (if (>= a 0)
          (u2b-n a)
          (cons 1 (cdr (u2b-n (+ (expt 2 (- n 1)) a)))))
      (error "not in range")))
;-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
;problem 3
(define (n2m a)
  (if (= (length a) n)
      (if (= (car a) 0)
          (append (zero (- m n)) a)
          (append (one (- m n)) a))
      (error "not of right length")))

(define (one N)
  (if (= N 0) '()
      (cons 1 (one (- N 1)))))

;---------------------------------------------------------------------------------------------------------------------------------------------------------------------
;problem 4
(define (u-add a b)
  (define (u-add-h a b i)
    (if (null? a) '()
        (cons (cdr (bit-adder (car a) (car b) i)) 
              (u-add-h (cdr a)(cdr b) (car (bit-adder (car a) (car b) i))))))
  (if (= (length a)(length b)) (reverse (u-add-h (reverse a)(reverse b) 0))
      (error "no.s not of same length") ))

(define (u-sub a b)
  (define (u-sub-h a b i)
    (if (null? a) '()
        (cons (cdr (bit-subtractor (car a) (car b) i)) 
              (u-sub-h (cdr a)(cdr b) (car (bit-subtractor (car a) (car b) i))))))
  (reverse (u-sub-h (reverse a)(reverse b) 0)))
;---------------------------------------------------------------------------------------------------------------------------------------------------------------------  
;problem 5
(define (u-mult a b)
  (define (u-mult-h a b)
    (cond ((null? b)  (zero (* 2 n)))
          ((= (car b) 0) (shift-l (u-mult-h a (cdr b))))
          (else (u-add a (shift-l (u-mult-h a (cdr b)))))))
  (u-mult-h (append (zero n) a) (reverse (append (zero n) b))))

(define (shift-l l)
  (if (null? l) l
      (append (cdr l) '(0))))
;-----------------------------------------------------------------------------------------------------------------------------------------------------------
;problem 6
(define (s-mult a b)
  (define (s-mult-h a b)
    (cond ((null? b) (n2m (u2b-n 0)))
          ((= (car b) 0) (shift-l (s-mult-h a (cdr b))))
          (else (u-add a (shift-l (s-mult-h a (cdr b)))))))
  (s-mult-h (n2m a) (reverse (n2m b))))
;----------------------------------------------------------------------------------------------------------------------------------------------------------------------
;problem 7
(define (u-div x y)
  (if(= (b2u-n y) 0) 
     (error "can't divide by zero")
     (if (< (b2u-n x) (b2u-n y)) (cons (u2b-n 0) (list x))
         (let* ((a  (shift-l (car (u-div (cons 0 (drop-right x 1)) y))))
                (b  (shift-l (cadr (u-div (cons 0 (drop-right x 1)) y)))))
           (if (equal? (take-right  x 1) '(0)) 
               (if (< (b2u-n b) (b2u-n y)) (cons a (list b))
                   (cons (u-add a (u2b-n 1)) (list (u-sub b y))))
               (if (< (b2u-n (u-add b (u2b-n 1)))  (b2u-n y)) (cons a (list (u-add b (u2b-n 1)))) 
                   (cons (u-add a (u2b-n 1)) (list (u-sub (u-add b (u2b-n 1)) y)))))))))
;---------------------------------------------------------------------------------------------------------------------------------------------------------------------
;problem 8
(define (s-div x y)
  (cond ((and (= (car x) 0) (= (car y) 0)) (u-div x y))
        ((and (= (car x) 1) (= (car y) 1)) (list (u-add (car (u-div (2comp x) (2comp y))) (u2b-n 1)) (2comp(u-add (cadr (u-div (2comp x) (2comp y))) y))))
        ((and (= (car x) 0) (= (car y) 1)) (list (2comp (car (u-div x (2comp y)))) (cadr (u-div x (2comp y)))))
        ((and (= (car x) 1) (= (car y) 0)) (list (2comp (u-add (car (u-div (2comp x) y)) (u2b-n 1))) (u-sub y (cadr (u-div (2comp x) y)))))))

(define (2comp x)
  (u-sub (u2b-n 0) x))
;--------------------------------------------------------------------------------------------------------------------------------------------------------------------
;problem 9
(define (fix2d a)
  (define (fix2d-h a i)
    (if (null? a) 0
        (+ (* (car a) (expt 2 i)) (fix2d-h (cdr a) (- i 1)))))
  (* 1.0 (fix2d-h a (- n 1))))

(define (d2fix a)
  (define (fract b i)
    (cond ((= i (+ n 1)) '())
          ((>= (* 2 b) 1) (cons 1 (fract (- (* 2 b) 1) (+ i 1))))
          (else (cons 0 (fract (* 2 b) (+ i 1))))))
  (append (u2b-n (inexact->exact (floor a))) (fract (- a (floor a)) 1)))
;--------------------------------------------------------------------------------------------------------------------------------------------------------------------
;problem 10
(define (float2d a)
  (let* ((s (car a))
         (E (b2u-n (take (cdr a) k)))
         (F (/ (b2u-n (cons 0 (take-right (cdr a) l))) (expt 2 l))))
    (cond ((and (= E 0) (= F 0)) (* (expt -1 s) 0.0))
          ((= E 0) (* (expt -1 s) F (expt 2 (- 1 bias))))
          ((and (= E (- (expt 2 k) 1))(= F 0)) (* (expt -1 s) +inf.0))
          ((= E (- (expt 2 k) 1)) +nan.0)
          (else (* (expt -1 s) (+ 1 F) (expt 2 (- E bias)))))))

(define (d2float a)
  (if(= (abs a) +inf.0)
     (append (if (negative? a) '(1) '(0)) (make-list k 1) (make-list k 0))
     (let* ((f-h (* (abs a) (expt 2 (- bias 1)))))
       (if (< f-h 1) 
           (append (if (negative? a) '(1) '(0)) (make-list k 0) (u2b-n (floor (* f-h (expt 2 l)))))
           (append (if (negative? a) '(1) '(0)) (u2b-n (find-E (abs a))) 
                   (take-right  (u2b-n  (floor (* (- (/ (abs a) (expt 2 (- (find-E (abs a)) bias))) 1) (expt 2 l)))) l))))))

(define (find-E  b)
  (cond ((and (> b 0) (< b 1)) (- (find-E (* 2 b)) 1))
        ((< b 2) bias)
        (else (+ (find-E (/ b 2)) 1))))

;----------------------------------------------------------------------------------------------------------------------------------------------------------------------  
;problem 11
(define (add a b)
  (cond ((and (= (car a) 0 ) (= (car b) 0)) (add-h a b))
        ((and (= (car a) 1) (= (car b) 0)) (sub-h b (cons 0 (cdr a))))
        ((and (= (car a) 0) (= (car b) 1)) (sub-h a (cons 0 (cdr b))))
        ( else (cons 1(cdr (add-h (cons 0 (cdr a)) (cons 0 (cdr b))))))))

(define (add-h a b) 
  (let* ((f1 (take-right a l))
         (f2 (take-right b l))
         (e1 (take (cdr a) k))
         (e2 (take (cdr b) k))
         (E1 (exponent-part f1 e1))
         (E2 (exponent-part f2 e2))
         (F1 (fractional-part f1 e1))
         (F2 (fractional-part f2 e2)))
    (if (>= E1 E2) 
        (cons 0 (if (= (car (u-add (cons 0 F1) (right (cons 0 F2) (- E1 E2)))) 1)
                    (number (+ E1 1) (take (u-add (cons 0 F1) (right (cons 0 F2) (- E1 E2))) n))
                    (number E1 (cdr (u-add (cons 0 F1) (right (cons 0 F2) (- E1 E2)))))))
        (add-h b a))))

(define (right l pos)
  (append (zero pos) (drop-right l pos)))

(define (fractional-part f e)
  ( if (= (b2u-n e) 0) (cons 0 f)
       (cons 1 f)))

(define (exponent-part f e)
  (if (= (b2u-n e) 0) (- 1 bias)
      (- (b2u-n e) bias)))


(define (sub-h a b) 
  (let* ((f1 (take-right a l))
         (f2 (take-right b l))
         (e1 (take (cdr a) k))
         (e2 (take (cdr b) k))
         (E1 (exponent-part f1 e1))
         (E2 (exponent-part f2 e2))
         (F1 (fractional-part f1 e1))
         (F2 (fractional-part f2 e2)))
    (if (>= (float2d a) (float2d b)) 
        (cons 0 (number E1 (u-sub F1 (right F2 (- E1 E2)))))
        (cons 1 (cdr (sub-h b a))))))

(define (sub a b) 
  (cond ((and (= (car a) 0 ) (= (car b) 1)) (add-h a b))
        ((and (= (car a) 1) (= (car b) 1)) (sub-h b (cons 0 (cdr a))))
        ((and (= (car a) 0) (= (car b) 0)) (sub-h a (cons 0 (cdr b))))
        ( else (cons 1 (cdr (add-h (cons 0 (cdr a)) (cons 0 (cdr b))))))))

(define (number E F)
  (cond ((< E (- 1 bias)) (number (+ E 1) (right F 1)))
        ((and (= (car F) 0) (= E (- 1 bias))) (append (u2b-n 0) (cdr F)))
        ((= (car F) 1) (append (u2b-n (+ E bias)) (cdr F)))
        (else (number (- E 1) (shift-l F) ))))

;-------------------------------------------------------------------------------------------------------------------------------------------------------------------
;problem 12
(define (mult a b)
  (let*((f1 (take-right a l))
        (f2 (take-right b l))
        (e1 (take (cdr a) k))
        (e2 (take (cdr b) k))
        (E1 (exponent-part f1 e1))
        (E2 (exponent-part f2 e2))
        (F1 (fractional-part f1 e1))
        (F2 (fractional-part f2 e2))
        (product (u-mult F1 F2))) 
    (cons (if (= (car a) (car b)) 0 1) (number (+ E1 E2) (take product n)))))

(define (divide a b)
  (let* ((f1 (take-right a l))
        (f2 (take-right b l))
        (e1 (take (cdr a) k))
        (e2 (take (cdr b) k))
        (E1 (exponent-part f1 e1))
        (E2 (exponent-part f2 e2))
        (F1 (fractional-part f1 e1))
        (F2 (fractional-part f2 e2))
        (q  (car (u-div F1 F2))))
    (cons (if (= (car a) (car b)) 0 1) (number (- E1 E2) q))))    



















