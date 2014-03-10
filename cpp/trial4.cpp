#include<simplecpp>
int main(){
initCanvas();
Polygon p[10];
for(int i=0; i<10; i++){
double pts[20][2];
int j=0;
for( ; j<20; j++){
int pt = getClick();
pts[j][0] = pt/65536;
pts[j][1] = pt % 65536;
if(j>0){
Line(pts[j-1][0], pts[j-1][1], pts[j][0], pts[j][1]).imprint();
if(pow(pts[j][0]-pts[0][0],2) + pow(pts[j][1]-pts[0][1],2) < 10)
break;
}
}
p[i].reset(0,0,pts,j);
p[i].setFill();
}
getClick();
}
