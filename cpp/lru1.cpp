#include<simplecpp>
void lru( int *a){
	int r;
	cout<<"asdf"<<endl;
	for(r=3;r<10;r++){
		if(a[2]!=a[r]){
			a[0]=a[r];
		}
	}
	cout<<a[0]<<a[1]<<a[3];
}

main_program{
	int a[10],b;
	for(b=0;b<10;b++){
		cin>>a[b];
	}
	lru( a);
}
