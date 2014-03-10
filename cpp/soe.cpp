#include<simplecpp>

void setrue(bool table[], int p){   //set all the bool array=true
	int r=p-1;
	for(int t=0;t<=r;t++){
		table[t]=true;
	}
}

void crossAllMultiple(bool table[],int t){      //cross out required no. i.e., set table[i]=false
	int p=t-1;
	for(int i=2;i<=p; i++){
		int r=i; 
		if(table[r]==true){
			for(r=r+i;r<=p;r=r+i){
				table[r]=false;
			}
		}
	}
}
																// at this point table[i] must be true only for i=0,1, and all primes.
int printPrimes(bool table[],int p){    
	int n=p-1, total=0;
	for(int r=2;r<=n;r++){
		if(table[r]==true){
			total++;
			cout<<r<<endl;
		}
	}
	return total;
}														// print uncrossed numbers and 
                                    // return the number of primes.
																
main_program{
	cout<<"enter ur no.";
	int n;
	cin>>n;
	bool table[n+1];
	setrue(table, n+1);
	crossAllMultiple(table,n+1);
	int np=printPrimes(table,n+1);
	cout<<"there are"<<np<<"primes.\n"<<"-----------";
}
