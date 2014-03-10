#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
bool prime(int n){
    if(n == 2)return true;
    for(int i=2;i<=sqrt(n);i++)
        if(n%i == 0)return false;
        return true;
}

int main() {
    int t,count,next;
    cin>>t;
    vector<int> p;
    vector<int> v;
    for(int j=2;j<444;j++)
        if(prime(j))p.push_back(j);
        //cout<<p.size()<<" ";
    for(int k=30;k<=2664;k++){
        count=0;
        for(int j=0;j<p.size();j++){
            if(k%p[j] == 0)count++;
            if(count == 3){
                v.push_back(k);
                break;}}}
    for(int k=0;k<t;k++){
        cin>>next;
        cout<<v[next-1]<<"\n";
    }
}

