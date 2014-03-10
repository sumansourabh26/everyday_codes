#include<iostream>
using namespace std;

void multiply2(long long f[2][2], long long b[2][2]){
    long long x1 = f[0][0]*b[0][0]+f[0][1]*b[1][0];
    long long x2 = f[0][0]*b[0][1]+f[0][1]*b[1][1];
    long long x3 = f[1][0]*b[0][0]+f[1][1]*b[1][0];
    long long x4 = f[1][0]*b[0][1]+f[1][1]*b[1][1];
    f[0][0]=x1;
    f[0][1]=x2;
    f[1][0]=x3;
    f[1][1]=x4;
}

void power(long long f[2][2],long long n){
    if(n==0||n==1) return;
    power(f,n/2);
    multiply2(f,f);
    if(n%2!=0){
        long long m[2][2]={{1,1},{1,0}};
        multiply2(f,m);
    }
}

long long fib(long long n){
    long long f[2][2]={{1,1},{1,0}};
    power(f,n-1);
    return f[0][0];
}

int main(){
    long long n;
    cin>>n;
    while(n--){
        long long p,m;cin>>p>>m;
        cout<<((fib(m+2)%1000000007)-(fib(p+1)%1000000007))%1000000007<<endl;
    }
}
