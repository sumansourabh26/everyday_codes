#include<simplecpp>
double detr(double a[][10],int n){
	if(n==1) return a[0][0];
	
	else{
		double det=0;
		for(int i=0;i<n;i++){
			double c[10][10];
			for(int j=0;j<10;j++){
				for(int k=0;k<10;k++){if(j==i)continue;
					else if(j==9) c[j][k]=0;
					else if(j<1) c[j][k]=a[j+1][k];
					else c[j][k]=a[j+1][k+1];if(k==9) c[j][k]=0;
				}
			}
			
			if(i%2==0) det+=detr(c,n-1)*a[0][i];
			else det-=detr(c,n-1)*a[0][i];
		}
		return det;
	}
}

int main(){
	int n;
	cin>>n;
	double a[10][10];
	for (int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	
	for(int i=9;i!=n-1;i--){
		for(int j=9;j!=n-1;j--){
			a[i][j]=0;
		}
	}
	
	cout<<detr(a,n);
}
