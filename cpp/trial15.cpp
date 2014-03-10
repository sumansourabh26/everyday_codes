#include<simplecpp>

struct v3{
	double x,y,z;
	v3(double p,double q, double r){
		x=p, y=q,z=r;
	}
	
	v3()
	{ }
	
	v3 sum( v3 t){
		 
		return v3(t.x/x,t.y/y,t.z/z);
	}
};
int main(){
	v3 a=v3(1,2,3),d=v3(7,8,9),e;
	v3 b(4,5,6);
	cout<<"enter the value of e";
	cin>>e.x>>e.y>>e.z;
	
	v3 z=e.sum(a);
	
	cout<<z.x;
}
