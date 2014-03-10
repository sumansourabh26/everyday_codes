#include<iostream>
using namespace std;

int main(){

    try{
        int num1, num2;
        cout<<"enter first no. \n";
        cin>> num1;
        cout<<"enter second no. \n";
        cin>> num2;
        if(num2==0)
            throw 0;
        cout<<num1/num2;

    }catch(...){

    cout<<"the error ";
    }
}
