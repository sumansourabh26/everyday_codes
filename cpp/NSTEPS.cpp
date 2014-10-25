#include <iostream>

using namespace std;

int main(){
	int n;
	cin>>n;

	while(n--){
		int x, y;

		cin>> x>>y;
		if(x==y){
			cout<< x*2 - x%2<<endl;
		}
		else if(y == x-2){
			cout<< (x-1)*2 - x%2<<endl;
		}
		else{
			cout<<"No Number"<<endl;
		}
	}
}