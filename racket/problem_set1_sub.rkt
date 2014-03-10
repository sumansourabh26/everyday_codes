#lang racket
(define (sub a b)
  (if (=(quotient a 10) 0)(- a b) (+(* 10 (sub (quotient a 10)(quotient b 10)))
                                  (- (remainder a 10)(remainder b 10)))))
