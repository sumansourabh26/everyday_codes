#lang racket
(define(foldr f base l)
  (if (null? l) base
      (f (car l) (foldr f base(cdr l)))))

(define(foldl f base l)
  (define(foldl-h acc l)
    (if(null? l) acc
       (foldl-h (f acc (car l)) (cdr l))))
  (foldl-h base l))

(define(sum l)
  (foldr + 0 l ))

(define(product l)
  (foldr * 1 l))

(define(append l1 l2)
  (foldr cons l2 l1))

(define(reverse l)
  (foldr (λ(x l)(append l (list x))) 
         `() l))

(define(map f l)
  (foldr (λ(x l1)(cons (f x) l1))
         `() l))

(define(init l)
  (foldr(λ(x y)
          (cons '() (map (λ(t)(cons x t)) y))) '(()) l))

(define(tail l)
  (foldl (λ(x y)
          (cons '() (map(λ(t)(append t (list y)))x)))
          '(())
          l))
  
  
  (define(sublist l)
    (foldr (λ(x y)
             (foldr(λ(a b)
                     (cdr(append (tail a) b)))
                   '(())(init l)))
           '(()) l))
  