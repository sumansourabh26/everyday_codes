#include<simplecpp>
struct position{
	double x,y;
	position(){x=0;y=0;}
	position(double a,double b){
		x=a;y=b;
	}
	position operator +( position d ){
		position e(x+d.x,y+d.y);
		return e;
	}
	position operator -(position d ){
		position e(x-d.x,y-d.y);
		return e;
	}
	position operator *(position c, double d){
		position e(x*d, y*d);
		return e;
	}
};
int main(){
	initCanvas();
	position arrowpt[3];
	arrowpt[0]=position(10,39),arrowpt[1]=position(457,5),arrowpt[2]=position(45,54);
	Polygon arrow(0,0,arrowpt,3);
	arrow.imprint();
}
