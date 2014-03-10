#include<iostream>
#include<stdio.h>
using namespace std;

int degree(int no, int &d){
    int dr = 1;
    while(no!=0 && no%d ==0){
        no = no/d;
        dr = dr* d;
    }
    return dr*d;
}
int main(){
    bool isprime[50000];
    int i;
    isprime[0]=false;
    isprime[1]=false;
    for( i=2; i < 50000; i++){
        isprime[i]=true;
    }
    int j;
    for(i = 2; i < 50000; i++){
        if(isprime[i]){
            for(j = 2*i; j < 50000; j = j+i)
                isprime[j]=false;
        }
    }
    int input, no_of_input, ans, d;
    bool found_factor, isgood;
    int deg;
    cin>>no_of_input;
    for(j = 2; j < 1000000; j++){
        ans = 1;
        found_factor = false; isgood = true;
        cin>>input;
        for(i = 2; i <=input; i++ ){
            if(isprime[i] && input%i==0){
                printf("i is%d\n",i);
                deg = (degree(input,i)-1)/(i-1);
                printf("deg is%d\n",deg);
                if((deg!=1&&found_factor)||(!isprime[deg])) {isgood = false; break;}
                if(deg!=1)found_factor=true;
                ans = (ans*deg);
                printf("ans is%d\n",ans);
                if(!isprime[ans]){isgood = false;break;}
            }
        }
        if(isprime[ans])cout<<ans<<" prime\n";
    }
}


