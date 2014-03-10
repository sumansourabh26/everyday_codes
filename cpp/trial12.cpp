#include<simplecpp>
#include<string>

int main(){
	string p="abc",q="defg";
	string r=p+q;
	cout<<p<<'\n'<<q<<'\t'<<r.length()<<endl;
	p[2]='1';q[0]=p[0];
	cout<<p<<'\n'<<q<<endl;
	int i = r.find("ab");cout<<i<< endl;// find from the beginning
int j = r.find("b",1); cout<<j<<endl;// find from position 1.
}
