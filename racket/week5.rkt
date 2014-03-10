#lang racket

(require  (lib "trace.ss"))

(define (foldr f id l)
  (if (null? l) id
      (f (car l) (foldr f id (cdr l)))))

(define (concat l) (foldr append `() l))

(define (append l1 l2) (foldr cons l2 l1))

(define (even n) (= 0 (remainder n 2)))

(define-syntax lc
  (syntax-rules (: <- @)
    [(lc exp : var <- lexp) (map (lambda (var) exp) lexp)]
    [(lc exp : @ guard) (if guard (list exp) `())]
    [(lc exp : @ guard qualifier ...) 
     (concat (lc (lc exp : qualifier ...) : guard))]
    [(lc exp : var <- lexp qualifier ...) 
     (concat (lc (lc exp :  qualifier ... ) : var <- lexp))]))



(define (qsort l)
  (if (null? l) `()
      (let ((lows (lc x : x <- (cdr l)  @ (<= x (car l))))
            (highs (lc x : x <- (cdr l)  @ (> x (car l)))))
        (append (qsort lows) (append(list (car l)) (qsort highs))))))

(define-syntax list-of-three
  (syntax-rules (@ <-)
    [(list-of-three b @ c ... <- d) `(b d c ...)])) 

(define (zip l1 l2)
  (cond [(null? l1) `()]
        [(null? l2) `()]
        [else (cons (cons (car l1) (car l2)) (zip (cdr l1) (cdr l2)))]))

(define (one-to-n n)
  (if (= n 0) `()
  (append (one-to-n (- n 1)) (list n))))


     
(define (queens n)
  (define (allsafe pos sol)
    (all (lc (safe (cons n pos) fullpos2) : fullpos2 <- (zip (one-to-n (- n 1)) sol))))
  (define (safe fullpos1 fullpos2)
    (not (or (= (cdr fullpos1) (cdr fullpos2))
             (= (abs (- (car fullpos1) (car fullpos2)))
                (abs (- (cdr fullpos1) (cdr fullpos2)))))))
  
  (if (= n 0) `(())
      (lc  (append sol (list pos)) : sol <- (queens (- n 1))  pos <- (one-to-n 8) @ (allsafe pos sol))))

(define (all l) (foldr (lambda (x y) (and x y)) #t l))


(struct posn (x y) #:transparent)

(struct node (val ltree rtree) #:transparent)
(struct nulltree () #:transparent)

; Now the following functions get defined automatically
; The constructors node and nulltree
; The selectors node-val, node-ltree, node-rtree
; The predicate node? nulltree?
   


(define nd1 (node 3 (nulltree) (nulltree)))
(define (print-node t)
  (begin (newline)
	 (print-node-helper t 0)
	 (newline)))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;my own printing routine 
(define (print-nulltree)
  (begin (newline)
	 (print-nulltree-helper 0)
	 (newline)))

(define (print-node-helper t indent)
  (begin (newline)
	 (printblanks indent)
	 (write-string "(node ")
         ;(printblanks 1 op)
         (display (node-val t))
         ;(newline op)
         (let ((t1 (node-ltree t)))
	   (cond ((node? t1) (print-node-helper t1 (+ indent 2)))
		 ((nulltree? t1)  (print-nulltree-helper (+ indent 2)))))
         (let ((t1 (node-rtree t)))
	   (cond ((node? t1) (print-node-helper t1 (+ indent 2)))
		 ((nulltree? t1)  (print-nulltree-helper (+ indent 2)))))
	 (write-char #\)) 
	 ;(newline op) 
	 ))


(define (print-nulltree-helper indent)
  (begin (printblanks 1 )
	(write-string "N")))

(define (printblanks indent)
  (if (= indent 0) `()
      (begin
	(write-char #\space )
        (printblanks (- indent 1)))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;An example tree

(define t4 (node 2 
                 (node 1 (nulltree) (nulltree))
                      (node 3 (nulltree) (nulltree))))
(define t6 (node 6 (nulltree) (nulltree)))
(define t7 (node 2  (node 7 (nulltree) (nulltree))
                 (node 9 (nulltree) (nulltree))))
(define t8 (node 8 (node 7 (nulltree) (nulltree))
                 (node 9 (nulltree) (nulltree))))  
(define t10 (node 12 (node 11 (nulltree) (nulltree))
                  (node 13 (nulltree) (nulltree))))
(define t11 (node 16 (node 15 (nulltree) (nulltree))
                  (node 17 (nulltree) (nulltree))))
(define t9 (node 14 t10 t11))
(define t3 (node 10  t8 t9))
(define t5 (node 5 (nulltree) (nulltree)))
(define t2 (node 4  t4 t5))
(define t1 (node 6 t2 t3))

(define (flatten t)
  (if (nulltree? t) `()
      (append (flatten (node-ltree t)) (list (node-val t)) (flatten (node-rtree t)))))

(define (insert x t) 
  (cond ((nulltree? t) (node x (nulltree) (nulltree)))
	((<= x (node-val t)) (node (node-val t) 
                                   (insert x (node-ltree t))
                                   (node-rtree t)))
        ((> x (node-val t)) (node (node-val t)
                                  (node-ltree t)
                                  (insert x (node-rtree t))))))


(define (search x t) 
  (cond ((nulltree? t) #f)
        ((= x (node-val t)) #t)
	((<= x (node-val t)) (search x (node-ltree t)))
        ((> x (node-val t)) (search x (node-rtree t)))))


(define (createtree set) 
  (if (null? set) (nulltree)
      (let* ([l (lc x : x <- (cdr set) @ (<= x (car set)))]
             [r (lc x : x <- (cdr set) @ (> x (car set)))])
	(node (car set) (createtree l) (createtree r)))))

(define (delete x t)
  (cond ((nulltree? t) t)
        ((= x (node-val t)) 
	 (join (node-ltree t)
	       (node-rtree t)))
	((< x  (node-val t)) 
	 (node (node-val t)
               (delete x (node-ltree t))
               (node-rtree t)))      
        ((> x  (node-val t)) 
	 (node (node-val t)
               (node-ltree t)
               (delete x (node-rtree t))))))

(define (join lt rt)
  (cond ((nulltree? rt) lt)
        ((nulltree? lt) rt)
	(node (rightmost lt) (readjust lt) rt)))

;; Important point, since the left subtree may contain values equal to
;; the root,  the rightmost of the  left subtree should  be hoisted at
;; the root

(define (rightmost t)
  (if (nulltree? (node-rtree t)) (node-val t)
      (rightmost (node-rtree t))))

(define (readjust t)
  (if (nulltree? (node-rtree t)) (node-ltree t)
      (node (node-val t)
            (node-ltree t)
	    (readjust (node-ltree t)))))

(define (reflect t)
  (cond ((nulltree? t) t)
        (else (node (node-val t)
                         (reflect (node-rtree t))
                         (reflect (node-ltree t))))))


(struct gnode (val lst) #:transparent)    

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

; This is the implementation of Huffman coding scheme. As explained in
; the class, in this scheme characters have varying length codes. The
; more frequent the character, the shorter is its code.


; The  running example  that we  shall  take has  messages having  the
; following characters  with the corresponding  frequencies: A-9, B-3,
; C-1, D-1, E-1, F-1, G-1, H-1.

; A possible tree representing Huffman encoding is 

;                          .                 A - 0
;                        /  \                B - 100
;                       A    .               C - 1010
;                          /   \             D - 1011
;                        .      .            E - 1100
;                       /\     / \           F - 1101
;                      B .    .   .          G - 1110
;                       / \  /\  /\          H - 1111
;                     C   D E F G  H                   

; To represent such a tree we define the following structure:

(struct bnode (ltree rtree) #:transparent)
(struct leaf (val) #:transparent)

;In terms of this structure let us encode the huffman tree above

(define example-huffman (bnode 
			 (leaf 'A)
			 (bnode 
			  (bnode (leaf 'B)
				     (bnode (leaf 'C)
						(leaf 'D)))
			  (bnode 
			   (bnode (leaf 'E)
				      (leaf 'F))
			   (bnode (leaf 'G)
				      (leaf 'H))))))


;________________________________________________________________

; The decode function takes a list of bits and a huffman tree and
; produces a list of characters

(define (decode t l)
  (define (decode-helper t1 l)
    (cond ((leaf? t1) (if (null? l) (list (leaf-val t1))
                         (cons (leaf-val t1)  (decode-helper t l))))
          ((null? l) (error "Ill formed input string"))
          ((= (car l) 0) (decode-helper (bnode-ltree t1) (cdr l)))
          ((= (car l) 1) (decode-helper (bnode-rtree t1) (cdr l)))))
  (if (null? l) `()
      (decode-helper t l)))

;(decode example-huffman '(0 1 0 0 0 0 0 0 0 0 0 0 ))

;Value 1: (a b a a a a a a a a)


;________________________________________________________________

;The encode function does just the opposite. It takes a tree and a
;list of characters and converts into a list of bits. To do this it
;first converts the tree into a lookup table and searches in the
;table. For the tree above it generates the following table:
;  ((A 0) (B 1 0 0) (C 1 0 1 0) ...  (H 1 1 1 0))


; transform converts the tree into a lookup table

;(define (transform t)
;  (cond ((leaf? t) (list (list (leaf-val t))))
;        (else (huffmerge (transform (bnode-ltree t))
;                         (transform (bnode-rtree t))))))

;(define (huffmerge l1 l2)
;  (cond ((null? l1) (map insert-1 l2))
;        ((null? l2) (map insert-0 l1))
;        ((<= (length (car l1)) (length (car l2))) 
;         (cons (insert-0 (car l1)) (huffmerge (cdr l1) l2)))
;        ((> (length (car l1)) (length (car l2))) 
;         (cons (insert-1 (car l2)) (huffmerge l1 (cdr l2))))))
;
;(define (insert-0 l)
;  (cons (car l) (cons 0 (cdr l))))
;
;(define (insert-1 l)
;  (cons (car l) (cons 1 (cdr l))))

(define (transform t)
  (define (transform-helper l t)
    (cond ((leaf? t) (list (cons (leaf-val t) (reverse l))))
	  (else (huffmerge (transform-helper (cons 0 l)  (bnode-ltree t))
			   (transform-helper (cons 1 l)  (bnode-rtree t))))))
  (transform-helper `() t))


(define (huffmerge l1 l2) 
  (cond ((null? l1) l2)
	((null? l2) l1)
	((<= (length (car l1)) (length (car l2))) 
	 (cons (car l1) (huffmerge (cdr l1) l2)))
	(else (cons (car l2) (huffmerge l1 (cdr l2))))))

; The function encode can now be written as:
 
(define (encode t l) (concat (encode-helper l (transform t))))

(define (encode-helper l tbl)
  (define (lookup x  tbl)
    (if (eq? x (caar tbl)) (cdar tbl)
	(lookup x (cdr tbl))))
  (map (lambda (x) (lookup x tbl))  l))

;(define (concat l) (foldr append `() l))


; Now we show how the Huffman tree is obtained from a list giving the
; relative frequencies of occurrence of different characters. We also
; assume that the list is sorted in ascending order of the
; frequencies. This means that in our case the following list could be
; given: ((H 1) (G 1) (F 1) (E 1) (D 1) (C 1) (B 3) (A 9)). Then we
; shall merge in the manner described in the class.

; Following a suggestion in the class, we shall work with binary
; trees. At any point of time the list will contain pairs whose first
; component is a binary tree, and the second component is a number
; representing frequency.
 
; first let us convert the initial list into a list of (binary-tree
; frequency) pairs.

(define (convert-initial-list l) 
  (map (lambda (x) (cons (leaf (car x)) (cdr x))) l))

(define initial-list (list (cons 'H 1) (cons 'G  1) 
                           (cons 'F  1) (cons 'E  1) 
                           (cons 'D  1) (cons 'C  1) 
                           (cons 'B  3) (cons 'A  9)))


; Now given an initial list of (binary-tree weight) pairs, we should
; repeatedly do the following till we get a singleton list:
; a. combine the first two trees in the list
; b. insert the combination in the right place
 

; The  function combine combines  two pairs  (t1 w1)  and (t2  w2) and
; makes the pair (t w1+w2), where t has t1 and t2 as its subtrees.

(define (combine p1 p2) 
  (cons (bnode (car p1) (car p2)) 
	(+ (cdr p2) (cdr p1))))

; a function  insert which,  given a (binary-tree  weight) pair  and a
; list of such pairs, insert the tree in the right place

;(define (insert p l) 
;  (append (takewhile (lambda (x) (< (cdr x) (cdr p))) l) 
;	  (list p)
;	  (dropwhile (lambda (x) (< (cdr x) (cdr p))) l)))

(define (dropwhile p l) 
  (if (null? l) `() 
      (if (p (car l)) (dropwhile p (cdr l)) l)))

(define (takewhile p l) 
  (if (null? l) `()
      (if (p (car l)) (cons (car l) (takewhile p (cdr l)))
	  `())))

			    
; combine the functions above into one called combine-and-insert

(define (combine-and-insert l) 
  (insert (combine (car l) (cadr l)) (cddr l)))
 
;we have to do combine-and-insert till the list becomes a singleton

(define (singleton? l) (null? (cdr l)))

; Now let us write a function which applies a function f repeatedly
; till a condition is met

(define (until f p x) 
  (if (p x) x (until f p (f x))))

;Now we can write the function maketree which converts an initial list
;of (char weight) pairs to a huffman tree

(define (huffman l)  
  (caar (until  combine-and-insert 
		singleton? 
		(convert-initial-list l))))


; Asexplained in the class, the tree that you get using the algorithm 
; looks like this: 


;                               .             A - 1
;                             /  \            B - 011
;                            .    A           C - 0101
;                          /   \              D - 0100
;                        .      .             E - 0011
;                       /\     / \            F - 0010
;                      .  .    .  B           G - 0001
;                    / \  /\  /\              H - 0000
;                   H  G F E D  c

; (define example-huffman (make-bnode (make-bnode 
; 				    (make-bnode 
; 				     (make-bnode (make-leaf 'H)
; 						(make-leaf 'G))
; 				     (make-bnode (make-leaf 'F)
; 						(make-leaf 'E)))
; 				    (make-bnode (make-bnode (make-leaf 'D)
; 							  (make-leaf 'C))
; 					       (make-leaf 'B)))
; 				   (make-leaf 'A)))
; 1 ]=> (transform example-huffman)
; Value 67: (('H (0 0 0 0)) ('G (0 0 0 1)) ('F (0 0 1 0)) ('E (0 0
; 1 1)) ('D (0 1 0 0)) ('C (0 1 0 1)) ('B (0 1 1)) ('A (1)))
;
; This is a source of inefficiency because A which is a frequent
; character appears at the end. The two appends - (append l '(0)) and
; (append l '(0)) in transform-helper are also sources of inefficiency

; To modify this, change transform to


