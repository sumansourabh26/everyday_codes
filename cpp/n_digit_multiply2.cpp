#include<simplecpp>
main_program{
	int n;
	cin>>n;
	int a[n],b[n],i,k,d,j,t[2*n];
	
	for(i=0;i<n;i++){
		cout<<"enter"<<i+1<<"digit";
		cin>>a[i];
	}
	for(i=0;i<n;i++){
		cout<<"enter"<<i+1<<"digit";
		cin>>b[i];
	}
	j=0;
	for(k=0;k<2*n;k++){
		for(i=0,d=0;d<=k;d++){
			t[k]=a[d]*b[k-d]+i;
			i=t[k];
		}
		t[k]=t[k]+j;
		j=t[k]/10;
		
		cout<<(t[k])%10<<endl;
	}
}
