#include<fstream>
#include<iostream>
using namespace std;

int main(){
    ofstream buckysFile("suman.txt");
    if(buckysFile.is_open()){
        cout<<"the file is open";
    }
    buckysFile<<"suman";
    buckysFile.close();
}
