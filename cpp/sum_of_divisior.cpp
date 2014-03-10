#include<iostream>
#include<stdio.h>
using namespace std;

long long degree(long long no, long long &d){
    long long dr = 1;
    while(no!=0 && no%d ==0){
        no = no/d;
        dr = dr* d;
    }
    return dr*d;
}
int main(){
    bool isprime[1000000];
    long long i;
    isprime[0]=false;
    isprime[1]=false;
    for( i=2; i < 1000000; i++){
        isprime[i]=true;
    }
    long long j;
    for(i = 2; i < 1000000; i++){
        if(isprime[i]){
            for(j = 2*i; j < 1000000; j = j+i)
                isprime[j]=false;
        }
    }
    long long input, no_of_input, ans, d;
    bool found_factor, isgood;
    long long deg;
    //cin>>no_of_input;
    for(j = 65536; j < 1000000; j++){
        ans = 1;
        found_factor = false; isgood = true;
        input = j;
        //cin>>input;
        for(i = 2; i <=input; i++ ){
            if(isprime[i] && input%i==0){
                //printf("i is%d\n",i);
                deg = (degree(input,i)-1)/(i-1);
                //printf("deg is%d\n",deg);
                if((deg!=1&&found_factor)||(!isprime[deg])) {isgood = false; break;}
                if(deg!=1)found_factor=true;
                ans = (ans*deg);
                //printf("ans is%d\n",ans);
                if(!isprime[ans]){isgood = false;break;}
            }
        }
        //cout<<ans-input<<endl;
        if(isprime[ans]&&isgood) cout<<input<<endl;

    }
}
