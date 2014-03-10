#include<simplecpp>
void reverse( char *a, int n){
	if(n==0) return;
	else{
		cout<<a[n-1];
		reverse( a,n-1);
	}
}



main_program{
	int n;
	cout<<"enter no. of terms";
	cin>>n;
	char a[n];
	cout<<"enter your string with space between each consecutive characters";
	for(int b=0; b<n;b++){
		cin>>a[b];
	}
	reverse(a,n);
}
	
