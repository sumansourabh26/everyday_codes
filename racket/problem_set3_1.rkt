#lang racket
(struct dir (info fdlist) #:transparent)
(struct file (info contents) #:transparent)
(define (concat l) (foldr append `() l))

(define thistree
  (dir
   (cons "as" 1024)
   (list (dir
          (cons "cs613" 1024)
          (list (file (cons "quiz" 4246) "junk")
                (file (cons "tut" 7226) "junk")
                (dir (cons "2004" 1024)
                     (list (file (cons "quiz" 576) "junk")
                           (file (cons "tut" 345) "junk")))))
         (dir (cons "cs152" 1024)
              (list (file (cons "quiz1" 4532) "junk")
                    (file (cons "quiz2" 1234) "junk")
                    (file (cons "tut" 1223) "junk")))
         (dir (cons "cs154" 1024)
              (list (file (cons "tut1" 459) "junk")
                    (file (cons "tut2" 782) "junk"))))))

(define(present dirlist name)
  (let((a (car dirlist)))
    (cond[(dir? a)(if(eq?(car(dir-info a))name) a (present (cdr dirlist) name))]
         [(file? a)(present (cdr dirlist) name)])))

(define p '("as" "cs613" "2004"))
(define(findtree t pathname)
  (cond[(null? (cdr pathname)) t]
       [else (findtree (present (dir-fdlist t) 
                                (cadr pathname))(cdr pathname))]))

(define (ls t pathname)
  (dir-fdlist(findtree t pathname)))

(define(size t pathname)
  (cdr(dir-info(findtree t pathname))))

(define(delete t pathname)
  