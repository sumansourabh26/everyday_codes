#include<iostream>
using namespace std;

int gcd(int x, int y){
    if(y==0){
        return x;
    }
    else
        return gcd(y, x%y);
}

int main(){
    int no_of_input;
    cin>>no_of_input;
    int a,b,c;
    for(int i = 0; i<no_of_input;i++){
        cin>>a>>b;
        c = gcd(a,b);
        cout<<b/c<<' '<<a/c<<endl;
    }
}
