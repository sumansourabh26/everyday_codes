#lang racket
(require plot)
(plot-new-window? #t)
(plot-width 900)
(plot-height 900)

(define (draw curve)
 (plot (parametric
    (lambda (t) (vector (x-of (curve t))
                       (y-of (curve t))))
0 1 #:width 1 #:samples 10000
#:x-min -10 #:x-max 10
#:y-min -10 #:y-max 10)))

(define (repeated f n)
  (if (= n 0)
      identity
      (compose f (repeated f (- n 1)))))

(define (make-point x y)
   (lambda (bit)
      (if (zero? bit) x y)))

(define (x-of point)
    (point 0))

(define (y-of point)
   (point 1))

(define (unit-circle t)
   (make-point (sin (* 2 pi t))
     (cos (* 2 pi t))))


(define (unit-line-at y)
    (lambda (t) (make-point t y)))

(define unit-line (unit-line-at 0))

(define (vertical-line p l)
  (lambda (t) (make-point (x-of p) (+ (y-of p) (* l t)))))

(define (reflect-through-y-axis curve)
  (lambda (t) 
    (let ((ct (curve t)))
      (make-point (* -1 (x-of ct)) (y-of ct)))))

(define (translate x y)
  (lambda (curve) 
    (lambda (t) 
      (make-point (+ x (x-of (curve t))) (+ y (y-of (curve t)))))))
  
 (define (scale x y)
   (lambda (curve)
     (lambda (t) 
       (make-point (* x (x-of (curve t))) (* y (y-of (curve t)))))))
 
(define (rotate-around-origin radians)
  (lambda (curve) 
    (lambda (t)
      (let ((ct (curve t)))
        (make-point (- (*  (x-of ct) (cos radians)) (* (y-of ct) (sin radians)))
                       (+ (* (x-of ct) (sin radians)) (* (y-of ct) (cos radians))))))))

(define (put-in-standard-position curve) 
  (lambda (t) 
    (let* ((x-start (x-of (curve 0)))
           (y-start (y-of (curve 0)))
           (x-end (x-of (curve 1)))
           (y-end (y-of (curve 1)))
           (radians (if(zero?(- x-end x-start)) (/ pi 2) (atan (/ (- y-end y-start) (- x-end x-start)))))
           (ct ((translate (* -1 x-start) (* -1 y-start)) curve)) 
           (cr ((rotate-around-origin radians)ct))
           (x-e (x-of (cr 1)))
           (y-e (y-of (cr 1)))
           (cre ((scale (/ 1 x-e) (/ 1 x-e)) cr)))
              (cre t))))

(define (connect-rigidly curve1 curve2)
  (lambda (t)
    (if (< t (/ 1 2))
        (curve1 (* 2 t))
        (curve2 (- (* 2 t) 1)))))

(define (gosperize curve)
  (let ((scaled-curve ((scale (/ (sqrt 2) 2) (/ (sqrt 2) 2)) curve)))
    (connect-rigidly
     ((rotate-around-origin (/ pi 4)) scaled-curve)
     ((translate .5 .5)
      ((rotate-around-origin (/  (- pi) 4)) scaled-curve)))))

(define (gosper-curve level)
  ((repeated gosperize level) unit-line))


                  