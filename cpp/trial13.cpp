#include<simplecpp>
int main()
{
	string s1;
	int st=0,end;
	getline(cin,s1);
	string s2[5];
	for(int i=0;i<5;i++)
	{
		for(;s1[st]==' ';st++);
		for(end=st;s1[end]!=' '&&s1[end]!='\0';end++);
		s2[i]=s1.substr(st,end-st);
		st=end;
		cout<<s2[i]<<endl;
		if(s1[end]=='\0')
		break;
	}
}
		
		
	
	
