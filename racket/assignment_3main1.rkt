#lang racket
(struct body (mass posn velocity) #:transparent)
(struct gnode (mass posn subtrees) #:transparent)
(struct box (llx lly rux ruy) #:transparent)
(struct position (x y) #:transparent)

(define initialArea (box 0 0 1.0 1.0))

(define b1 (body 1 '(0.85 0.85) 3))
(define b5 (body 1 '(0.65 0.85) 3))
(define b6 (body 1 '(0.65 0.65) 3))
(define b7 (body 1 '(0.85 0.65) 3))

(define b2 (body 3 '(0.75 0.25) 3))
(define b3 (body 1 '(0.25 0.75) 3))
(define b4 (body 1 '(0.25 0.25) 3))


(define(buildtree-h pos half area bodies)
  (cond[(= 1 (length bodies)) bodies]
       [else(gnode (foldr (λ(x y)(+(body-mass x)y)) 0 bodies)
                   pos
                   (list (buildtree-h (list (+(first pos)half)(+(second pos)half)) 
                                      (/ half 2) 
                                      (box (+(box-llx area)half)(+(box-lly area)half) (box-rux area)(box-ruy area) )
                                      (filter (λ(x)(and(positive?(-(first (body-posn x))(+(first pos)half))) (positive? (-(second (body-posn x))(+(second pos)half)))))bodies))
                         (buildtree-h (list (+(first pos)half)(second pos)) 
                                      (/ half 2) 
                                      (box (+(box-llx area)half)(box-lly area) (box-rux area) (-(box-ruy area)half ))
                                      (filter (λ(x)(and(positive?(-(first (body-posn x))(+(first pos)half))) (negative?(-(second (body-posn x))(second pos)))))bodies))
                         (buildtree-h pos
                                      (/ half 2) 
                                      (box (box-llx area)(box-lly area) (-(box-rux area)half) (-(box-ruy area)half ))
                                      (filter (λ(x)(and(negative?(-(first (body-posn x))(first pos))) (negative?(-(second (body-posn x))(second pos)))))bodies))
                         (buildtree-h (list (first pos)(+(second pos)half)) 
                                      (/ half 2) 
                                      (box (box-llx area) (+(box-lly area)half) (-(box-rux area)half) (box-ruy area) )
                                      (filter (λ(x)(and(negative?(-(first (body-posn x))(first pos))) (positive?(-(second (body-posn x))(+(second pos)half)))))bodies))))]))