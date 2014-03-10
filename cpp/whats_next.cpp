#include<iostream>
using namespace std;
int main(){
    int a1,a2,a3;
    while(true){
        cin>>a1>>a2>>a3;
        if(!a1&&!a2&&!a3) break;
        else if(2*a2 == a1+a3){
            cout<<"AP "<<a3+a2-a1<<endl;
        }
        else if(a2*a2 == a1*a3){
            cout<<"GP "<<(a3*a2)/a1<<endl;
        }
    }
}
