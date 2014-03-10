#lang racket
(define (div x y)
  (cond((< x y) (cons 0 x))
     (else(let* ((pair (div(quotient x 2) y))
             (q1 (car pair))
             (r1 (cdr pair))
             (tq1 (* 2 q1))
             (tr1 (if (even? x)
                      (* 2 r1)
                      (+(* 2 r1) 1))))
        (if(>= tr1 y)(cons (+ tq1 1)(- tr1 y)) (cons tq1 tr1))))))
             