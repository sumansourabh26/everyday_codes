#include<iostream>
using namespace std;

int gcd(int n, int m){
	int div;
	if(n==m){ return n;}
	else if(n>m) {div=gcd(n-m,m); return div;}
	else if(n<m) {div=gcd(m-n,n); return div;}
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
