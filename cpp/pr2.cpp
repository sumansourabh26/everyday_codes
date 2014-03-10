#include<iostream>
#include<string>
using namespace std;

int main(){
    vector<bool> isprime(1000000000,true);
    isprime[1]=false;
    for(int i = 2; i < 1000000000; i++){
        if(isprime[i]){
            for(int j = 2*i; j < 1000000000; j= j+i){
                isprime[j]=false;
            }
        }
    }
    int lower, upper;
    cin>>lower>>upper;
    bool isKnumber = true;
    for(int i = lower; i <= upper; i++){
        //cout<<"for "<<i<<endl;
         bool is_good = true;
         int got_p = 0;
        for(int j = 2; j <= i; j++){
            if(isprime[j]){
                //cout<<"for prime:"<<j<<endl;
                int power_mult = j, temp_i = i;

                while(temp_i%j == 0){
                    power_mult = power_mult*j;
                    temp_i=temp_i/j;
                }
                //cout<<"power mult:"<<power_mult<<endl;
                int to_multiply = (power_mult-1)/(j-1);
                //cout<<"factor to multiply:"<<to_multiply<<endl;
                if(to_multiply > 1 && got_p == 1){
                    //cout<<"case1"<<endl;
                    is_good = false;
                    break;
                }
                else if(!isprime[to_multiply] && to_multiply != 1){
                    //cout<<"case2"<<endl;
                    is_good = false;
                    break;
                }
                else if(to_multiply !=1 && got_p == 0){
                    //cout<<"case3"<<endl;
                    got_p++;
                }
            }

        }

        if(is_good && got_p ==1) cout<<i<<endl;
    }
}
