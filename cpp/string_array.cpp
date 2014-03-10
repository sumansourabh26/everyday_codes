#include<iostream>
#include<string>
using namespace std;

int main(){
    string s1("hi my name is suman and i love bacon and ham!");
    cout<<s1<<endl;
    s1.erase(13);
    cout<<s1<<endl;

    string s2("hi my name is suman and i love bacon and ham!");
    s2.replace(14,5,"bucky");
    cout<<s2<<endl;

    string s3("hi my name is suman and i love bacon and ham!");
    s3.insert(14,"lucky ");
    cout<<s3<<endl;


}
