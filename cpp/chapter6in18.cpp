#include<simplecpp>
main_program{
	int a=0,b;
	while(true){
		cin>>b;
		if(b==1000)
			break;
		if(a+b<0)
			continue;
		if(a+b>=b)
			a=a+b;
		if(a+b<b)
			a=b;
		
		}
		cout<<a;
	}
