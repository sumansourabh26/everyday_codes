#include<simplecpp>
void setTrue(bool* table,int p){//set the value of all entries of "table" array true
	for(int i=0;i<p;i++) table[i]=true;
	return;
	}

void crossAllMultipleOfi(bool* table,int tablelength,int i){
	
	for(int j=2;i*j<=tablelength;j++) table[i*j]=false;	//crosses the  multiple of i
	return;
	}	
 void crossAllMultiple(bool* table,int p){//screen the uncrossed no's and then call oter function for crossing its multiples
	 for(int i=2;i<p;i++){
		 if(table[i]==true) crossAllMultipleOfi(table,p-1,i);
		 }
		 return;}
int printPrimes(bool* table,int p){int d=0;
	for(int i=2;i<p;i++){//finally print those no's ehich are uncrossed==primes
		if(table[i]==true){
			cout<<i<<endl;
			d++;}//also takes care of no of primes
			}
			return d;
		}
	
		 
int main(){
	int n;
	cout<<"n:";
	cin>>n;
	bool table[n+1];
	setTrue(table,n+1) ;
	crossAllMultiple(table,n+1);
	 int nP = printPrimes(table, n+1);
	 cout<<"____________________________";
	 cout <<endl<< "There are " << nP <<" primes.\n";
	 cout<<"____________________________";
	 return 0;
 }
	
