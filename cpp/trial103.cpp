#include<iostream>

using namespace std;

struct node{
    int data;
    node* left;
    node* right;
};

node* NewNode(int data) {
node* node = new(struct node); // "new" is like "malloc"
node->data = data;
node->left = NULL;
node->right = NULL;
return(node);
}

node* insert(struct node* node, int data) {
// 1. If the tree is empty, return a new, single node
    if (node == NULL) {
        return(NewNode(data));
    }
    else {
// 2. Otherwise, recur down the tree
        if (data <= node->data) node->left = insert(node->left, data);
        else
            node->right = insert(node->right, data);
    return(node); // return the (unchanged) node pointer
    }
}

int main(){
    cout<<"making new tree\n";
    node* root = NULL;
    root = insert(root, 2);
    root = insert(root, 1);
    root = insert(root, 3);
    cout<<(root->left)->data;
}
