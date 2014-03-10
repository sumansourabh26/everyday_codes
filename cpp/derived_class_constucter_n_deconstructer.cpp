#include<iostream>
using namespace std;

class mother{
public:
    mother(){cout<<"i am the mother constructor\n";
    }
    ~mother(){
        cout<<"mother deconstructed\n";
    }
};

class son:public mother{
public:
    son(){
        cout<<"i am the son constructor\n";
    }
    ~son(){
        cout<<"son destroyed\n";
    }

};

int main(){
        son chotu;

}
