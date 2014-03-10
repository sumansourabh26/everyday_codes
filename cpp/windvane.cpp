#include<iostream>
#include<vector>
using namespace std;

vector< vector<char> > direction;
struct node{
    node *q1,*q2,*q3,*q4;
    int startx,starty, endx, endy;
    int total;
    char dir;

    node(){
        q1 = NULL;
        q2 = NULL;
        q3  = NULL;
        q4  = NULL;
        total = 0;
    }
//    node(node* left, node* right, int ranges, int rangee){
//        l_beta=left;
//        r_beta=right;
//        this->rangee=rangee;
//        this->ranges=ranges;
//    }
};
void printtree(node* tree);
node* maketree(node* &newnode, int startx, int starty, int endx, int endy);
void update(node* &newnode, int sx, int sx, int ex, int ey, int &inc);

int main(){
    int n, m; cin>>n>>m;

    vector< vector<char> > temp_direction(n, vector<char>(m));

    cout<<temp_direction.size()<<" "<<temp_direction[0].size()<<endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>temp_direction[i][j];
        }
    }
    direction.assign(temp_direction.begin(),temp_direction.end());


    node* newnode = NULL;
    maketree(newnode, 0, 0, n-1, m-1);
    printtree(newnode);

    int no_input; cin>>no_input;
    char command;
    int sx,sy,ex,ey, inc, qx, qy;
    while(no_input--){
        cin>>command;
        if(command=='C'){
            cin >> sx >>sy >> ex >> ey >> inc;
            update(newnode, sx, sy, ex, ey, inc);
        }
        else if(command=='D'){
            cin>>qx>>qy;
        }
    }
}

void update(node* &newnode, int sx, int sx, int ex, int ey, int &inc){

}

node* maketree(node* &newnode, int startx, int starty, int endx, int endy){
    if(startx==endx && starty==endy){
        newnode = new node();
        //newnode->total = number[start];
        newnode->startx = startx;
        newnode->starty = starty;
        newnode->endx = endx;
        newnode->endy = endy;
        newnode->dir = direction[startx][starty];
        // cout<<"total is "<<newnode->total<<"range is "<<newnode->ranges<<" to "<<newnode->rangee<<endl;
        return newnode;
    }
    else{
        newnode = new node();
        newnode->q1 = maketree(newnode->q1, startx, starty, (startx+endx)/2, (starty+endy)/2);
        if((starty+endy)/2 +1 <= endy){
            newnode->q2 = maketree(newnode->q2, startx, (starty+endy)/2 +1, (startx+endx)/2, endy);
        }
        if(((startx+endx)/2 + 1 <= endx &&  (starty+endy)/2 +1 <= endy)){
            newnode->q3 = maketree(newnode->q3, (startx+endx)/2 + 1, (starty+endy)/2 +1, endx, endy);
        }
        if((startx+endx)/2 + 1 <= endx){
            newnode->q4 = maketree(newnode->q4, (startx+endx)/2 + 1, starty, endx, (starty+endy)/2);
        }
        newnode->startx = startx;
        newnode->starty = starty;
        newnode->endx = endx;
        newnode->endy = endy;
        //cout<<"range is ("<<newnode->startx<<","<<newnode->starty<<") to ("<<newnode->endx<<","<<newnode->endy<<endl;
        return newnode;
    }
}

void printtree(node* tree){
    if (tree==NULL) {return;}
    cout<<"range is ("<<tree->startx<<","<<tree->starty<<") to ("<<tree->endx<<","<<tree->endy<<")"<<endl;
    if(tree->startx==tree->endx && tree->starty==tree->endy){
        cout<<"the direction here is "<<direction[tree->startx][tree->starty]<<endl;
    }
    printtree(tree->q1);
    printtree(tree->q2);
    printtree(tree->q3);
    printtree(tree->q4);
}
