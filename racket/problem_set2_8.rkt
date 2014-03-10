#lang racket

(define(foldr f base l)
  (if (null? l) base
      (f (car l) (foldr f base(cdr l)))))

(define(delete r l)
  (define(delete-h p1 p2 count)
    (if (= count r) (append p1 (cdr p2))
        (delete-h (append p1 (list (car p2)))(cdr p2) (+ count 1))))
  (delete-h '() l 1))
    
(define(insert element r l)
  (define(insert-h p1 p2 count)
    (if(= count r) (append(append p1 (list element))p2)
       (insert-h (append p1 (list(car p2)))(cdr p2)(+ count 1))))
  (insert-h '() l 1))

(define(replace new place list)
  (insert new place (delete place list)))