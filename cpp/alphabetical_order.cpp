#include<simplecpp>
int compare( char a[],char b[]){
	for(int i=0;i<50;i++){
		if(a[i]>b[i]) return 1;
		if(a[i]<b[i]) return 0;
	}
	return 2;
}
int main(){
	int n;
	cout<<"enter the no. of words";
	cin>>n;
	char word[n][50];
	cout<<"enter the words in caps off\n";
	for(int i=0;i<n;i++){
		cin>>word[i];
	}
	
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-1;j++){
			if(compare(word[j],word[j+1])==1){
				char c[50];
				strcpy(c,word[j]);strcpy(word[j],word[j+1]);strcpy(word[j+1],c);
			}
		}
	}
	for(int i=0;i<n;i++){
			cout<<word[i]<<endl;
		}
}
