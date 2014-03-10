#include<iostream>

using namespace std;

int mod(int &x, int &y){
    if(y<x){
        return y;
    }
    else if(x | 0){
        return mod((2* mod(x/2 , y) + 1), y);
    }
    else{
        return mod((2* mod(x/2 , y)), y);
    }
}

int main(){
    cout<<mod(100,6);

}
