#include<simplecpp>
int main(){
	
	int  id[10],remain,i=-1,next=0;
	char intro;
	while(true){
		cout<<"who are you:";
		cin>>intro;
		if(intro=='b') break;
		
		if(intro=='d'){
			i=(i+1)%10;
			cout<<"enter ur id :";
			cin>>id[i];
			
		}
		
		if(intro=='c'){
			if(i==-1) {
				cout<<"no taxi\n";
			}
			else{
				cout<<"ur taxi id is"<<id[next]<<endl;
				next=(next+1)%10;
			}
		}
	}
}
