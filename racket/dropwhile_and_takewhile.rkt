#lang racket

(define(dropwhile cond l)
  (if(null? l) '()
     (if(cond (car l))(dropwhile cond (cdr l))
        l)))

(define(takewhile cond l)
  (define(takewhile-h acc listnow)
    (if(null? listnow) listnow
       (if(cond(car listnow))
          (takewhile-h (append acc (list (car listnow))) (cdr listnow))
          acc)))
  (takewhile-h '() l))
          