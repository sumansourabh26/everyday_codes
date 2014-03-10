#include<simplecpp>
#include<string>
int main(){
	cout<<"give your N";
	int n; cin>>n;
	
	int a[n];
	for(int i=0; i<n;i++) cin>>a[i];
	
	//int low=a[0];
	repeat(n){
		for(int i=1;i<n;i++){
			if(a[i]>a[i-1]){
				swap(a[i],a[i-1]);
			}
		}
	}
	int i=0,j=1;
	for(;i<5;j++){
		if(a[j]!=a[j-1]){
			i++;
		}
	}
	int max5=a[j];
	cout<<"5 max="<<max5;
	
	int distinct=0;
	for(int j=1;j<n;j++){
		if(a[j]!=a[j-1]){
			distinct++;
		}
	}
	cout<<distinct;
	cout<<"no. less than 5th larget="<<distinct-max5;
}
	
	
	

