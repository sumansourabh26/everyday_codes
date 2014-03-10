
#include<iostream>
using namespace std;

template <class FIRST, class SECOND>

double smaller(FIRST a, SECOND b){
    return(a<b? a:b);
}

int main(){
    double a = 3.22321;
    long  b =12;
    cout<<smaller(a,b);
    cout<<smaller(b,a);

}
