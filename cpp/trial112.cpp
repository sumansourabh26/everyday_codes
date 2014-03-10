
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include <tr1/unordered_map>
#define V 4
using namespace std::tr1;
using namespace std;


vector<int> weight = {-3,2,4,-1 }; //length of path from start to respective vertices
vector<bool> analysed = {true, true, false, true};

int min_weight(){
    int mymin = 10000, min_index;
    for(int i = 0; i < V; i++){
        if(!analysed[i]){
            if(mymin>weight[i]){
                mymin = weight[i];
                min_index = i;
            }
        }
    }
    return mymin;
}


int main(){
    cout<<min_weight();
}
