#include<iostream>
#include<cmath>
using namespace std;

bool isgood(int input){
    for(int i = sqrt(input/3); i>=0; i--){
        if(3*i*(i+1)==input){
            return true;
        }
    }
    return false;
}

int main(){
    while(true){
        int no;
        cin>>no;
        if(no==-1) break;
        if(isgood(no-1)){
            cout<<"Y"<<endl;
        }
        else cout<<"N"<<endl;
    }
}
