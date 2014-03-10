#lang racket
(define (summands n)
  (sum-h 1 (list (list n))n)) 

(define (sum-h count acc n)
    (if (= count n) acc
        (sum-h (+ 1 count) (append (map (λ(t) (cons count t)) (summands (- n count))) acc) n)))