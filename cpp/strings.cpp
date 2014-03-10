
#include<iostream>
#include<string>
using namespace std;

int main(){
    string s1("suman 1 ");
    string s2;
    string s3;

    s2=s1;
    s3.assign(s1);

    cout<<s1<<s2<<s3;
}
