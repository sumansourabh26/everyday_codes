#include<simplecpp>

int main(){
	int i;
	cin>>i;
	int num[i];
	
	for(int j=0;j<i;j++){
		cin>>num[j];
	}
	
	for(int end=i-1;end>0;end=end-1){
		for(int j=1;j<=end;j++){
			if( num[j-1]>num[j]){
				//cout<<"no interchanged:"<<num[j-1]<<"and"<<num[j]
				swap(num[j-1],num[j]);
			}
		}
	}
	for(int j=0;j<i;j++){
		cout<<num[j]<<",";
	}
}
