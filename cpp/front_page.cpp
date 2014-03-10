#include<simplecpp>
int main(){
	initCanvas("ARCHERY",1300,700);
	
	Polygon rect(650,350,{{50,50},{50,-50},{-50,50},{-50,-50}},4);
	rect.imprint();
	getClick();
}
