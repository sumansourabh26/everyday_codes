#include<simplecpp>
#include<vector>
#include<algorithm>
double sqr(double a){
	return a*a;
}

int main(){
	double a,b;
	
	for( a=1;a<1000;a++){
		for( b=a+1;(b< (1000-a)) && (b>a);b++){
			if( sqr(a)+sqr(b)==sqr(1000-a-b)){
				cout<<"a = " <<a<<endl;
				cout<<"b = " <<b<<endl;
				cout<<"c = " <<1000 - a - b<<endl;
				break;
			}
			else continue;
		}
	}
}
