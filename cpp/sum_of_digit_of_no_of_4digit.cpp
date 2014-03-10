#include<simplecpp>
main_program{
	int i,rem,sum=0;
	cin>>i;
	repeat(4){
		rem=i%10;
		i=(i-rem)/10;
		sum=sum+rem;
	}
	cout<<sum;
}
