#include <simplecpp>
main_program{
int n;
cout<<"n:";
cin>>n;
int j,e;
for( j=1,e=10; n/e>1;j++,e*=10);
int i=1,sum=0;
int digit[j*n],carry[j*n-1];
for(int b=0;b<j*n;b++)digit[b]=0;
for(int b=0;b<j*n-1;b++)carry[b]=0;
digit[0]=1;i=1;
while(i<=n){
for(int b=0;b<j*n;b++)digit[b]=digit[b]*i;
for(int b=0;b<j*n;b++){
digit[b]=digit[b]+sum;
int z=digit[b]%10;
sum=0;
for(int c=0,q=10;c<j*n-1;c++,q*=10){
carry[c]=digit[b]/q;
sum+=carry[c]*q/10;}
digit[b]=z;
}i++;
}
for(int b=j*n-1;b>=0;b--){
	cout<<digit[b];}cout<<" "<<endl;
}
}
