#include<simplecpp>
int main(){
	int n;
	cout<<"no of points:";
	cin>>n;
	float point[n][2];
	for(int i=0;i<n;i++){
		cout<<"point("<<i<<"):";
		cin>>point[i][0]>>point[i][1];
	}
	
	int i=0,j,k,l=0;
	
	for(;i<n;i++){
		for(j=i+1;j<n;j++){
			for(k=j+1;k<n;k++){
				if((point[i][0]-point[j][0])/(point[i][1]-point[j][1])==(point[i][0]-point[k][0])/(point[i][1]-point[k][1])){
					cout<<"i"<<i<<endl;
					cout<<"j"<<j<<endl;
					cout<<"k"<<k<<endl;
					l=1;
					break;
				}
			}
			if(l==1) break;
		}
		if(l==1) break;
	}
	if(l==0) cout<<"no line found";
}
