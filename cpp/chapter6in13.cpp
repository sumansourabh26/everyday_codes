#include<simplecpp>
main_program{
	int i,d,n,p;
	cin>>i;
	int j=i;
	int z=1;
	for(p=1;i>10;p++){
		i=i/10;
	}
	cout<<p<<endl;
	repeat(p-1){
		z=z*10;
	}
	cout<<z<<endl;
	
	while(j>0){
		d=j/z;
		cout<<d;
		j=j%z;
		z=z/10;
		n=n-1;
	}
}
	
	
