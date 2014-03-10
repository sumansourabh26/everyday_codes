#include<iostream>
#include<vector>

using namespace std;

bool f( vector<int> v);

int main(){
    vector<int> a;
    a.push_back(1);
    a.push_back(3);
    a.push_back(10);
    f(a);
    cout<<a[2];
}

bool f( vector<int> v){
    v[2] = 200;
    cout<<v[2];
}
