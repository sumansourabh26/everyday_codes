#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int ans=1;

    for(int counter = 1; counter <= n; counter++){
        ans = ans* counter;

    }
    jump(0);
    cout<<ans;
}

