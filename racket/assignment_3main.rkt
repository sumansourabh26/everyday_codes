#lang racket

(define delta-t 4)

(define (concat l) (foldr append `() l))
(define-syntax lc
  (syntax-rules (: <- @)
    [(lc exp : var <- lexp) (map (lambda (var) exp) lexp)]
    [(lc exp : @ guard) (if guard (list exp) `())]
    [(lc exp : @ guard qualifier ...)
     (concat (lc (lc exp : qualifier ...) : guard))]
    [(lc exp : var <- lexp qualifier ...)
     (concat (lc (lc exp : qualifier ... ) : var <- lexp))]))

(struct body (mass posn velocity) #:transparent)
(struct gnode (mass posn subtrees) #:transparent)
(struct box (llx lly rux ruy) #:transparent)
(struct position (x y) #:transparent)

;The heart of the program is a function singleStep that takes a list of bodies, and
;produces a list of bodies with changed positions and velocities after delta-t. delta-t
;is a global variable.

(define (singleStep bodies)
  (let* ([tree (buildTree initialArea bodies)]
         [forces (calcForces initialArea tree bodies)])
    (movebodies bodies forces)))

(define initialArea (box 0 0 1.0 1.0))



(define (main l)
  (define (main-helper lnow i)
    (if (= i iter) exit
        (begin
          (draw lnow)
          (let ([lnext (singleStep lnow)])
            (main-helper lnext (+ i 1))))))
  (main-helper initialList 0))