#include<iostream>
#include<vector>
using namespace std;
void f(int input,vector<long long> &factorsum ,vector<long long> &ans){
    if(input==0||input==1) ans[input]=0;
    else if(ans[input]==0){
        f(input-1,factorsum,ans);
        ans[input] = ans [input-1] +factorsum[input];
    }
}

int main(){
    int no;
    cin>>no;
    vector<long long> factorsum(1000000,1);
    factorsum[0]=0;
    factorsum[1]=0;
    for(int i=2;i<1000000;i++){
        for(int j = 2; i*j < 1000000; j++){
            factorsum[i*j]=factorsum[i*j]+i;
        }
    }
    while(no--){
        int input;cin>>input;
        int ans = 0;
        for(int i = 1; 1<=input; i++)
            ans = ans + factorsum[i];
        cout<<ans<<endl;
    }

//C:\codes\simplecpp\amazing_factor.cpp|33|error: invalid
// initialization of reference of type
//'std::vector<int>&' from expression of type 'std::vector<long long int>'|
//    vector<long long> ans(1000000,0);
//    int input;
//    ans[0]=0;ans[1]=0;
//    while(no--){
//        cin>>input;
//        f(input,factorsum, ans);
////            for(int i = 1; i <= input; i++){
////                ans[i] = ans[i-1]+factorsum[i];
////            }
//        cout<<ans[input]<<endl;
//
//    }

}

