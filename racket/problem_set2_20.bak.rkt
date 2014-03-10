#lang racket
(define(pascal-h l)
  (if(null? (cdr l)) '()
     (cons (+(car l)(car(cdr l))) (pascal-h (cdr l)))))

(define(pascal-row n)
  (if(= n 1) 1
     (if(= n 2)(list 1 1)
        (append '(1) (append(pascal-h (pascal-row(- n 1))) '(1))))))