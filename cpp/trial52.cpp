#include<iostream>
using namespace std;

class Stankfist{
public:
    Stankfist(){
        stinkyVar = 0;
        }
private:
    int stinkyVar;
    friend void stinkysfriend(Stankfist *sfo);


};

void stinkysfriend(Stankfist *sfo){
    sfo->stinkyVar = 99;
    cout<<sfo->stinkyVar;
};

int main(){
    Stankfist s;
    stinkysfriend(&s);
}
