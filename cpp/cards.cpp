#include<iostream>
using namespace std;

int main(){
    int no;
    cin>>no;
    while(no--){
        long long n;
        cin>>n;
        cout<<(((3*n*(n+1))/2) - n)%1000007<<endl;
    }
}
