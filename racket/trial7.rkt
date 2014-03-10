#lang racket
(require  (lib "trace.ss"))

(define (concat l) (foldr append `() l))

(define-syntax lc
  (syntax-rules (: <- @)
    [(lc exp : var <- lexp) (map (lambda (var) exp) lexp)]
    [(lc exp : @ guard) (if guard (list exp) `())]
    [(lc exp : @ guard qualifier ...) 
     (concat (lc (lc exp : qualifier ...) : guard))]
    [(lc exp : var <- lexp qualifier ...) 
     (concat (lc (lc exp :  qualifier ... ) : var <- lexp))]))

(define(qsort l)
  (if (null? l)'()
      (let((low (lc x : x <- (cdr l) @ (<= x (car l))))
           (high(lc x : x <- (cdr l) @ (> x (car l)))))
        (append (qsort low)(append(list (car l))(qsort high))))))

(define(zip l1 l2)
  (if(or(null? l1)(null? l2)) '()
     (append (list(cons (car l1)(car l2)))(zip (cdr l1)(cdr l2)))))

(define (ziplecture l1 l2)
  (cond [(null? l1) `()]
        [(null? l2) `()]
        [else (cons (cons (car l1) (car l2)) (zip (cdr l1) (cdr l2)))]))

(define(1-to-n n)
  (if (= n 0) '()
      (cons n (1-to-n (- n 1)))))
(define(all l)
  (foldr(λ(x y) (
                 
                 (define(queen n)
                   (define(allsafe pos sol)
                     (all(lc (safe?(cons pos n) fullpos2): fullpos2 <- (zip sol (1-to-n (- n 1))))))
                   (define (safe? p1 p2)
                     (not(or(=(car p1)(car p2))
                            (=(abs(- (car p1) (car p2)))(abs(- (cdr p1) (cdr p2)))))))
                   (if(= n 0)'(())
                      (lc (append sol (list pos)) : sol <- (queen (- n 1)) pos <- (1-to-n n)@ (allsafe pos sol))))
                 
                 
                 