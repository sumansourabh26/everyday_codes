#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector<bool> isprime(1000000000,true);
    isprime[0]=0;
    isprime[1]=0;
    for(int i=2;i<1000000000;i++){
        if(isprime[i] == -1){
            isprime[i]=i;
            for(int j=2;(j*i)<1000000000 ;j++){
                if(isprime[i*j] == -1) isprime[i*j]=false;
            }
        }
    }
    cout<<"done\n";
}
