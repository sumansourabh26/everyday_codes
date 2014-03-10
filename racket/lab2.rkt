
#lang racket
(define (append l1 l2)
  (if (null? l1) l2
      (cons 
       (car l1)(append (cdr l1) l2))))
(define (reverse l)
  (if (null? l) l
      (append (reverse (cdr l)) (list(car l)))))

(define (map f l)
  (if (null? l) l
      (cons (f (car l)) (map f (cdr l)))))
(define (foldr f id l)
  (if (null? l) id
      (f (car l)(foldr f id (cdr l)))))

(define (f0 x y)
  (let* ((a x))
  (filtered-accumulate (λ(t) (= (modulo (+ (- t a) 1) 13) 0)) + (λ(t) t) 0 x))) 
(define (filtered-accumulate cond f g id x y)
  (if (> x y) id
   (if (cond x) (f (g x) (filtered-accumulate cond f g id (+ x 1) y))
             (filtered-accumulate cond f g id (+ x 1) y))))
(define (f1 x y)
  (filtered-accumulate (λ(t) (= (modulo t 2) 1)) + sqr 0 x y)) 
(define (f2 x y)
  (filtered-accumulate (λ(t) (= (modulo t 3) 0)) * fac 1 x y))
(define (fac n)
  (define (nfac count ans)
    (if (> count n)ans
        (nfac (+ 1 count) (* count ans))))
  (nfac 1 1))
(define (f3 x y)
  (filtered-accumulate (λ(t) (prime t)) + sqr 0 x y))
(define (prime x)
  (define (check count)
    (if (= count x)#t
        (if (= (modulo x count) 0) #f
            (check (+ 1 count)))))
  (if (= x 2)#t
  (check 2)))
(define (f4 x)
  (let* ((a x))
  (filtered-accumulate (λ(t) (= (gcd t a) 1)) * (λ(t) t) 1 1 x)))
(define (powerset l)
 (foldr (λ(x y) (append y (map (λ(t) (cons x t)) y))) '(()) l)) 
(define (init l)
  (foldr  (λ(x y) (cons '() (map (λ(t) (cons x t)) y))) '(()) l))
(define (tail l)
  (let* (( r (reverse l)))
    (foldr  (λ(x y) (cons '() (map (λ(t) (cons x t)) y))) '(()) r)))

(define (sublist l)
  (define (sublist-h l)
  (if (null? l) l
  (append (cdr (init l)) (sublist-h (cdr l)))))
  (cons '() (sublist-h l)))

  (define (foldr1 f x y)
   (if (and (> (length x) 2) (> (length y) 2))
    (f (cons (car x) (car y)) (foldr1 f (cdr x) (cdr y)))
    (let* (( r (reverse x))
           (p (reverse y)))
     (cons (cons (car x) (car y)) (cons (cons (car r) (car p)) '())))
     ))
 
(define (transpose m)
  (if (>= (length m) 2)
 (foldr (λ(x y) (foldr1 cons x y)) (nul (length (car m))) m)
 m))
 
(define (nul n)
  (define (nul-h count ans)
    (if (= count n) ans
        (nul-h (+ 1 count) (cons '() ans))))
  (nul-h 1 '(())))
(define (mat-mult a b)
  (map  (λ(t) (foldr2 t b)) a))
(define (foldr2 t b)
  (if (null? (car b)) (car b) 
      (cons (add1 t b) (foldr2 t (map (λ(k) (cdr k)) b)))))
(define (add1 t b)
  (if (null? t)0
      (+ (* (car t) (car (car b))) (add1 (cdr t) (cdr b)))))
(define (evaluate x poly)
  (if (= (length poly) 1) (car poly)
  (+ (car poly) (* x (evaluate x (cdr poly))))))
(define (add p1 p2)
  (cond ((and (null? p1)(null? p2)) `())
        ((null? p1) p2)
        ((null? p2) p1)
        (else (cons (+ (car p1) (car p2)) (add (cdr p1)(cdr p2))))))
(define (split n)
  (define (sol count acc)
    (if (= count (+ n 1)) acc
        (sol (+ 1 count) (cons (cons count (list(- n count))) acc))))
  (sol 0 `()))
(define (power n p1 p2)
  (let* (( l1 (length p1))
         (l2 (length p2)))
  (foldr (λ(x y) (+ y (* (term p1 (+ 1 (car x))) (term p2 (+ 1 (- n (car x)))))))  0 (split n))))
(define (term p i)
  (if (or (null? p) (> i (length p))) 0
   (if (= i 1) (car p)
        (term (cdr p) (- i 1)))))
(define (multiply p1 p2)
  (let* (( p (+ (- (length p1) 1) (- (length p2) 1))))
    (define (mult count acc)
      (if (= count 0) acc
          (mult (- count 1) (cons (power (- count 1) p1 p2) acc))))
    (mult (+ 1 p) `())))
(define (rle l)
  (foldr (λ(x y) (if (null? y) (list(append (list x) (list 1))) 
                         (if (= x (car (car y))) (cons (cons x (list (+ 1 (car (cdr (car y)))))) (cdr y))
                     (cons (cons x (list 1)) y)))) `() l))

(define (cprod l)
  (foldr (λ(x y) (add-h x y)) `(())  l))
(define (nullset)
  (λ(x) #f))
(define (union c1 c2)
  (λ(x) (or (c1 x) (c2 x))))
(define (intersection c1 c2)
  (λ(x)  (and (c1 x) (c2 x))))
(define (member c x)
  (c x))
(define (difference c1 c2)
  (λ(x) (or (and (c1 x) (not (c2 x))) (and (c2 x) (not (c1 x))))))
(define (insert c x)
  (λ(t) (if (= t x) #t
            (c t))))
(define (gc n)
  (if (= n 0) `(())
      (add-h `(0 1) (gc (- n 1)))))
(define (add-h l1 l2)
  (foldr (λ(x y) (append (map (λ(t) (cons x t)) l2) y)) `()  l1))
(define (summands n)
 
      (define (sum-h count acc)
        (if (= count n) acc
            (sum-h (+ 1 count) (append (map (λ(t) (cons count t)) (summands (- n count))) acc))))
      (sum-h 1 (list (list n))))
(define (shuffle l1 l2)
  (define (shuffle-h l1 l2 ans)
  (cond ((and (null? l1)(null? l2)) ans)
      ((null? l1) (map (λ(t) (append t l2)) ans))
      ((null? l2) (map (λ(t) (append t l1)) ans))
      (else (append (shuffle-h (cdr l1) l2 (map (λ(t) (append t (list (car l1)))) ans))
                    (shuffle-h l1 (cdr l2) (map (λ(t) (append t (list (car l2)))) ans))))))
  (shuffle-h l1 l2 `(())))
(define (flatten l)
  (if (null? l) l
      (if (not (list? (car l))) l
      (append (flatten (car l)) (flatten (cdr l))))))
;;;;;;;;;;;;;;;

 (define (ssm-h l)
  (foldr (λ(x y) (if (null? (car y)) (list (list x)) 
                     (append y (append (list (list x)) (map (λ(t) (if (< x (car t)) (cons x t) t)) y))))) `(()) l))
(define (ssm l)
  (let* (( q (ssm-h (cdr l)))
         (p (map (λ(t) (if (> (car t) (car l)) (cons (car l) t) '())) q)))
   (define (fun l count ans)
  (cond ((= count (length p)) ans)
        ((> (length (car l)) (length ans)) (fun (cdr l) (+ 1 count) (car l)))
       (else  (fun (cdr l) (+ 1 count) ans))))    
 (fun p 1 (car p))))
    
    

  

                  
  
                 
  
        
        
                       
      
         
  
  
  
  
  
  
  
  
  