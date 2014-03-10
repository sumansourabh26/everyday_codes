#lang racket
{
 State Next;
       ListIndex I;
       float V, Value, BestScore;
       List L;                   //successors of S at this level
       
       if ((N == 0) || Terminal(S))
       {
        Value = Eval(S);
              T[S] = Value;    //record values only to confirm cut offs
              
              if (Value > 100)  ;          //machine win
              return INT_MAX;
              else if (Value < -100) ;     //machine loss
              return  -INT_MAX;
              else if (Value == 0)    ;    //draw
              return 0;
              else
              return Value;
              }
       else
       {
        if (MachineMove(N))    ;     //program's move
           BestScore = Alpha;
           else
           BestScore = Beta;
           
           I = 1;
           while (I <= MaxNum)
           {
            Next = Child(S, I);
                 V = AlphaBeta(Next, N - 1, Alpha, Beta);
                 
                 if (MachineMove(N))      ; //program's move
                 {
                  BestScore = Max(V, BestScore);
                            Alpha = BestScore;
                            if (Alpha >= Beta)
                            {
                             BestScore = Beta;
                                       I = MaxNum;           //prune remaining S successors
                                       }
                            }
                 else
                 {
                  BestScore = Min(V, BestScore);
                            Beta = BestScore;
                            if (Alpha >= Beta)
                            {
                             BestScore = Alpha;
                                       I = MaxNum;           //prune remaining S successors
                                       }
                            }
                 I = I + 1;
                 }
           return BestScore;
           }
       }