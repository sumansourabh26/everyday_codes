#include<simplecpp>
int main(){
	int n;
	cout<<"enter the no. of eqn";
	cin>> n;
	cout<<"enter the entries\n";
	
	double entry[n][n+1];
	for(int row=0;row<n;row++){
		for(int col=0;col<n+1; col++){
			cin>> entry[row][col];
		}
	}
	int row3;
	int row1=0;
	while(row1<n-1){
		if(entry[row1][row1]!=0){
			for(int row2=row1+1; row2<n; row2++){
				for(int col2=0; col2<n+1;col2++){
					entry[row2][col2]=entry[row2][col2]-(entry[row2][row1]/entry[row1][row1])*entry[row1][col2];
				}
			}
			row1++;
		}
		else{
			for( row3=0;row3<n;row3++){
				if(entry[row3][row1]!=0){
					for(int col3=0;col3<n+1;col3++){
						swap(entry[row3][col3],entry[row1][col3]);
					}
					break;
				}
			}
			if(row3==n){
				cout<<"infi soln";
				break;
			}
		}
	}
	double x[n];
	for(int i=0;i<n;i++){
		x[i]=0;
	}
	x[n-1]=entry[n-1][n]/entry[n-1][n-1];
	for(int i=n-2; i>=0;i--){
		x[i]=entry[i][i+1];
		for(int j=n-1; j>i;j--){
			x[i]=x[i]-(entry[i][j])*x[i];
		}
		x[i]=x[i]/entry[i][i];
	}
	
	for(int j=0; j<n; j++){
		cout<<"x"<<j+1<<"="<<x[j]<<endl;
	}
}
	
	
	
