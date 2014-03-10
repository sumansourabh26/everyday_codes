#include<simplecpp>
int gcd(int a,int b){
	
	if(a%b==0) return b;
	else return gcd(b,a%b);
}

main_program{
	int c,a,b;
	cin>> a>>b;
	c=gcd(a,b);
	cout<<c;
}
