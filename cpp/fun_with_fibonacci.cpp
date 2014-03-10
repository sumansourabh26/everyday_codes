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

long long fib(int a, int b,long long n){
    long long f[2][2]={{1,1},{1,0}};
    power(f,n-1);
    return (b*f[0][1]+a*f[1][1]);
}

int main(){
    int n;
    cin>>n;
    int a,b,c,d;
    while(1){
        cin>>a>>b>>c>>d;
        cout<<(fib(a,b,c+2)-b)<<endl;
    }
}
