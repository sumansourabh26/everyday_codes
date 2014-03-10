#include<sstream>
int main(int argc,char** argv){
	double x,y;
	stringstream(argv[1])>>x;
	stringstream(argv[2])>>y;
	cout<<x*y<<endl;
}
