#include<iostream>
using namespace std;

class hannah{
private :
    int h;
public:
    hannah(int a){
        h = a;
    }
    void printcrap(){
        cout<<"h = "<< h << endl;
        cout<<"h = "<< this->h << endl;
        cout<<"h = "<< (*this).h << endl;
        cout<<(this);
        }
};
int main(){
    hannah p(24);
    p.printcrap();
}

