
#include<fstream>
#include<iostream>
using namespace std;

int main(){
    ifstream thefile("player.txt");
    int id;
    string name;
    double money;
    while(thefile>> id>>name>>money){
        cout<< id<<','<<name<<','<<money<<endl;
    }
}
