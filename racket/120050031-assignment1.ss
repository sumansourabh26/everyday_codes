#lang racket
(require plot)
(plot-new-window? #t)
(plot-width 900)
(plot-height 900)
(define (draw curve)
  (plot (parametric
         (λ (t) 
           (let* ((c (curve t)))
             (vector (x-of c)
                     (y-of c))))
         0 1 #:width 1 #:samples 20000
         #:x-min -10 #:x-max  10
         #:y-min -10 #:y-max  10)))
(define (compose f g)
  (λ (x)
    (f (g x))))
(define (thrice f)
  (compose (compose f f) f))
(define (identity x) x)
(define (repeated f n)
  (if (= n 0)
      identity
      (compose f (repeated f (- n 1)))))
(define (make-point x y)
  (λ (bit)
    (if (zero? bit) x y)))
(define (x-of point)
  (point 0))
(define (y-of point)
  (point 1))

(define (unit-circle t)
  (make-point (sin (* 2 pi t))
              (cos (* 2 pi t)))) ;..................................circle of radius t and  centre origin

(define (unit-line-at y) ;.........................simply unit line at y=y
  (λ (t) (make-point t y)))

(define unit-line (unit-line-at 0));..........................simply unit line at y=0

(define (rotate-pi/2 curve)
  (λ (t)
    (let ((ct (curve t)))
      (make-point
       (- (y-of ct))
       (x-of ct)))))
(define(reflect-through-y-axis curve)
  (λ(t)(let((ct (curve t)))
         (make-point(-(x-of ct))
                    (y-of ct)))))

(define(sqrt-sqr x y);..............................gives squareroot of sum of squares of a and b
  (sqrt(+(sqr x)(sqr y))))

(define((translate a b)curve);................................translate graph by (a,b)
  (λ(t)(let((ct (curve t)))
         (make-point (+ a (x-of ct)) (+ b (y-of ct))))))

(define((scale rx ry)curve);.................................scale down x and y coordinates by rx and ry respectively
  (λ(t)(let((ct (curve t)))
         (make-point (/  (x-of ct)rx)(/ (y-of ct)ry)))))

(define(put-in-standard-position curve);..........................................put in standard position
  (let((x0 (x-of(curve 0)))
       (y0 (y-of(curve 0)))
       (x1 (x-of(curve 1)))
       (y1 (y-of(curve 1))))
    (λ(t)(let*((curve ((translate (* -1 x0)(* -1 y0))curve))
               (curve (cond[(and (= x1 0)(> y1 0)) (rotate-around-origin (/ pi 2) curve)]
                           [(and (= x1 0)(< y1 0)) (rotate-around-origin (-(/ pi 2))curve)]
                           [else(let ((slope (atan(/ y1 x1))))
                                  (if (> x1 0) ((rotate-around-origin slope) curve)
                                      (rotate-around-origin (+ pi slope) curve)))]))
               (ct (((scale ((sqrt-sqr x1 y1)(sqrt-sqr x1 y1)))curve)t)))
           (make-point (x-of ct) (y-of ct))))))
;....................................;
(define (str-line m c)
  (λ(t)
    (make-point t (+ c (* m t)))))

(define((rotate-around-origin theta)curve)
  (λ(t)(let((xt (x-of(curve t)))
            (yt (y-of(curve t)))
            (ct (cos theta))
            (st (sin theta)))
         (make-point (+(* xt ct)(* yt (- st))) 
                     (-(* yt ct)(* xt (- st))))))) ;...........................((rotate-around-origin theta)curve)

(define (connect-rigidly curve1 curve2)
  (λ (t)
    (if (<= t (/ 1 2))
        (curve1 (* 2 t))
        (curve2 (- (* 2 t) 1)))))
(define (connect-rigidlyo ratio curve1 curve2); connects and also consider division of points, imp in cactus, for no distortion
  (λ (t)
    (if (< t ratio)
        (curve1 (/  t ratio))
        (curve2 (/(- t ratio)(- 1 ratio))))))
(define(connect-ends curve1 curve2)
  (connect-rigidly curve1 ((translate (-(x-of (curve1 1))(x-of(curve2 0)))
                                      (-(y-of (curve1 1))(y-of(curve2 0))))
                           curve2)));............................................................(connect-ends curve1 curve2)
(define(connect-endso ratio curve1 curve2)
  (connect-rigidlyo ratio curve1 ((translate (-(x-of (curve1 1))(x-of(curve2 0)))
                                             (-(y-of (curve1 1))(y-of(curve2 0))))
                                  curve2)))
;....................gosper-curve=> syntex (draw((gosper-curve  5)unit-line)))...............................;
(define (gosperize curve)
  (let ((scaled-curve ((scale  (sqrt 2) (sqrt 2) ) curve)))
    (connect-rigidly
     ((rotate-around-origin (/ pi 4)) scaled-curve)
     ((translate .5 .5)
      ((rotate-around-origin (/ (- pi) 4)) scaled-curve)))))
(define ((gosper-curve level)curve)
  ((repeated gosperize level) curve))
;.............................................................................................

(define(horiline  length) ; makes horizontal line at x=z
  (λ(t)
    (make-point (* t length) 0)))
(define(horilineopp  length)
  (λ(t)
    (make-point (* (- 1 t) length) 0)))
(define(verline  length)
  (λ(t)
    (make-point 0 (* t length))))
(define(verlineopp length)
  (λ(t)
    (make-point 0 (* (- 1 t) length))))
;------------------cactus------------------------;
(define(square x y side)
  (λ(t)
    (cond[(> 0.25 t) (make-point x (+ y(* 4 t side)))] 
         [(> 0.5 t) (make-point (+ x(* 4 (- t 0.25)side)) (+ y side))]
         [(> 0.75 t) (make-point (+ x side)  (+ y(* side 4 (- 0.75 t))))]
         [else (make-point (+ x(* side 4(- 1 t))) y)])));.........................................(square x y side)

(define(cactus n)
  (let((scale-to (expt 3 (- n 1)))) 
    ((scale scale-to scale-to)((rotate-around-origin (/ pi 4))(cactush n (expt 3 n))))))

(define(cactush n side)
  (if(= side 1) (square 0 0 side)
     (let ((fig (cactush (- n 1) (/ side 3))))
       (connect-endso (/ 4 5)
                      (connect-rigidlyo (/ 3 4)
                                        (connect-rigidlyo (/ 2 3)
                                                          (connect-endso 0.5
                                                                         (horiline side) 
                                                                         ((translate side 0) 
                                                                          ((rotate-around-origin (- (/ pi 2)))fig )))
                                                          ((translate side side) fig))
                                        ((translate 0 side) ((rotate-around-origin (/ pi 2))fig )))
                      (verlineopp side)))))

;------------------koch-curve--------------------;
(define(remain curve)
  (let((remain-h ((scale  3 3) curve)))
    (connect-endso 0.75 (connect-endso (/ 2 3)(connect-endso 0.5 remain-h
                                                             ((rotate-around-origin (/ pi 3))remain-h))
                                       ((rotate-around-origin (-(/ pi 3)))remain-h))
                   remain-h)))

(define(koch-flakes level)
  (let ((third ((repeated remain level) unit-line)))
    (connect-endso (/ 2 3)(connect-endso 0.5 third
                                         ((rotate-around-origin (-(/ (* 2 pi) 3)))third))
                   ((rotate-around-origin (/ (* 2 pi) 3))third))))

