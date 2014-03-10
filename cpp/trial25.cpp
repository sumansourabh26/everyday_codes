#include<simplecpp>
#include<string>
#include<vector>
#include<algorithm>
int main( )
{ 
   using namespace std;   
	vector<int> v1,v2,v3;
	vector<int>::iterator itr;
	
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);
	for(itr=v1.begin();itr!=v1.end();itr++)
	cout<< *itr<<' ';
	cout<<endl;
	
	v2.assign(3,4);
	for(itr=v2.begin();itr!=v2.end();itr++)
	cout<< *itr<<' ';
	cout<<endl;
	
	v3.assign(v1.begin()+2,v1.end());
	for(itr=v3.begin();itr!=v3.end();itr++)
	cout<< *itr<<' ';
	cout<<endl;	
	
}
