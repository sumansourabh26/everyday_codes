#include<iostream>
using namespace std;

struct node{
    int value;
    node* left;
    node* right;

    node(){
        //value = 0;
        left = NULL;
        right = NULL;
    }
    node(int x){
        value = x;
        left = NULL;
        right = NULL;
    }
};
void printnode(node* &tree);
void insert(node* &tree, int v);
node* build123();
int size(node* &tree);
int sum(node* &tree);
void printSeq(node* &tree);
void printPost(node* &tree);
bool hasPathSum(node* &tree, int sum);
void deleteNode(node* &tree, int val);
int leftMost(node* &tree);
void prePrint(node* &tree);

int main(){
    cout<<"making new tree\n";
    node* tree = NULL;
    int input;
    while(true){
        cin>>input;
        if(input==100)break;
        else insert(tree, input);
    }
    prePrint(tree);
}

int leftMost(node* &tree){
    if(tree->left == NULL){
        int toReturn = tree->value;
        deleteNode(tree, tree->value);
        return toReturn;
    }
    else{
        return leftMost(tree->left);
    }
}

void deleteNode(node* &tree, int val){
    if(tree->value < val){
        deleteNode(tree->right, val);
    }
    else if(tree->value > val){
        deleteNode(tree->left,val);
    }
    else{
        if(tree->left == NULL && tree->right==NULL){
            tree = NULL;
        }
        else if(tree->left==NULL){
            tree = tree->right;
        }
        else if(tree->right==NULL){
            tree = tree->left;
        }
        else{
            tree->value = (leftMost(tree->right));
        }
    }
}

bool hasPathSum(node* &tree, int sum){
    if(tree==NULL){
        if(sum==0)
            return true;
        else
            return false;
    }
    else
        return( hasPathSum(tree->left, sum-(tree->value))
                || hasPathSum(tree->right, sum-(tree->value)));
}
void printPost(node* &tree){

    if(tree==NULL){
        cout<<"";
    }
    else{
        printPost(tree->left);
        printPost(tree->right);
        cout<<tree->value;
    }
}

void prePrint(node* &tree){
    if(tree==NULL);
    else{
        cout<<tree->value<<' ';
        prePrint(tree->left);
        prePrint(tree->right);
    }
}
void printSeq(node* &tree){
    if(tree==NULL){
        cout<<"";
    }
    else{
        printSeq(tree->left);
        cout<<tree->value<<' ';
        printSeq(tree->right);
    }
}

int sum(node* &tree){
    if(tree==NULL){
        return 0;
    }
    else{
        return(tree->value + sum(tree->right) + sum(tree->left));
    }
}

int size(node* &tree){
    if(tree==NULL){
        return 1;
    }
    else
        return (size(tree->left)+ size(tree->right));
}

void insert(node* &tree, int v){
    if(tree == NULL){
        tree = new node(v);
    }
    else if(tree->value <= v){
            insert( tree->right , v);
    }
    else{
            insert(tree->left, v);
    }
}

void printnode(node* &tree){
    if(tree==NULL){
        cout<<"null here\n";
    }
    else{
        cout<<"entering node:"<<tree->value<<endl;
        cout<<"entering left node\n";
        printnode(tree->left);
        cout<<"entering right node\n";
        printnode(tree->right);
    }
}

