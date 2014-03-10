#include<simplecpp>
int tree(int n, float length, float angle){
	if (n==1) return(0);
	if (n==2) return(0);
	if(n>2){
		right(angle/2);
		forward(length);
		
		left(angle/2);
		tree(n-1,length*(3.0/4.0),angle*(5.0/6.0));
		
		right(angle/2);
		forward(-length);
		
		left(angle);
		forward(length);
		right(angle/2);
		tree(n-2,length*(3.0/4.0),angle*(25.0/36.0));
		
		left(angle/2);
		forward(-length);
		
		right(angle/2);
	}
}

main_program{
	int n;
	cin>>n;
	turtleSim();
	penUp();
	right(90);
	forward(-200);
	penDown();
	tree(n,100.0,90.0);
	getClick();
}
