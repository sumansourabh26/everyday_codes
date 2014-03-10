#include<simplecpp>
struct v3{
	int x,y,z;
	/*v3(int k,int l,int m){
		x=k;y=l;z=m;
	}*/
	v3 sum(v3 a){
		v3 b;
		b.x=a.x+x;b.y=a.y+y;b.z=a.z+z;
		return b;
	}
};

int main(){
	v3 v={1,2,3}, w={4,5,6};
	v3 p=v.sum(w);
	cout<<p.x;
}
