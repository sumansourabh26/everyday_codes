#include<simplecpp>

char compare(char a[], char b[]){
	int i=0;
	
	for(;;i++){
		
		if(a[i]==b[i]) continue;
		if(a[i]<b[i]) return('<');
		if(a[i]>b[i]) return('>');
	}
}

int main(){
	cout<<"cutiya\n";
	char a[10],b[10];
	cin>>a>>b;
	cout<<compare(a,b)<<endl;
}
