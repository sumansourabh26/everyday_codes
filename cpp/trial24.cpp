#include<simplecpp>
class v3{
	protected: double x,y,z;
	public:
	v3(double a,double b,double c){
		x=a,y=b,z=c;
		//V3 operator+(const V3 rhs){
			//return v3( rhs 
		}
	};
class mv3:public v3{
	public:
	mv3(double x,double y, double z) :v3(x,y,z){}
	double dot(mv3 num){
		return num.x*x+num.y*y+num.z*z;
	}
};

int main(){
	mv3 a(1,2,3), b(2,3,4);
	cout<<a.dot(b);
}
	
		
