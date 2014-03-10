#include<simplecpp>
main_program{
	double r,fx,fxdash,xnew,x=1;
	cin>>r;
	while(abs(x*x*x-r)>0.0005){
		fx=x*x*x-r;
		fxdash= 3*x*x;
		x=x-(fx/fxdash);
	}
	cout<<x;
}
