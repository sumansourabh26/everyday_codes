#include<simplecpp>
main_program{
	int a,b=0,m,n,d;
	cout<<"enter ur d and n";
	cin>>d>>n;
	repeat(n){
		cin>>m;
		a=((d*m)+b)%10;
		b=(d*m+b)/10;
		cout<<a;
		}
	}
