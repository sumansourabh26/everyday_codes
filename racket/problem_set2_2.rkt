#lang racket

(define(foldr f base l1)
  (if (null? l1) base
      (f (car l1) (foldr f base(cdr l1)))))

(define(insert a l)
  (cons a l))

(define(member r l)
  (cond[(null? l) #f]
       [(=(car l) r) #t]
       [else (member r(cdr l))]))

(define(union l1 l2)
  (cond[(null? l1) l2]
       [(member(car l1)l2) (union(cdr l1)l2)]
       [else (union (cdr l1)(cons (car l1) l2))]))

(define(intersection l1 l2)
  (intersection-h l1 l2 `()))
(define(intersection-h l1 l2 final)
  (cond[(null? l1) final]
       [(member(car l1) l2)(intersection-h (cdr l1) l2 (cons (car l1) final))]
       [else(intersection-h (cdr l1) l2  final)]))

(define(append l1 l2)
  (if(null? l1) l2
     (cons (car l1)(append (cdr l1) l2))))

(define(reverse l1)
  (if(null? l1) `()
     (append (reverse (cdr l1))(list(car l1)))))

(define(map f l)
  (if(null? l) `()
     (append(list(f (car l)))(map f (cdr l))))) ; instead of it, we could also write (cons(f(car l))(map f (cdr l)))

(define(filter_even? l1)
  (if(null? l1) `()
     (if(even? (car l1))
        (cons(car l1)(filter_even? (cdr l1)))
        (filter_even? (cdr l1)))))

(define




