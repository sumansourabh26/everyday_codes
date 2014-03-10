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
         #:x-min -20 #:x-max 20
         #:y-min -20 #:y-max 20)))

(define(make-point x y)
  (lambda(p)(if(zero? p) x y)))

(define(x-of point)
  (point 0))
(define(y-of point)
  (point 1))
(define (str-line m c)
  (lambda(t)
    (make-point t (+ c (* m t)))))
(define(sqrt-sqr x y)
  (sqrt(+(sqr x)(sqr y))))
(define(semi-circle r)
  (λ(t)(make-point (* r (cos(* pi t))) (* r (sin(*  pi t))))))
(define(rotate-about-origin theta)
  (λ(curve)
    (λ(t)(make-point (+(* (x-of (curve t))
                          (cos theta))(* (y-of (curve t)) 
                                         (sin theta)))(-(* (y-of (curve t))
                                                           (cos theta))(* (x-of (curve t))
                                                                          (sin theta)))))))
(define(translate a b)
  (λ(curve)
    (λ(t)(make-point (+ a (x-of (curve t))) (+ b (y-of (curve t)))))))
(define(scale rx ry)
  (λ(curve)
    (λ(t)(make-point (/  (x-of (curve t))rx)(/ (y-of (curve t))ry)))))
(define(put-in-standard-position curve)
  (λ(t)(let*((curve ((translate (* -1 (x-of (curve 0)))(* -1 (y-of (curve 0))))curve))
             (curve (cond[(and (= (x-of (curve 1)) 0)(> (y-of (curve 1)) 0)) (rotate-about-origin (/ pi 2) curve)]
                         [(and (= (x-of (curve 1)) 0)(< (y-of (curve 1)) 0)) (rotate-about-origin (-(/ pi 2))curve)]
                         [else(let ((slope (atan(/(y-of (curve 1))(x-of (curve 1))))))
                                (if (> (x-of (curve 1)) 0) ((rotate-about-origin slope) curve) (rotate-about-origin (+ pi slope) curve)))]))
             (curve ((scale ((sqrt-sqr (x-of (curve 1))(y-of (curve 1)))(sqrt-sqr (x-of (curve 1))(y-of (curve 1)))))curve)))
         (make-point (x-of (curve t))(y-of (curve t))))))
(define (compose f g)
  (lambda (x)
    (f (g x))))
(define (repeated f n)
  (if (= n 0)
      identity
      (compose f (repeated f (- n 1)))))
(define (identity x) x)
(define (unit-line y)
  (λ(t) (make-point t y)))
(define(connect-rigidly curve1 curve2)
  (λ(t)
    (if(< t 0.5)
       (curve1(* 2 t))
       (curve2(- (* 2 t) 1)))))
(define(connect-ends curve1 curve2)
  (connect-rigidly curve1 ((translate (-(x-of (curve1 1))(x-of(curve2 0)))
                                      (-(y-of (curve1 1))(y-of(curve2 0))))
                           curve2)))
(define (gosperize curve)
  (let ((scaled-curve ((scale (/ (sqrt 2) 2) (/ (sqrt 2) 2)) curve)))
    (connect-rigidly
     ((rotate-about-origin (/ pi 4)) scaled-curve)
     ((translate .5 .5)
      ((rotate-about-origin (/ (- pi) 4)) scaled-curve)))))
(define (gosper-curve level)
  ((repeated gosperize level) (unit-line 0)))