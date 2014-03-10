(define (add-c x y c) 
  (cond ((and (= x 0)(= c 0)) y)
        ((and (= y 0) (= c 0)) x)
         (else ( define sum-single (add-single (remainder x 10) (remainder y 10) c))
  ( convert (add-c (quotient x 10) (quotient y 10) (quotient sum-single 10)) 
            (remainder sum-single 10)))))
(define (add-single a b c) 
  (+ a b c ))
(define (convert x y)
  (+(* x 10) y))
(define (add x y)
  (add-c x y 0))
    
  