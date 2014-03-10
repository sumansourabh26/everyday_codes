#lang racket
;;;;;;;;;;;;;;;;;;;;;;;;;;;CAUTION:
;SOME OF MY PROGRAMS ARE EXCLUSIVELY FOR PREDIFINED VALUES OF n AND m
; SO USE THOSE SIZE OF LIST ONLY


(define n 4)
(define m 8)
(define k 4)
(define l 3)

; Returns a pair of carry and sum (carry.sum)
; carry = (a & b) | (b & c) | (a & c)
; sum = a ^ b ^ c
(define (bit-adder a b c)
  (cons (bitwise-ior (bitwise-and a b)
                     (bitwise-and b c)
                     (bitwise-and a c))
        (bitwise-xor a b c)))

; Returns a pair of borrow and subtraction (borrow-out.sub)
; Does m - n - borrow-in
; borrow-out = (m' & borrow-in) | (n & (m ^ borrow-in)')
; sub = m ^ n ^ borrow-in
(define(lst char size)
  (if(= size 0)'()
     (cons char (lst char (- size 1)))))
(define (bit-subtractor m n borrow-in)
  (cons (bitwise-ior (bitwise-and (bitwise-not m) borrow-in)
                     (bitwise-and n (bitwise-not (bitwise-xor m borrow-in))))
        (bitwise-xor m n borrow-in)))

(define(greater? a b)
  (if(>(b2u-n a)(b2u-n b))#t #f))
(define(smaller? a b)
  (if(<(b2u-n a)(b2u-n b))#t #f))
(define(equality? a b)
  (if(=(b2u-n a)(b2u-n b))#t #f))
;;;;;;;;;;;;;;;;;;;;;;;b2u
(define(b2u-n l)
  (car(foldr(λ(x y)
              (if(null? y)(cons x 1)
                 (cons(+ (car y) (* x (expt 2 (cdr y))))
                      (+ (cdr y) 1)))) 
            '() l)))
(define(u2b-n  r)
  (u2b-n-h n r))
(define(u2b-n-h size r)
  (append (make-list (- size (length(u2b-n-hh r))) 0)(u2b-n-hh r)))
(define(u2b-n-hh r)
  (if(= r 0)'()
     (append (u2b-n-hh (quotient r 2))
             (list(remainder r 2)))))



(define(b2s-n l)
  (let ((newlist (if(= (car l) 1)(cons (- (car l))(cdr l))
                    l)))
    (b2u-n newlist)))

(define(longer b n)
  (if(= (length b) n) b
     (longer (cons 0 b) n)))
(define(helper n var r)
  (if (> var 1)(helper n (/ var 2)(+ r 1))
      (cons(- (expt 2 r)n)r)))
(define(s2b-n n)
  (cond[(> n 0)(cons 0(u2b-n n))]
       [else (let((left (helper(- n) (- n) 0)))
               (cons 1(longer (u2b-n (car left)) (cdr left)))
               )]))

;;;;;;;;;;;;;;;;;;Q3
(define(n2m l)
  (cond[(= (length l) m) l]
       [(n2m(cons(car l)l))]))

(define(n2ms size l)
  (cond[(= (length l) size) l]
       [(n2ms size(cons(car l)l))]))

(define(n2mu size l)
  (cond[(=(length l) size) l]
       [(n2mu size (cons 0 l))]))
;;;;;;;;;;;;;;Q4
(define(merge a b)
  (if(null? a)'() (cons(cons(car a)(car b))
                       (merge (cdr a)(cdr b)))))
(define(u-add-h a b)
  (flatten(let((bin (merge a b)))
            (foldr(λ(x y) (if(null? x)(cons (car y)
                                            (cdr y))
                             (let ((combination (bit-adder(car x)(cdr x)(car y))))
                               (cons(car combination)
                                    (list(append(list(cdr combination))
                                                (cdr y)))))))
                  (cons 0 '()) bin ))))
(define(u-add a b)
  (cdr(u-add-h a b)))

(define(u-sub a b)
  (let ((bin(merge a b)))
    (cdr(foldr (λ(x y)
                 (let((combination (bit-subtractor (car x)(cdr x)(car y))))
                   (cons (car combination)
                         (cons(cdr combination)(cdr y)))))
               (cons 0 '()) bin))))


;;;;;;;;;;;;;;;;Q5
(define(shift-l r l)
  (define(shift-h r l)
    (if (= r 0) '() (cons 0 (shift-h (- r 1 ) l))))
  (append l (shift-h r l)))

(define(shift-r r l)
  (append(make-list r 0) (take l (-(length l) r))))

(define(u-mult a  b)
  (if (=(length a)(length b))
      (let((size (length a)))
        (cdr(foldr (λ(x y)
                     (cons (+(car y) 1 )
                           (u-add (n2mu (* 2 size) (shift-l (car y)
                                                            (if(= x 1)a
                                                               (lst 0 size))))
                                  (cdr y))))
                   
                   (lst 0 (+(* 2 size)1)) b)))
      "give list of same length, or append 0's to the smaller list to make them equal"))
;;;;;;;;;;;;;;;;Q6
(define(s-mult-h a b)
  (let((size (length a)))
    (foldr(λ(x y)
            (if(= x 1)
               (cons (+(car y)1)
                     (u-add (n2ms ( * 2 size) (shift-l (car y) a ))
                            (cdr y)))
               (cons (+(car y) 1)
                     (u-add (n2ms(* 2 size) (shift-l (car y) (lst 0 size)))
                            (cdr y)))))
          (lst 0 (+(* 2 size)1)) b)))
(define(s-mult a b)
  (let((size (length a)))
    (if(=(car b)1)
       (u-add (u-sub(lst 0 (* 2 size))
                    (n2ms ( * 2 size) (shift-l (- size 1) a )))
              (cdr(s-mult-h a (cons 0 (cdr b)))))
       (cdr(s-mult-h a b)))))


;;;;;;;;;;;;;;Q7
(define(double l)
  (u-add l l))
(define(u-div-h m a b)
  (cond[(greater? b a) (list (make-list m 0) a)]
       [else(let((q (car(u-div-h m (shift-r 1 a) b)))
                 (r (cadr (u-div-h m(shift-r 1 a) b))))
              (cond[(=(last a)1) (if (>= (b2u-n(u-add(double r) (append(make-list (- m 1)0)'(1)))) (b2u-n b))
                                     (list(u-add (double q) (append(make-list (- m 1)0)'(1)))
                                          (u-sub (u-add (double r) (append(make-list (- m 1)0)'(1))) b))
                                     (list (double q) (u-add (double r) (append(make-list (- m 1)0)'(1)))))]
                   [(=(last a)0) (if (>=(b2u-n(double r)) (b2u-n b))
                                     (list(u-add (double q) (append(make-list (- m 1)0)'(1)))
                                          (u-sub (double r) b))
                                     (list (double q) (double r)))]))]))
(define(u-div a b)
  (u-div-h n a b))

;;;;;;;;';;;;Q8
(define (2scompli l)
  (u-sub(make-list (length l) 0)l))
(define(s-div a b)
  (cond[(and(=(car a)0)(=(car b)0))(u-div a b)]
       [(and(=(car b) 0)(=(car a)1)) (let((ans(u-div (2scompli a)b)))
                                       (list(2scompli (car ans))(2scompli(cadr ans))))]
       [(and(=(car b) 1)(=(car a)1)) (let((ans(u-div (2scompli a)(2scompli b))))
                                       (list (car ans))(2scompli(cadr ans)))]
       [(and(=(car b) 1)(=(car a)0)) (let((ans(u-div a (2scompli b))))
                                       (list(2scompli (car ans)) (cadr ans)))]))



;;;;;;;;;;;;;;Q9
(define(fix2d-h r l)
  (if(null? l)0
     (+(*(car l)(/ 1 (expt 2 r)))(fix2d-h (+ r 1) (cdr l)))))
(define(fix2d a)
  (let((size(/ (length a)2)))
    (+(b2u-n (drop-right a n))
      (fix2d-h 1 (take-right a n)))))

(define(d2fix-h n r rem)
  (if(= r (+ n 1)) '()
     (let((q (inexact->exact(floor(* rem (expt 2 r))))))
       (append (list q )
               (if(= q 0)
                  (d2fix-h n(+ r 1) rem)
                  (d2fix-h n(+ r 1)(- rem (/ 1(expt 2 r)))))))))
(define(d2fix a)
  (append(u2b-n(inexact->exact(floor a)))(d2fix-h n 1 (- a (floor a)))))

;;;;;;;;;;;;;;;;;;;;Q9 2
(define bias (-(expt 2 (- k 1))1))
(define(float2d-h k l lst)
  (let((f (take-right lst l ) )
       (e (cdr(take lst (+ k 1))))
       (s (car lst)))
    (cond[(equal? e (make-list k 0))
          (let ((power (expt 2 (- 1 bias))))
            (* (if (= s 0) 1 -1) (fix2d-h 1 f)power))]
         [(equal? e (make-list k 1))
          (cond[(equal? f (make-list l 0))(if(= s 0)+inf.0 -inf.0)]
               [else +nan.0])]
         [else (let((power (expt 2 (- (b2u-n e) bias))))
                 (* (if (= s 0) 1 -1)
                    (+(fix2d-h 1 f)1)
                    power))])))
(define(float2d lst)
  (float2d-h k l lst))

(define(d2float-h k l value)
  (let((avalue (abs value)))
    (cond[(< avalue (expt 2 (- 1 bias)))
          (cons (if(positive? value)0 1)
                (append (make-list k 0)
                        (d2fix-h l 1 (* avalue
                                        (expt 2 (- bias 1))))))]
         [(= value -inf.0)(append(make-list (+ k 1) 1)(make-list l 0))]
         [(= value +inf.0)(cons 0 (append(make-list k 1)(make-list l 0)))]
         [(or(= value +nan.0)(= value -nan.0))"can't determined with certainity"]
         [else(let*((E-bias (floor(/(log avalue)(log 2))))
                    (E      (+ bias E-bias))
                    (F    (-(/ avalue (expt 2 E-bias))1)))
                (cons (if(positive? value)0 1)
                      (append(n2mu k (u2b-n (inexact->exact E)))
                             (d2fix-h l 1 F))))])))
(define(d2float value)
  (d2float-h k l value))

;;;;;;;;;;;;;;;Q10
(define(add-h a b)
  (let*((s1 (car a))
        (s2 (car b))
        (e1 (take (cdr a)k ))
        (e2 (take (cdr b)k ))
        (f1 (cons(if(equal? (make-list k 0) e1) 0 1)
                 (take-right a l)))
        (f2 (cons(if(equal? (make-list k 0) e2) 0 1)
                 (take-right b l))))
    (define (case2 E1 E2 F1 F2)
      (let*((diffexp (if (and (equal? (make-list k 0) E2)
                              (not (equal? (make-list k 0) E1)))
                         (- (b2u-n E1) 1)
                         (b2u-n (u-sub E1 E2))))
            (new-F2 (append(make-list diffexp 0)F2))
            (fsum (u-add-h (append F1 (make-list diffexp 0)) new-F2))
            (stfsum(if(= (car fsum) 1)
                      (take (cdr fsum) l) 
                      (take (cddr fsum)l)))
            (ste (if(equal? E1(make-list k 0))                                  
                    (if(=(cadr fsum)1)(append (make-list(- k 1)0)'(1)) E1)
                    (if(=(car fsum)1)
                       (u2b-n (+ (b2u-n E1) 1))
                       (u2b-n (b2u-n E1) )))))
        (append ste stfsum )))
    (cond[(>= (b2u-n e1)(b2u-n e2))(case2 e1 e2 f1 f2)]
         [(greater?  e2 e1)(case2 e2 e1 f2 f1)]
         )))

(define(find1 r l)
  (if(=(car l)1)(cons (list r) (list(cdr l)))
     (find1 (+ r 1) (cdr l))))

(define(efinder l E1)
  (cond[(and(=(car l) 0) (=  (b2u-n E1) 0)) E1]
       [(= (car l)1)  E1]
       [else (efinder (cdr (append l '(0))) (u-sub  E1 (append(make-list (- k 1)0)'(1))))]))
(define(sub-h a b)
  (let*((s1 (car a))
        (s2 (car b))
        (e1 (take (cdr a)k ))
        (e2 (take (cdr b)k ))
        (f1 (cons(if(equal? (make-list k 0) e1) 0 1)
                 (take-right a l)))
        (f2 (cons(if(equal? (make-list k 0) e2) 0 1)
                 (take-right b l))))
    (define (case2 E1 E2 F1 F2)
      (let*((diffexp (if (and (equal? (make-list k 0) E2)
                              (not (equal? (make-list k 0) E1)))
                         (- (b2u-n E1) 1)
                         (b2u-n (u-sub E1 E2))))
            (new-F2  (append(make-list diffexp 0)F2))
            (fdiff (u-sub (append F1 (make-list diffexp 0)) new-F2))
            (stfdiff (if(equal? E1 (make-list k 0)) (take (cdr fdiff) 3)
                        (if (andmap (λ(x)(= x 0)) fdiff) (make-list l 0)
                            (let((a (find1 1 (append fdiff (make-list l 0)))))
                              (take (cadr a)3)))))
            (ste (efinder fdiff E1)))
        (append ste stfdiff)))
    (cond[(greater?  e1 e2)(case2 e1 e2 f1 f2)]
         [(greater?  e2 e1)(case2 e2 e1 f2 f1)]
         [else(cond[(>= (b2u-n f1)(b2u-n f2))(case2 e1 e2 f1 f2)]
                   [(greater?  f2 f1)(case2 e2 e1 f2 f1)])])))
(define(add a b)
  (let*((s1 (car a))
        (s2 (car b))
        (e1 (take (cdr a)k ))
        (e2 (take (cdr b)k ))
        (f1 (take-right a l))
        (f2 (take-right b l)))
    (cond[(and(= s1 0)(= s2 0))(cons 0 (add-h a b))]
         [(and(= s1 1)(= s2 0))(cond[(greater? e1 e2)(cons 1 (sub-h a b))]
                                    [(smaller? e1 e2)(cons 0 (sub-h a b))]
                                    [(equality? e1 e2)
                                     (cond[(greater?  f1 f2)(cons 1 (sub-h a b))]
                                          [(smaller? f1 f2)(cons 0 (sub-h a b))]
                                          [(equality? f1 f2)(make-list (+ 1 k l) 0)])])]
         [(and(= s2 1)(= s1 0))(cond[(greater? e1 e2)(cons 0 (sub-h a b))]
                                    [(smaller? e1 e2)(cons 1 (sub-h a b))]
                                    [(equality? e1 e2)
                                     (cond[(greater? f1 f2)(cons 0 (sub-h a b))]
                                          [(smaller? f1 f2)(cons 1 (sub-h a b))]
                                          [(equality? f1 f2)(make-list (+ 1 k l) 0)])])]
         [(and(= s1 1)(= s2 1))(cons 1 (add-h a b))])))


(define(sub a b)
  (let*((s1 (car a))
        (s2 (car b))
        (e1 (take (cdr a)k ))
        (e2 (take (cdr b)k ))
        (f1 (take-right a l))
        (f2 (take-right b l)))
    (cond[(and(= s1 0)(= s2 1))(cons 0 (add-h a b))]
         [(and(= s1 1)(= s2 1))(cond[(greater? e1 e2)(cons 1 (sub-h a b))]
                                    [(smaller? e1 e2)(cons 0 (sub-h a b))]
                                    [(equality? e1 e2)
                                     (cond[(greater? f1 f2)(cons 1 (sub-h a b))]
                                          [(smaller? e1 e2)(cons 0 (sub-h a b))]
                                          [(equality? f1 f2)(make-list (+ 1 k l) 0)])])]
         [(and(= s1 0)(= s2 0))(cond[(greater? e1 e2)(cons 0 (sub-h a b))]
                                    [(smaller? e1 e2)(cons 1 (sub-h a b))]
                                    [(equality? e1 e2)
                                     (cond[(greater? f1 f2)(cons 0 (sub-h a b))]
                                          [(smaller? f1 f2)(cons 1 (add-h a b))]
                                          [(equality? f1 f2 )(make-list (+ 1 k l) 0)])])]
         [(and(= s1 1)(= s2 0))(cons 1 (add-h a b))])))


;;;;;;;;;;;;;;;;;;;Q10




(define(mult a b)
  (let*((s1 (car a))
        (s2 (car b))
        (e1 (take (cdr a)k ))
        (e2 (take (cdr b)k ))
        (exp1(if(equal? (make-list k 0) e1)
                (- 1 bias)(-(b2u-n e1)bias)))
        (exp2(if(equal? (make-list k 0) e2)
                (- 1 bias)(-(b2u-n e2)bias)))
        (f1 (cons(if(equal? (make-list k 0) e1) 0 1)
                 (take-right a l)))
        (f2 (cons(if(equal? (make-list k 0) e2) 0 1)
                 (take-right b l))))
    (define(case2 E1 E2 F1 F2)
      (let*((frac (u-mult f1 f2)))
        (cons (if(=(car a)(car b)) 0 1) (num(if(=(car frac)1) (+ exp1 exp2 )
                                               (+ exp1 exp2 1))frac))))
    (case2 e1 e2 f1 f2)))

(define (num exponent fraction)
  (cond ((< exponent (- 1 bias)) (num (+ exponent 1) (shift-r  1 fraction)))
        ((and (= (car fraction) 0) (= exponent (- 1 bias))) (append (u2b-n 0) (take(cdr fraction)l)))
        ((= (car fraction) 1) (append (u2b-n (+ exponent bias)) (take(cdr fraction)l)))
        (else (num (- exponent 1) (drop(shift-l 1  fraction)1 )))))



;;;;;;;;;;;;;;;;;;;;;;;;Q11
(define(div-h a b)
  (let*((s1 (car a))
        (s2 (car b))
        (e1 (b2u-n(take (cdr a)k )))
        (e2 (b2u-n(take (cdr b)k )))
        (f1 (cons(if(equal? (make-list k 0) e1) 0 1)
                 (take-right a l)))
        (f2 (cons(if(equal? (make-list k 0) e2) 0 1)
                 (take-right b l))))
    (let*((qtn (car(u-div-h (* 2(+ l 1)) (append f1 (make-list (+ l 1)0))
                            (append (make-list (+ l 1)0) f2)))))
      (if(<=(caar(find1 1 qtn))(+ l 1))
         (num (+(- e1 e2) (-(+ l 1)(caar(find1 1 qtn)))) (cons 1(cadr (find1 1 qtn))))
         (num (- e1 e2) (take-right qtn (+ l 1)))))))
(define(div a b)
  (cons (if(=(car a)(car b)) 0 1) (div-h a b)))

