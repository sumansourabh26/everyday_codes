#include<iostream>
using namespace std;

class Enemy{
protected:
    int power;


public:
    virtual void attack(){}
    void setpower(int i){
        power = i;
    }
};

class Ninja:public Enemy{
public:
    void attack(){
        cout<<"ninja attack"<< power<<endl;
    }
};

class Monster:public Enemy{
public:
    void attack(){
        cout<<"monster attack"<< power<<endl;
    }
};

int main(){
    Ninja n;
    Monster m;
    Enemy *e1 = &n, *e2 = &m;
    e1->setpower(20);e1->attack();
    e2->setpower(30);e2->attack();

}
