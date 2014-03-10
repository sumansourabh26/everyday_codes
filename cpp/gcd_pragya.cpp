#include<iostream>
using namespace std;

int gcd(int n, int m){
	int div;
	if(n>m) {div=gcd(n,n%m);
		if (n%m==0)div=n;
		return div;}
	else if(n<m) {div=gcd(m%n,m); 
		if (m%n==0) div=m;
		return div;}
}

int main(){
	int n,m;
	cout<< "enter n ";
	cin>>n;
	cout<<"enter m ";
	cin>> m;
	int res2= gcd(n,m);
	cout<< "gcd is "<<res2<<endl;
}