#lang racket
(require plot)
(plot-new-window? #t)
(plot-width 900)
(plot-height 900)
(define (draw curve)
  (plot (parametric
         (lambda (t) (vector (x-of (curve t))
                             (y-of (curve t))))
         0 1 #:width 1 #:samples 20000
         #:x-min -10 #:x-max 10
         #:y-min -10 #:y-max 10)))

(define(make-point x y)
  (lambda(p)(if(zero? p) x y)))

(define(x-of point)
  (point 0))
(define(y-of point)
  (point 1))

(define(vertical-line p l )
  (λ(r)(make-point (x-of p)
                        (+ (y-of p) (* r l)))))

