#include<iostream>
using namespace std;

int main(){
    int no;
    cin>>no;
    while(no--){
        int input;
        cin>>input;
        cout<<input - (input/2)<<endl;
    }
}
