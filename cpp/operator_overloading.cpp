
#include<iostream>
using namespace std;

class ritu{
public:
    int x,y,z;
    ritu(int a, int b, int c){
        x = a;
        y = b;
        z = c;
    }
    ritu operator+(ritu b){
        ritu a(x+ b.x, y+ b.y, z+ b.z);
        return a;
    }

};

int main(){
    ritu v(1,2,3), n(100,101,102);
    ritu c = v+n;
    cout<<c.x;

}
