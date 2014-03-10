
#include<iostream>
#include<list>
#include<utility>
#include<vector>

using namespace std;

int main(){
    list<int> l;
    l.push_back(23);
    l.push_back(231);
    l.push_back(234);
    l.push_back(235);
    l.push_back(238);

    list<int>::iterator itr;

    for(itr=l.begin();itr!=l.end();itr=itr++){
        cout<<*itr;
    }
}
