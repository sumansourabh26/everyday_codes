#lang racket
(define(survive? position n)
  (cond[(< n 3) #t]
       [(= position 3) #f]
       [(survive? (cond[(> position 3)(- position 3)]
                       [(= position 1)(- n 2)]
                       [(= position 2)(- n 1)])
                  (- n 1))])) 