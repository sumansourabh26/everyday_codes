#include<simplecpp>
main_program{
	int i,n,a,b;
	cin>>n;
	b=n;
	for(i=0;n>0;i++){
		n=n/10;
	}
	
	repeat(i){
		a=b%10;
		b=(b-a)/10;
		cout<<a;
	}
}
