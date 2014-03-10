#lang racket



(define(flatten-check l)
  (if(null? l)#t
     (if(list? (car l)) #f
        (flatten-check(cdr l)))))


(define(flatten l)
  (define(flatten-h l)
    (if (flatten-check l) l
        (flatten-h(foldr(λ(x y)
                          (if (list? x)(append x y)
                              (cons x y)))
                        '()
                        l))))
  (flatten-h l))

