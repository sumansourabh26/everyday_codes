#include<simplecpp>
main_program{
	int n,alast=1, alast2=0, p;
	cin>>n;
	cout<<1<<",";
	repeat(n-1){
		p=alast+alast2;
		cout<<p<<",";
		alast2=alast;
		alast=p;
	}
}
