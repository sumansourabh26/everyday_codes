#lang racket

(define day 0)
(define gl-no. 0)
(define boy-no. 0)
(define (best-match (boys-list)
                    (gls-list))
  (define boy-cross (make-vector (length gl-list) '()))
  (define gl-has-option (make-vector (length boys-list) '()))
  
  (if(all-true gl-has-ption) (begin(display gl-has-option)
                                   (set! day 0))
     (begin (vector-map (λ(gl-at-glno.)
                          (
                          gl-has-option )