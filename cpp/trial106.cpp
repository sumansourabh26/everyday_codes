
#include<iostream>
using namespace std;

int main(){
    long long int no_of_lines;
    cin>>no_of_lines;

    long long int up[no_of_lines], low[no_of_lines], range = 0;
    for(long long int i = 0; i<no_of_lines; i++){
        cin>> low[i]>>up[i];
        range = max(range , up[i]);
    }

    bool isprime[range+1];
    isprime[0]=false;
    isprime[1]=false;
    for(long long int i = 2; i <=range; i++){
        isprime[i]=true;
    }
    for(long long int i = 2; i <=range; i++){
        if( isprime[i]){
            for(long long int j = 2*i ; j <= range; j = j + i){
                isprime[j] = false;
            }
        }
    }
    for(long long int i = 0; i < no_of_lines; i++){
        for(long long j = low[i]; j <= up[i]; j = j++){
            if(isprime[j])cout<<j<<endl;
        }
        cout<<endl;
    }

}
