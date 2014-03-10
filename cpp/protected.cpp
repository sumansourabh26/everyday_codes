#include<iostream>

using namespace std;

class Mother{
public :
    int publicv;
protected:
    int protectedv;
private:
    int privatev;
};

class Daughter : public Mother{
public:
    void dosomething(){
        privatev = 1;
    }
};

int main(){
    Daughter tina;
    tina.dosomething();
}
