#include<simplecpp>
main_program{
	long n,m,d;
	cin>>n;
	d=n;
	for(m=0;n>0;m++){
		n=n/10;
	}
	if(m==1) cout<<"11";
	else {
	while(true){
		long digit[m],x=0,i=d;
		for(x=0;i>0;x++){
			digit[x]=i%10;
			i=i/10;
		}
		for(x=0;(digit[x]==digit[m-x-1])&&x<m;x++);
		
		if(x==m){
		cout<<d;
		break;}
		else 
		d++;
		}
	}
}
