# include<iostream>

using namespace std;

int main(){
	int n, d;
	while(1){
		cin>>n>>d;
		if(n+d != 0){
			int f[n+1];
			f[1] = 1;
			for(int i = 2; i <= n; i++){
				f[i] = (f[i-1]+d-1)%i + 1;
			}
			cout<<n<<' '<<d<<' '<<f[n]<<endl;

		}
		else
			break;
	}
}