#include<iostream>
using namespace std;

int main(){
	int a[5],max=0,max2=0,n=0;

	cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4];
	for(n=0;n<5;n++){
		if(a[n]>max){
			max2=max;
			max=a[n];
		}
		else if(a[n]<max2);
		else{
			max2=a[n];
		}
		cout<<max2;
	}
	cout<<max2;
}
