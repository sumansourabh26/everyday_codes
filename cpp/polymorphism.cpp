
#include<iostream>
using namespace std;

class Enemy{
protected:
    int attackPower;
public:
    void setAttack(int a){
        attackPower = a;
    }
};

class Ninja:public Enemy{
public:
    void attack(){
        cout<<"i am a ninja = "<< attackPower<<endl;
    }
};

class Monster:public Enemy{
public:
    void attack(){
        cout<<"monster will kill you = "<< attackPower<<endl;
    }
};


int main(){
    Ninja n;
    Monster m;
    Enemy *enemy1 = &n, *enemy2 = &m;
    enemy1->setAttack(20);
    enemy2->setAttack(30);
    n.attack();
    m.attack();

}
