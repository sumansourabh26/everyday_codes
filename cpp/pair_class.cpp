
#include<iostream>
#include<string>
#include<map>
using namespace std;

int main()
{
    map<string, int> ma;
    ma.insert(pair<string, int>("test",1));
    ma.insert(make_pair("rest",2));

    cout<<ma["rest"]<<endl;


}
