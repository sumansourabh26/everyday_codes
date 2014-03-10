(define (modexp x y n)
  (cond ((= y 0) 1)
        (else 
   (if ( even y) 
      (remainder (* (modexp x (quotient y 2) n) 
                  (modexp x (quotient y 2) n))
               n)
      (remainder (* x
                  (modexp x (quotient y 2) n) 
                  (modexp x (quotient y 2) n))
               n)))))
                 
  (define (even x) 
    ( if (= (remainder x 2)0) 
         #t
         #f))
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
 