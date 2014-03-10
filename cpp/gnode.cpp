#include<vector>
#include<iostream>

using namespace std;

struct node{
    string dir_name;
    map<string,node*> child_dir; //stores the pointers of the child
    list<string> files;
    node(string name){
        dir_name = name;
    }
};

void insert_file(node* &tree, string &address, node* &to_insert, int &pos_slash){
    if()

}

int main(){
    node tree = new node("suman/system/itsme/acads");
    string address1 = "suman/system/itsme/acads";
    string address2 = "suman/system";
    string address3 = "sonu/movies";

    node to_insert1 = new node("skiena");
    node to_insert2 = new node("idc");

    insert_file(tree, "suman/xx",,  );
}
