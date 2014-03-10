#include<iostream>
using namespace std;

class mother{
public:
    int
    mother(){}

    void sayname(){
        cout<<"i am a robnertsq\n";
    }
};

class son:public mother{
public:
    son(){}

};

int main(){
        son chotu;
        chotu.sayname();
}
