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
         #:x-min -50 #:x-max 50
         #:y-min -50 #:y-max 50)))

(define (koch-flakes level)
  (lambda (t) 
    (cond ((< t (/ 1.0 3)) ((rotate-about -16 0 
                                        (koch-at -16 0 level 32) (/ pi 3)) (* t 3)))
          ((and (> t (/ 1.0 3)) (< t (/ 2.0 3))) 
           ((rotate-about 0 (* 32 (sin (/ pi 3))) 
                          (koch-at 0 (* 32 (sin (/ pi 3))) level 32) (/ (* -1 pi) 3)) (- (* t 3) 1)))
          ((> t (/ 2.0 3)) ((rotate-about 16 0 (koch-at 16 0 level 32) pi) (- (* t 3) 2))))))
(define (x-of point)
  (point 0))

(define (y-of point)
  (point 1))

(define (make-point x y)
  (lambda (bit)
    (if (zero? bit) x y)))

(define (rotate-about  x0 y0 curve radians)
  (lambda (t) 
    (let* ((ct (curve t))
           (x (x-of ct))
           (y (y-of ct)))
      (make-point (- (+ x0 (* (- x x0) (cos radians))) 
                     (* (- y y0) (sin radians)))
                  (+ (+ y0 (* (- x x0) (sin radians))) 
                     (* (- y y0) (cos radians)))))))

(define (koch-at x y level length)
  (lambda (t)
    (if (= level 0) 
        ((horizontal-line (make-point x y) length) t)
        (cond ((< t (/ 1 4)) ((koch-at x y (- level 1) (/ length 3)) (* 4 t)))
              ((and (> t (/ 1 4)) (< t (/ 1 2))) 
               ((rotate-about 
                 (+ x (/ length 3)) y (koch-at (+ x (/ length 3)) y (- level 1) (/ length (* 6 (cos (/ pi 3))))) (/ pi 3)) (-(* 4 t) 1)))
              ((and (> t (/ 1 2)) (< t (/ 3 4))) 
               ((rotate-about 
                 (+ x (/ length 2)) (+ y (/ (* length (sin (/ pi 3)))  3)) 
                 (koch-at (+ x (/ length 2)) (+ y (/ (* length (sin (/ pi 3)))  3)) (- level 1) (/ length 3)) (/ (* -1 pi) 3)) (-(* 4 t) 2)))
              ((> t (/ 3 4)) ((koch-at (+ x (/ (* 2 length) 3)) y (- level 1) (/ length 3)) (-(* 4 t)3)))))))

(define (horizontal-line p l)
  (lambda (t) (make-point  (+ (x-of p) (* l t)) (y-of p))))

