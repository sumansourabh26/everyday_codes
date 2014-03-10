
#include<fstream>
#include<iostream>
using namespace std;

int main(){
    ofstream thefile("palyer.txt");

    cout<<"enter players id, name, and money\n";
    cout<<"press ctrl+Z to quit\n";

    int idnumber;
    string name;
    double money;

    while(cin>> idnumber>>name>>money){
        thefile<<idnumber<<' '<<name<<' '<<money<<endl;
    }

}
