#lang racket
(curve2 (cond [(= (x-of(curve 1)) 0)(rotate (if (> (y-of(curve 1)) 0) 
                                                (/ pi 2)
                                                (-(/pi 2))) curve1)]
              [else(let(slope (atan (/(y-of(curve 1))(x-of(curve 1)))))
                     (cond[(> x 0)(rotate slope curve1)]
                          [(and (< x 0)(< y 0))(rotate (+ pi slope) curve1)]))]))