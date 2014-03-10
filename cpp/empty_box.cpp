#include<iostream>
using namespace std;

int main(){
	cout<<"program begin\n";
	int no_of_input;
	cin>>no_of_input;
	int n,k,t,f;
	int temp;
	while(no_of_input--){
		cin>>n>>k>>t>>f;
		temp = (f-n)/(k-1);
		cout<<temp*k + n<<endl;
	}
}
