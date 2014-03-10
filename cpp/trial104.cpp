#include<iostream>

using namespace std;

struct data{
    int value;
    int bal; // stores height of (left - right)
};

struct node{
    data r;
    node*left;
    node* right;
    node(){
        left = NULL;
        right = NULL;
        r.bal = 0;
    }
    node(int val){
        left = NULL;
        right = NULL;
        r.value = val;
        r.bal = 0;
    }
    node( data r,node* ln, node* rn){
        left = ln;
        right = rn;
        this->r = r;
    }
};

bool insert(node* &tree, int val);//returns if height of new tree > older. val
void printnode(node* &tree);
//bool deleteNode(node* &tree, int val);
int leftMost(node* &tree);

int main(){
    node* tree;
    tree= NULL;
    int input;
    while(true){
        cin>>input;
        if(input==100) break;
        else insert(tree, input);
    }
    printnode(tree);
}

int leftMost(node* &tree){
    if(tree->left == NULL){
        int toReturn = (tree->r).value;
        deleteNode(tree, (tree->r).value);
        return toReturn;
    }
    else{
        return leftMost(tree->left);
    }
}

bool deleteNode(node* &tree, int x){//returns if height is changed
    if((tree->r).value > x){
        bool b = deleteNode(tree->left, x);
        if(!b) return false;
        else if((tree->r).bal != 1)
    }
    else if((tree->r).value < x){
        bool b = deleteNode(tree->right, x);

        if(!b) return false;
        else if((tree->r).bal != 1){
            (tree->r).bal = (tree->r).bal + 1;
            return ((tree->r).bal == 0);
        }
        else{
            if(((tree->right)->r).value < x){

            }
        }
    }
    if((tree->r).value == x){
        if(tree->left == NULL && tree->right == NULL){
            tree = NULL;
        }
        if(tree->left==NULL){
            tree = tree->right;
        }
        if(tree->right==NULL){
            tree = tree->left;
        }
        else{
            (tree->r).value = leftMost(tree->right);
        }
    }

}

bool insert(node* &tree, int x){ //returns if height of new tree > older. val
    if(tree == NULL){
        tree = new node(x);
        return true;
    }
    else if((tree->r).value < x){
        bool b = insert(tree->right, x);
        if(!b) return false;
        else if((tree->r).bal != -1){
            (tree->r).bal = (tree->r).bal - 1;
            return ((tree->r).bal == -1);
        }
        else{
            if(((tree->right)->r).value < x){
                (tree->r).bal = 0;
                ((tree->right)->r).bal = 0;
                tree = new node((tree->right)->r,
                                 new node(tree->r, tree->left, (tree->right)->left),
                                (tree->right)->right);
                return false;
            }
            else if(((tree->right)->r).value > x){
                int bal_of_lr = (((tree->right)->left)->r).bal;

                (((tree->right)->left)->r).bal = 0;
//                if(bal_of_lr==-1) (tree->r).bal=1;
//                else (tree->r).bal= 0;
//
//                if(bal_of_lr==1) ((tree->right)->r).bal=-1;
//                else ((tree->right)->r).bal= 0;

                if(bal_of_lr=1){
                    (tree->r).bal=0;
                    ((tree->right)->r).bal=-1;
                }
                if(bal_of_lr=0){
                    (tree->r).bal=0;
                    ((tree->right)->r).bal=0;
                }
                if(bal_of_lr=-1){
                    (tree->r).bal=1;
                    ((tree->right)->r).bal=0;
               }
                tree = new node(((tree->right)->left)->r,
                                 new node(tree->r, tree->left,(((tree->right)->left)->left)),
                                 new node((tree->right)->r,((tree->right)->left)->right,(tree->right)->right));
                return false;
            }
        }
    }
    else if((tree->r).value > x){
        bool b = insert(tree->left, x);
        if(!b) return false;
        else if((tree->r).bal != 1){
            (tree->r).bal = (tree->r).bal + 1;
            return ((tree->r).bal == 1);
        }
        else{
            if(((tree->left)->r).value > x){
                (tree->r).bal = 0;
                ((tree->left)->r).bal = 0;
                tree =new node((tree->left)->r,
                               (tree->left)->left,
                               new node(tree->r,  (tree->left)->right ,tree->right));
                return false;
            }
            else if(((tree->left)->r).value < x){
                int bal_of_lr = (((tree->left)->right)->r).bal;
                (((tree->left)->right)->r).bal = 0;

//                if(bal_of_lr==1) (tree->r).bal=-1;
//                else (tree->r).bal= 0;
//
//                if(bal_of_lr==-1) ((tree->right)->r).bal=1;
//                else ((tree->right)->r).bal= 0;

                if(bal_of_lr=-1){
                    (tree->r).bal=0;
                    ((tree->left)->r).bal=1;
                }
                if(bal_of_lr=0){
                    (tree->r).bal=0;
                    ((tree->left)->r).bal=0;
                }
                if(bal_of_lr=1){
                    (tree->r).bal=-1;
                    ((tree->left)->r).bal=0;
                }
                tree = new node(((tree->left)->right)->r,
                                new node((tree->left)->r,(tree->left)->left,((tree->left)->right)->left),
                                new node(tree->r, ((tree->left)->right)->right, tree->right));
                return false;
            }
        }
    }
}

void printnode(node* &tree){
    if(tree==NULL){
        cout<<"null here\n";
    }
    else{
        cout<<"entering node:"<<(tree->r).value<<endl;
        cout<<"entering left node\n";
        printnode(tree->left);
        cout<<"entering right node\n";
        printnode(tree->right);
    }
}
