//makes calander of a month given no. of days and first day
#include<simplecpp>
#include<string>
int main(){
	int days,dayi;
	string day;
	cout<<"enter no. of days";
	cin>>days;
	
	cout<<"first day is:";
	//getline(cin,day);
	cin>>day;
	if(day=="sunday")dayi=0;
	if(day== "monday") dayi=1;
	if(day== "tuesday") dayi=2;
	if(day== "wednes")dayi=3;
	if(day== "thurs") dayi=4;
	if(day== "fri")dayi=5;
	if(day== "sat")dayi=6;
	
	cout<<"s\t"<<"m\t"<<"t\t"<<"w\t"<<"t\t"<<"f\t"<<"s\t"<<endl;
	repeat(dayi) cout<<' '<<'\t';
	for(int n=1;n<=days;n++){
		cout<<n<<'\t';
		if((dayi+n)%7==0) cout<<endl;
	}
}
	
