#include<simplecpp>

void command(int p,Turtle t1){
t1.forward(p);
}

main_program{
int n;
cin>>n;
initCanvas ("su",400,400);
Turtle t;
command(n,t);
getClick();
}
