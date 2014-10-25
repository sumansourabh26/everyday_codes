#include <iostream>

using namespace std;

long power000(long long n,long &m){
	if(n==1){
		return 10%m;
	}
	long long half = n/2;

	long x = power000(n/2,m);
	if(n%2 == 0){
		return (x*x)%m;
	}
	else{
		return (x*x*10)%m;
	}
}

long power111(long long n,long &m){
	if(n==1){
		return 1;
	}
	long long half = n/2;
	long x = power111(half,m);
	if(n%2 == 0){
		return (x*power000(half, m) + x)%m;
	}
	else{
		return (x*power000(n - half,m) + (x*10+1)%m)%m ;
	}
}

int main(){
	int count;
	cin>>count;

	while(count--){
		long long n;
		long m;
		cin>>n>>m;

		cout<< power111(n,m)<<endl;
	}
}