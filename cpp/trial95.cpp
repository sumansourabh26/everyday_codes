
#include<iostream>
#include<cmath>
using namespace std;

bool is_prime(long long x){
    bool prime = true;
    for(long long i = 2; i < sqrt(x)+1; i++){
        if(x%i==0){
            prime = false;
            break;
        }
    }
    return prime;
}

int main(){
    long long roll ,range;
    cout<<"enter n\n";cin>>roll;
    cout<<"enter m\n";cin>>range;

    int no_of_special= 0;
    cout<<"Special Prime numbers less than roll no. :\n";
    for(long long i = roll-1; i>= roll-range; i--){
        if(is_prime(i) && is_prime(i+6)){
            cout<<i<<' ';
            no_of_special++;
            if(no_of_special%5==0){cout<<endl;}
        }
    }
    cout<<"\nThere are "<<no_of_special<<" Special primes below roll "<<roll;

    int no_of_nonspecial= 0;
    cout<<"\nnon Special Prime numbers more than roll no. :\n";
    for(long long i = roll+1; i<= roll+range; i++){
        if(is_prime(i) && !is_prime(i+6)){
            cout<<i<<' ';
            no_of_nonspecial++;
            if(no_of_nonspecial%5==0){cout<<endl;}
        }
    }
    cout<<"\nThere are "<<no_of_nonspecial<<" non Special primes below roll "<<roll;
}
