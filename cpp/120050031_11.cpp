#include<iostream>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	unordered_map<string,int> mymap={};
	int total, dis=0, max_rep=0;
	cin>>total;
	string max_string = "{", input;
	int temphash;
	for(int i = 0; i<total; i++){
		cin>>input;
		temphash = ++mymap[input];
		
		if(temphash==1) dis++;
		
		if( temphash== max_rep){
			if(lexicographical_compare(input.begin(),input.end(),max_string.begin(),max_string.end())){
				max_string = input;
			}
		}
		else if(temphash > max_rep){
			max_rep = temphash;
			max_string = input;
		}         
	}
	cout<<dis<<endl<<max_string<<' '<<max_rep<<endl;
}
