
#include<iostream>
#include<vector>
#include<string>
#include<cmath>

using namespace std;

class prime_class{
public:
    long long prime;
    long long power;
    prime_class(long long  prime){
        this->prime = prime;
    }
    void setpower(long long  power){
        this->power = power;
    }
};

int main(){
    long long  input;
    cin>>input;

    vector<prime_class> primes;
    for(long long  i = 2; i <= input; i++){
        bool primeq = true;
        long long  j = 2;
        for(; j <= sqrt(i); j++){
            if(i%j == 0){
                primeq = false;
                break;
            }
        }
        if(primeq)
            primes.push_back(prime_class(i));
    }
    //unsigned long long int total = 1 ;
    for(long long  i = 0; i< primes.size(); i++){
        long long  temp_power = 0;
        for(long long  temp = primes[i].prime ; temp <= input; temp = temp*primes[i].prime){
            temp_power = (temp_power + (input/temp));
        }
        primes[i].setpower(temp_power);
    }
    long i = 0;
    unsigned long long total = 1 ;
    for( ;i < primes.size(); i++){
        total = (total* ((2*(primes[i].power) + 1 )%1000007))%1000007;
    }
    cout<<total;

}
