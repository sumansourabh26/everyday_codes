#lang racket
(define (total-coin j)
  (total-coin-h 1 j))

(define (total-coin-h  i j)
  (if(= i 9) 10000000000000000000000
     (if(= 0 j) 0
        (let((dnmtn (cond ((= i 1) 50)
                          ((= i 2) 25)
                          ((= i 3) 20)
                          ((= i 4) 10)
                          ((= i 5) 5)
                          ((= i 6) 3)
                          ((= i 7) 2)
                          ((= i 8) 1))))
          
          (if(> dnmtn j)
             (total-coin-h (+ i 1) j)
             (min (+(total-coin-h i (- j dnmtn)) 1) (total-coin-h (+ i 1) j) )))))) 
  