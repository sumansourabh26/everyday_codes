#include<simplecpp>
#include<vector>
void print(vector<int> v){
	for(unsigned int i=0; i<v.size();i++){
		cout<< v[i]<<' ';
	}
}
void read(vector<int> &v){
	for(unsigned int i=0; i<v.size();i++){
		cin>>v[i];
	}
}
int main(){
	vector<int> v(5); 
	read(v);
	write(v);
}
