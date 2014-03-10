#include<simplecpp>

void dream(float n,float l){
	if(n==0) return;
	else{
		forward(l/4);left(90);dream(n-1,l/4);left(90);dream(n-1,l/4);left(90);dream(n-1,l/4);left(90);forward(3*l/4);
		right(90);
		forward(l);forward(-l/4);dream(n-1,l/4);right(90);dream(n-1,l/4);right(180);dream(n-1,l/4);left(90);
		forward(7*l/4);
		forward(-l/4);dream(n-1,l/4);right(90);dream(n-1,l/4);right(180);dream(n-1,l/4);left(90);
		forward(3*l/4);
		left(90);
		forward(l);forward(-l/4);dream(n-1,l/4);right(90);dream(n-1,l/4);right(180);dream(n-1,l/4);right(90);
		forward(-2*l);
	}
}
	
main_program{
	float n,l=100;
	cin>> n;
	turtleSim();
	dream(n,l);
	getClick();
}
	
