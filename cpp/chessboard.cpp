#include<simplecpp>
int gcd(int a,int b){
	int r=a%b;
	if(r==0) return b;
	if(r!=0) gcd(b,r);
}

main_program{
	int a,b;
	cin>> a>>b;
	cout<<gcd(a,b);
}
