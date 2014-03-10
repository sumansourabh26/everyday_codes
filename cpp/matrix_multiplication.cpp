#include<simplecpp>


int main(){
	int r1,r2,c1,c2;
	cout<<"enter ur constants r1,c1,r2 and c2 respectively\n";
	cin>>r1>>c1>>r2>>c2;
	if(c1!=r2){
		cout<<"invalid";
	}
	else{
		double mat1[r1][c1], mat2[r2][c2];
		
		
		for( int i=0 ; i<r1;i++){
			for(int j=0; j<c1; j++){
				cin>>mat1[i][j];
			}
		}
		for( int i=0 ; i<r2;i++){
			for( int j=0; j<c2; j++){
				cin>>mat2[i][j];
			}
		}
		
		for(int i=0;i<r1;i++){
			for(int j=0;j<c2;j++){
				double sum=0;
				for(int p=0;p<c1;p++){
					sum=sum+mat1[i][p]*mat2[p][j];
				}
				cout<<sum<< " ";
				if(j==c2-1) cout<<endl;
			}
		}
	}
}
