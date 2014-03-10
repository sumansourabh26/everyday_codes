
#include<simplecpp>
int main(){
	double x;
	cin>>x;
	
	double expx=1,term=1;
	
	for(double n=1;n<21;n++){
		term=(term*x)/n;
		expx=expx+term;
	}
	
	cout<<expx;
}
