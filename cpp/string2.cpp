#include<iostream>
#include<string>
using namespace std;

int main(){

    string s1 = "whatthefuck wlekq";

    cout<<s1.substr(3,5)<<endl;

    string one("apple");
    string two("beans");
    one.swap(two);
    cout<<one<<endl<<endl;

    string s2("ham is spam oh yes i am!");
    cout<<s2.rfind("am");
}
