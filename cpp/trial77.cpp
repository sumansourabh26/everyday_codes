#include<iostream>
#include<math.h>
using namespace std;
bool prime(int i){
    if(i==2)return true;
    int k=sqrt(i);
    for(int j=2;j<=k;j++)
        if(i%j==0)return false;
    return true;
}
int main(){
    int n;
    long long ans=1;
    cin>>n;
    for(int i=2;i<=n;i++){
        if(prime(i)){
            int b=2;
            for(int k=2;k*i<=n;k++){
                int a=k*i;
                while(a%i==0){
                    a=a/i;
                    b=b+2;
                }
            }
            int p=b+1;
            p=p%1000007;
                ans=(ans*p)%1000007;
        }
    }
    cout<<ans<<endl;
}
