#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string a = "suman";

    reverse(a.begin(),a.end());
    cout<<*(a.begin());
}


