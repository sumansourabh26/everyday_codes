
#include<iostream>
#include<vector>

using namespace std;

class tree{
public:
    int node_val;

    tree* left;
    tree* right;
    tree(int x, tree& l, tree& r){
        node_val=x;
        left = &l;
        right = &r;
    }
    tree(int x){
        node_val=x;
        left=NULL;
        right=NULL;
    }

};

bool all_same(string &x){
    int i = 1;
    for(; i < x.size(); i++){
        if(x[i]!=x[i-1]){
            return false;
        }
    }
    if(i==x.size())
        return true;
}

int main(){
    tree leaf1(3);
    tree leaf2(4);
    tree main_tree(5,leaf1,leaf2);
    cout<<main_tree.node_val;
}
