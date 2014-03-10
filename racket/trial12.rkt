#lang racket
(define Computer 'O)
;Define end-game values
(define Win 1)
(define Loss -1)
;Move vetor, move are optimally ordered allowing for better pruning should we use it.
(define moves (vector 4 0 2 6 8 1 3 5 7))
(define TIE 0)
;Board representations
(define player_board 	(vector 0 0 0 0 0 0 0 0 0))
(define computer_board 	(vector 0 0 0 0 0 0 0 0 0))
;Variable to hold the best move we found in our search
(define best_move 0)

;win states
(define top_row_win (vector 1 1 1 0 0 0 0 0 0))
(define middle_row_win (vector 0 0 0 1 1 1 0 0 0))
(define bottom_row_win (vector 0 0 0 0 0 0 1 1 1))
(define top_left_bottom_right_win (vector 1 0 0 0 1 0 0 0 1))
(define top_right_bottom_left_win (vector 0 0 1 0 1 0 1 0 0))
(define col1_win (vector 1 0 0 1 0 0 1 0 0))
(define col2_win (vector 0 1 0 0 1 0 0 1 0))
(define col3_win (vector 0 0 1 0 0 1 0 0 1))




;Make a move for the specified player by updating the index value for their board array
;Make sure the move is legal, return 0 otherwise
(define (make-move player place)
  (begin
    
    
    (if (= (vector-ref computer_board place) 1)
        0
        (if (= (vector-ref player_board place) 1)
            0
            (if (= player 0)
                (begin (vector-set! computer_board place '1) 1)
                (if (= player 1)
                    (begin (vector-set! computer_board place '1)) 1)
                    )))))

;Undo a move we made
;Due to the way I am storing boards and then setting next moves, they must be un-done once a value has been established.
(define (undo-make-move player place)
  (begin
    
    (if (= player 0)
        (vector-set! computer_board place '0)
        (vector-set! player_board place '0)
        
        )
    ))



;Very simple evaluation function, if specified player has won, return true
;Otherwise false
(define (eval_board player)
  (begin
    (if (= player 0)
        (if (equal? computer_board top_row_win)
            1
            (if (equal? computer_board middle_row_win)
                1
                (if (equal? computer_board bottom_row_win)
                    1
                    (if (equal? computer_board top_left_bottom_right_win)
                        1
                        (if (equal? computer_board top_right_bottom_left_win)
                            1
                            (if (equal? computer_board col1_win)
                                1
                                (if (equal? computer_board col2_win)
                                    1
                                    (if (equal? computer_board col3_win)
                                        1
                                        0
                                        
                                        ))))))))
        
        (if (equal? player_board top_row_win)
            1
            (if (equal? player_board middle_row_win)
                1
                (if (equal? player_board bottom_row_win)
                    1
                    (if (equal? player_board top_left_bottom_right_win)
                        1
                        (if (equal? player_board top_right_bottom_left_win)
                            1
                            (if (equal? player_board col1_win)
                                1
                                (if (equal? player_board col2_win)
                                    1
                                    (if (equal? player_board col3_win)
                                        1
                                        0
                                        
                                        ))))))))
        
        
        )
    )
  )

;Test for a tie
;Not used, just use depth
(define (is_tie)
  0
  )

;Min portion of our minimax
(define (minval depth)
  (define minVal 1)
  (define retval 1)
  (if (= (eval_board 1) 1)
      -1
      (if (= (eval_board 0) 1)
          1
          (if (>= 9 depth)
              0
              (let loop ((n 0))
                (if (< n (vector-length moves))
                    (begin
                      (if ( (make-move 1 (vector-ref moves n)) 1)
                          (begin
                            retval = (maxval (+ depth 1))
                            (if (<= retval minVal)
                                (set minVal retval)
                                (undo-make-move 1 (vector-ref moves n))
                                )
                            ))
                      (loop (+ n 1)))
                    ) 
                minVal
                )
              )
          ;move check   
          
          
          )))

;Maximizing function for our Minimax search
(define (maxval depth)
  (define maxVal -1)
  (define retval 1)
  (write 'inmax)
  (if (= (eval_board 1) 1)
      -1
      (if (= (eval_board 0) 1)
          1
          (if (>= depth 9)
              0
              (let loop ((n 0))
                (if (< n (vector-length moves))
                    (begin
                      (if (= (make-move 0 (vector-ref moves n)) 1)
                          (begin
                            retval = (minval (+ depth 1))
                            (if (> retval maxVal)
                                (set! best_move (vector-ref moves n))
                                )
                            (if (> retval maxVal)
                                (set! maxVal retval)
                                (undo-make-move 0 (vector-ref moves n))
                                )))
                      
                      (loop (+ n 1)))
                    )
                maxVal
                )
              ))))


(define (play_game)
  (begin
    (maxval 0)
    (write best_move)
    
    )
  )




;Test method, will eventually display the board in the console
(define (display-board)
  (begin
    (write computer_board)
    (write player_board)
    )
  )