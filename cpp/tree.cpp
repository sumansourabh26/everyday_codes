#include<simplecpp>

void tree(int level,double centerx,double centery, double margin, double height){
	if(level==0) return;
	else{
		Line l1(centerx,centery, centerx+margin,centery-height);
		l1.imprint();
		tree(level-1,centerx+margin, centery-height, margin/2,height);
		
		Line l2(centerx,centery, centerx-margin,centery-height);
		l2.imprint();
		tree(level-1,centerx-margin, centery-height, margin/2,height);
	}
}

int main(){
	int level;
	cin>>level;
	initCanvas("ritu",500,400);
	double height=400/level, margin=125,centerx=250, centery=400;
	tree(level,centerx,centery, margin,  height);
	getClick();
}
