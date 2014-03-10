#include<fstream>
#include<iostream>
using namespace std;

int main(){
    ofstream buckyfile;

    buckyfile.open("tuna.txt");

    buckyfile<<"I love ritu and ritu loves me\n";

    buckyfile.close();
}
