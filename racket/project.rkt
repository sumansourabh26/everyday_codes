;#lang racket
#lang racket/gui


(define-syntax for 
  (syntax-rules ( : )
    [(for init : bexp : change : statements)
     (begin
       init
       (define(loop)
         (cond[bexp (begin
                      statements
                      change
                      (loop))]))
       (loop))]))

(define-syntax while
  (syntax-rules ( : )
    [ (while bexp : statements)
      (begin
        (define(loop)
          (cond[bexp statements
                     (loop)]))
        (loop))]))
(define (concat l) (foldr append `() l))

(define-syntax lc
  (syntax-rules (: <- @)
    [(lc exp : var <- lexp) (map (lambda (var) exp) lexp)]
    [(lc exp : @ guard) (if guard (list exp) `())]
    [(lc exp : @ guard qualifier ...) 
     (concat (lc (lc exp : qualifier ...) : guard))]
    [(lc exp : var <- lexp qualifier ...) 
     (concat (lc (lc exp :  qualifier ... ) : var <- lexp))]))

(define(make-2d-vector r c)
  (build-vector r (λ(x)(make-vector c #f))))
(define(vector-2d-ref vec r c)
  (vector-ref (vector-ref vec r) c))
(define(vector-2d-set! vec r c val)
  (vector-set! (vector-ref vec r) c val))

(define board%
  (class object%
    (init-field (row 9))
    (init-field (column 9))
    (init-field (tiger-list '()))
    (init-field (goat-list '()))
    (init-field (grid (make-2d-vector 9 9)))
    (super-new)
    
    (define/public (add2-tiger-list t)
      (set! tiger-list (cons 
                        t tiger-list)))
    (define/public (add2-goat-list t)
      (set! goat-list (cons t goat-list)))
    ))
(define(list-of-valid-postion)
  (remove* (list (cons 0 0)(cons 0 1)(cons 1 0)(cons 1 1)(cons 2 1)(cons 1 2)
                 (cons 0 7)(cons 0 8)(cons 1 7)(cons 1 8)(cons 2 7)(cons 1 6)
                 (cons 8 7)(cons 8 8)(cons 7 7)(cons 7 8)(cons 6 7)(cons 7 6)
                 (cons 8 0)(cons 7 1)(cons 7 0)(cons 6 1)(cons 8 1)(cons 7 2)
                 (cons 0 3)(cons 0 5)(cons 8 3)(cons 8 5)(cons 3 8)(cons 5 8)(cons 3 0)(cons 5 0))
           (lc (cons x y) : x <- (build-list 9 (λ(x)x)) 
               y <- (build-list 9 (λ(x)x)))))

(define my-board (new board%))

(define goat%
  (class object%
    (init pos-g)
    (init-field (pos pos-g))
    (super-new)
    
    (send my-board add2-goat-list this)
    (define/public (move-to new-pos)
      (set-field! pos this new-pos))
    (define/public (move change)
      (set-field! pos this (cons(+ (car pos)(car change))
                                (+ (cdr pos)(cdr change)))))))

(define tiger%
  (class object%
    (init pos-g)
    (init-field (pos pos-g))
    (super-new)
    (define pos-sum (+(car pos)(cdr pos)))
    
    (send my-board add2-tiger-list this)
    (define/public (move-to new-pos)
      (set-field! pos this new-pos))
    (define/public (move change)
      (set-field! pos this (cons(+ (car pos)(car change))
                                (+ (cdr pos)(cdr change)))))
    (define(can-eat goat) ; check whether that particular goat can be killed by the tiger or not
      (let*((goat-pos (get-field pos goat))
            (x-pos-g (car goat-pos))
            (y-pos-g (cdr goat-pos)))
        (cond[(= (car pos) 0) (and(= (vector-2d-ref(get-field grid my-board) 2 4) #f)
                                  (= x-pos-g 1)
                                  (= y-pos-g (+ 2 (/ (cdr pos) 2))))]
             [(= (car pos) 8) (and(= (vector-2d-ref(get-field grid my-board) 6 4) #f)
                                  (= x-pos-g 7)
                                  (= y-pos-g (+ 2 (/ (cdr pos) 2))))]
             [(= (cdr pos) 0) (and(= (vector-2d-ref(get-field grid my-board) 4 2) #f)
                                  (= y-pos-g 1)
                                  (= x-pos-g (+ 2 (/ (car pos) 2))))]
             [(= (cdr pos) 8) (and(= (vector-2d-ref(get-field grid my-board) 4 2) #f)
                                  (= y-pos-g 7)
                                  (= x-pos-g (+ 2 (/ (car pos) 2))))]
             [(= (car pos) 1) (and(= (vector-2d-ref(get-field grid my-board) 3 (- 8 (cdr pos))) #f)
                                  (= goat-pos (cons 2 4)))]
             [(= (car pos) 7) (and(= (vector-2d-ref(get-field grid my-board) 5 (- 8 (cdr pos))) #f)
                                  (= goat-pos (cons 6 4)))]
             [(= (cdr pos) 1) (and(= (vector-2d-ref(get-field grid my-board)(- 8 (car pos)) 3) #f)
                                  (= goat-pos (cons 4 2)))]
             [(= (cdr pos) 7) (and(= (vector-2d-ref(get-field grid my-board)(- 8 (cdr pos)) 5) #f)
                                  (= goat-pos (cons 4 6)))]
             [(even? pos-sum)(and (= 1 (+ (abs (- x-pos-g (car pos)))(abs (- y-pos-g (cdr pos)))))
                                  (= #f (vector-2d-ref(get-field grid my-board)
                                                      (- (* 2 x-pos-g)(car pos))
                                                      (- (* 2 y-pos-g)(cdr pos)))))]
             [(odd? pos-sum)(and (or(= 1 (abs (- x-pos-g (car pos))))(= 1 (abs (- y-pos-g (cdr pos)))))
                                 (= #f (vector-2d-ref(get-field grid my-board)
                                                     (- (* 2 x-pos-g)(car pos))
                                                     (- (* 2 y-pos-g)(cdr pos)))))])))
    (define/public (can-eat-list)    ; gives the list of goat that can be killed by the tiger
      (lc x : x <- (get-field goat-list my-board )
          @ (can-eat x)))
    
    (define (list-of-next-valid-pos)
      (if(even? pos-sum)
         (lc x : x <- (list-of-valid-postion)  @ (or(and (or(= 1 (abs(-(car x)(car pos))))
                                                            (= 1 (abs(-(cdr x)(cdr pos)))))
                                                         (not(vector-2d-ref (get-field grid my-board) (car x)(cdr x))))
                                                    (member x (map (λ(t)(get-field pos t)) (can-eat-list)))))
         (lc x : x <- (list-of-valid-postion)  @ (or(and (and(= 1 (abs(-(car x)(car pos))))
                                                             (= 1 (abs(-(cdr x)(cdr pos)))))
                                                         (not(vector-2d-ref (get-field grid my-board) (car x)(cdr x))))
                                                    (member x (map (λ(t)(get-field pos t)) (can-eat-list)))))))))

(define (list-of-next-valid-pos-overall)
  (concat(map (λ(tiger) (map (λ(p)(cons tiger p))
                             (send tiger can-eat-list)) 
                (get-field tiger-list my-board)))))


(define (alphabeta node depth alpha beta player)
  (cond [(or (= depth 0)(terminate? node))
         (evaluate node)]
        [(= player #t)
         (let* ((children list-of-next-valid-pos-overall))
           (define (f children)
             (begin(set! alpha (max alpha (alphabeta (set-field! pos (caar children)(cdar children))
                                                     (- depth 1) alpha beta #f)))
                   (cond[(null? children)alpha]
                        [(<= beta alpha)alpha]
                        [else(f (cdr children))])))
           (f children))]
        [(= player #f)
         (let* ((children list-of-next-valid-pos-overall))
           (define (f children)
             (begin(set! beta (min bata (alphabeta (car children)(- depth 1) alpha beta #f)))
                   (cond[(null? children)beta]
                        [(<= beta alpha)beta]
                        [else(f (cdr children))])))
           (f children))]))

(define (terminate? node)
  (or(send winning-board? node)(loosing-board? node)))
