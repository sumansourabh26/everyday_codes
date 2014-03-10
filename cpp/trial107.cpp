#include <iostream>
#include <string>
#include<map>
#include<vector>

using namespace std;

struct node{
    string dir_name;
    map<string, node*> child_list; //stores the pointers of the child
};

int main(){
    string s = "qwertyuiop";
    int i = 5;
    cout<<s.substr(1,i)<<endl<<s.substr(i+1)<<endl<<s[0];
}
