#include<iostream>
#include<vector>
using namespace std;

int main(){
    int no;
    cin>>no;
    vector<int> isprime(10000000,-1);
    isprime[0]=0;
    isprime[1]=0;
    for(int i=2;i<10000000;i++){
        if(isprime[i] == -1){
            isprime[i]=i;
            for(int j=2;(j*i)<10000000 ;j++){
                //if(i == 3)cout<<i*j<<" ";
                if(isprime[i*j] == -1) isprime[i*j]=i;
            }
        }

    }
    //vector<long long int>ans (10000000,-1);
    long long ans;
    int input;
    while(no--){
        cin>>input;
        ans = 0;
        for(int i = 1; i <= input; i++){
            ans = ans+isprime[i];
        }
        cout<<ans<<endl;
    }

}
