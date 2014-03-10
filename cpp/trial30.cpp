#include<simplecpp>

int main(){
	double max=-100000000,max2=-1000000,dummy;
	int n;
	cin>> n;
		if(n<2){
		cout<<"give at least two arguments";
		exit(1);}
	double term[n];
		
	for(int i=0; i<n;i++ ){
		cout<<"enter ur "<< i+1<<" term";
		cin>>term[i];
	}
		
	for(int i=0;i<n;i++){
		if(term[i]>max){
			dummy= max;
			max= term[i];
			max2=dummy;
		}
		else if((term[i]<max)&&(term[i]>max2)){
			max2=term[i];
		}
	}
	cout<<max2;
}
			
