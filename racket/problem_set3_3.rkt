#lang racket
;;;;;;;;;;Q3
(struct node(op ltree rtree) #:transparent)
(struct leaf (num) #:transparent)

(define ex (node '* (node '* (node '* (leaf 4)(leaf 6))
                          (node '+ (leaf 7)(leaf 9)))
                 (node '* (node '+ (leaf 3)(leaf 4))
                       (node '+ (leaf 4)(leaf 3)))))

(define (concat l) (foldr append `() l))

(define(convert t)
  (cond[(and(leaf?(node-ltree t))(leaf?(node-ltree t)))
        (list (leaf-num (node-ltree t))
              (node-op t)
              (leaf-num(node-ltree t)))]
       [(and(eq?(node-op t) (cadr(convert (node-ltree t)))) 
            (eq?(node-op t) (cadr(convert (node-rtree t)))))
        (concat(list(convert(node-ltree t) )
                    (list(node-op t))
                    (convert(node-rtree t))))]
       [(eq?(node-op t) (cadr(convert (node-ltree t))))
        (concat(list(convert(node-ltree t) )
                    (list(node-op t))
                    (list(convert(node-rtree t)))))]
       [(eq?(node-op t) (cadr(convert (node-rtree t))))
        (concat(list(list(convert(node-ltree t) ))
                    (list(node-op t))
                    (convert(node-rtree t))))]))