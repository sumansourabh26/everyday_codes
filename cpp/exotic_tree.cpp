#include<simplecpp>

void tree(int height,float length,float angle,float shrinkage){
	
	if(height==0)
	return;	
	left(angle/2);
	forward(length);
	
	right(angle/2);
	tree(height-1,length*shrinkage,angle*shrinkage,shrinkage);
	
	left(angle/2);
	forward(-length);
	
	right(angle/2);
	forward(length);
	
	left(angle/2);
	tree(height-1,length*shrinkage,angle*shrinkage,shrinkage);
	right(angle/2);
	forward(-length);
	
	left(angle/2);
}


main_program{
	int height;
	turtleSim();
	left(90);
	cin>>height;
	tree(height,50,30,0.8);
	getClick();
	closeCanvas();
}
