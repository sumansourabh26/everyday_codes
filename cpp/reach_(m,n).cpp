#include<iostream>
using namespace std;

int reach(int m,int n){
    if(m == 0) return 1;
    else if(n==0) return 1;
    else return(reach(m,n-1) + reach(m-1,n));
}

int main(){
    int n,m;
    cin>>n>> m;
    cout<<reach(n,m);
}
