#include<simplecpp>
int main(){

initCanvas();
Circle c[2]={0,0,0};
c[0].reset(4,4,4);
c[1].reset(9,9,9);
c[1].imprint();
}
