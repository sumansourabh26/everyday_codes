#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(){
    bool found = false;
    int x;
    while(true){
        cin>>x;
        if(!found){
            cout<<x<<endl;
        }
        if(x==42)break;
    }
}
