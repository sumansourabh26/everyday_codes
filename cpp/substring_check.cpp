#include<simplecpp>

void check( string a, string b){
	int n=0;
	for(;n<6;n++){
		string c=a.substr(n,5);
		if(c==b) {
			cout<<"1\n";
			return;
		}
	}
	if(n==6) cout<<"0\n";
}
int main(){
	string stg[2][2];
	for(int n=0;n<2;n++){
		getline(cin,stg[n][0]);getline(cin,stg[n][1]);
	}
	
	for(int n=0;n<2;n++){
		check(stg[n][0],stg[n][1]);
	}
}

