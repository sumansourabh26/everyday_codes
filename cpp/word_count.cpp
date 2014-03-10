#include<simplecpp>
int main(){
	char chr[100];
	cin.getline(chr,100);
	if(chr[0]=' '){
		int j=1;
		for(int i=1;i<100;i++){
			if(chr[i]==0&&chr[i-1]!=0){
				j++;
			}
		}
		cout<<j;
	}
	
	if(chr[0]!=' '){
		int j=0;
		for(int i=1;i<100;i++){
			if(chr[i]==0&&chr[i-1]!=0){
				j++;
			}
		}
		cout<<j+1;
	}
}
