#include<iostream>
using namespace std;

int main(){
    int no;
    cin>>no;
    while(no--){
        int n,x;
        cin>>n>>x;
        if(x==0)
            cout<<"Airborne wins.\n";
        else
            cout<<"Pagfloyd wins.\n";
    }
}
