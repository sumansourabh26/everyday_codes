#include<simplecpp>
struct v3{
	double x,y,z;
	v3(double a,double b, double c){
		x=a;y=b;z=c;
	}
	v3(){
		x=0,y=0,z=0;
	}
	v3 sum( v3 w){
		return v3(x+w.x,y+w.y,z+w.z);
	}
};

int main(){
	v3 a=v3(), b=v3(21,24,56);
	cin>>a.x>>a.y>>a.z;
	v3 w=a.sum(b);
	cout<<w.x<<' '<<w.z;
}
	
