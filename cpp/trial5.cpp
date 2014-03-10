#include<simplecpp>
int main(){
	initCanvas("suman", 800,800);
	Polygon poly[10];
	double point[10][2];
	for(int j=0;j<10;j++){
		int i;
		for( i=0;i<10;i++){
			int gc=getClick();
			point[i][0]=gc/65536;
			point[i][1]=gc%65536;
			if(i>0){
				Line l(point[i][0],point[i][1],point[i-1][0],point[i-1][1]);
				l.imprint();
				if(point[i][0]==point[0][0]&&point[i][1]==point[0][1]) break;
			}
		}
		 poly[j].reset(0,0,point,i);
		poly[j].setFill();
	}
}
			
