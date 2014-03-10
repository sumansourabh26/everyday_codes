#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v1(2,3),v2(3,5);
    v1.insert( v1.end(), v2.begin(), v2.end() );
    cout<<v1[4];
}
