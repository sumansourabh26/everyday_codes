//counts total no of words in a string
#include<simplecpp>

int main(){
	cout<<"enter ur sentence\n";
	string line;
	getline( cin,line);
	int n, word;
	if(line[0]==' '){
		for(word=0,n=1;line[n]!='\0';n++){
			if(line[n]!=' '&&line[n-1]==' ') word=word+1;
		}
	}
	else{
		for( word=1,n=1;line[n]!='\0';n++){
			if(line[n]!=' '&&line[n-1]==' ') word=word+1;
		}
	}
	cout<<word;
}
