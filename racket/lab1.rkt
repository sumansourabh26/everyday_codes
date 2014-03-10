#lang racket
(define (akmult x y)
  (cond [(= x 0) 0]
        [(= x 1) y]
        [(even? x) (* 2 (akmult (quotient x 2) y))]
        [(odd? x) (+ y (* 2 (akmult (quotient x 2) y)))]))
(define (div x y)
  (cond [(< x y) (cons 0 y)]
        [else ( let*([pair(div (quotient x 2) y)]
              [ q1 (car pair)]
              [ r1 (cdr pair)]
              [tq1 (* 2 q1)]
              [tr1 (if (even? x)
                   (* 2 r1)
                   (+ 1 (* 2 r1)))])
              ( if (>= tr1 y) (cons (+ 1 tq1) (- tr1 y))
                  (cons tq1 tr1)))]))
(define (find a b)
  (let* ([g (gcd a b)])
  (if (= a g) (cons 1 0)
      (cons (cdr (find b (modulo a b))) 
            (- (car (find b (modulo a b))) (* (cdr (find b (modulo a b))) (quotient a b)))))))
(define (expmod x y n)
  (define (multmod a b)
    (modulo (* (modulo a n) (modulo b n)) n))
  (cond ((= y 0) 1)
        (else (let*( [res (expmod x (quotient y 2)  n)])
                (cond ((even? y) (multmod res res))
                      ((odd? y) (multmod x (multmod res res))))))))
(define (prime n)
  (define (check i n)
    (if (= i n) #t
        (and (not(= (modulo n i) 0)) (check (+ i 1) n))))
  
  (check 2 n))
(define (carm i n)
    (cond ((= i (+ n 1)) #t)
          ((not(= (gcd n i) 1)) (carm (+ i 1) n))
          (else(if (= (expmod i (- n 1) n) 1) (carm (+ i 1) n) #f))))
(define (carmichael n)
 
  (define (find i j)
    (if (= j n) (- i 1)
        (if (prime i) (find (+ i 1) j)
        (if (carm 1 i) (find (+ i 1) (+ j 1))
            (find (+ i 1) j)))))
  (find 4 0))
(define (fun i j)
  (cond ((and (prime i) (prime j)) (cons i j))
      (else (fun (+ i 2) (- j 2)))))
  (define (goldbach m)
    (if (= m 4) (cons 2 2)
        (fun 3 (- m 3))))
    (define (minchange n)
        (cond ((>= n 50)  (+ (quotient n 50) (minchange (modulo n 50))))
              ((and (< n 50) (>= n 25)) (+ 1 (minchange (modulo n 25))))
              ((and (< n 25) (>= n 20)) (+ 1 (minchange (modulo n 20))))
              ((and (< n 20) (>= n 10))  (+ 1 (minchange (modulo n 10))))
              ((and (< n 10) (>= n 5))  (+ 1 (minchange (modulo n 5))))
              ((and (< n 5) (>= n 3))  (+ 1 (minchange (modulo n 2))))
              ((= n 2) 1)
              ((= n 1) 1)
              ((= n 0) 0)))
    
 
   (define (isprime n)
     (define (rand n)
       (let* ((p (random n)))
         (if (= 0 p) 1 p)))
     (define (try i)
     (cond [(= i 200) "prime"]
           [(= 1 (expmod (rand n) (- n 1) n)) (try (+ i 1))]
           [else "composite"]))
     (try 1))
   ;(define (f i))
;(define (cansurvive pos n)
  
  
                              
              