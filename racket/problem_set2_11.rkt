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

(define (zip l1 l2)
  (cond [(null? l1) `()]
        [(null? l2) `()]
        [else (cons (cons (car l1) (car l2)) (zip (cdr l1) (cdr l2)))]))

(define(rowcheck l)
  (define(rowcheck-h r l)
    (cond[(null? l)#f]
         [(= r (car l)) #t]
         [else (rowcheck-h r (cdr l))]))
  (define(rowcheck-hh r l)
    (cond[(= r 10) #t]
         [(rowcheck-h r l)(rowcheck-hh (+ r 1) l)]
         [else  #f]))
  (rowcheck-hh 1 l))

(define(transpose m)
  (let((size (length (car m))))
    (define(empty-mat n)
      (if(= n 1) '(())
         (cons '()(empty-mat(- n 1)))))
    (foldr(λ(x y)(map cons x y)) (empty-mat size )  m)))


(define(sudoku l)
  (and (rowcheck l)(rowcheck(transpose l)) 
  
  