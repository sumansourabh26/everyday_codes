#include<iostream>
#include<vector>
#include<algorithm>
#include <tr1/unordered_map>
#include<set>
#include<map>
# define V 9
using namespace std::tr1;
using namespace std;

vector<int> weight(V,10000); //length of path from start to respective vertices
vector<bool> analysed(V,false);


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
    return min_index;
}
bool all_analysed(){
    for(int i = 0; i < V;i++){
        if(!analysed[i])
            return false;
    }
    return true;
}

void dijkstra(int graph[][V], int start){ //start is starting vertices
    cout<<"analysing "<<start<<' '<<analysed[start]<<endl;

    for(int i = 0; i < V; i++){
        if(!analysed[i]){
            int temp = weight[start]+graph[start][i];
            if(weight[i]> temp){
                weight[i]= temp;
            }
            cout<<"from "<<start<<' '<<i<<" is "<<weight[i]<<endl;
        }
    }
    if(!all_analysed()){
        start = min_weight();
        analysed[start]=true;
        dijkstra(graph,start );
    }

}

int main(){
    int graph[V][V] = {{0,1,4},{1,0,2},{4,2,0}};


//    int graph[V][V] = {{10000, 4, 10000, 10000, 10000, 10000, 10000, 8, 10000},
//                    {4, 10000, 8, 10000, 10000, 10000, 10000, 11, 10000},
//                    {10000, 8, 10000, 7, 10000, 4, 10000, 10000, 2},
//                    {10000, 10000, 7, 10000, 9, 14, 10000, 10000, 10000},
//                    {10000, 10000, 10000, 9, 10000, 10, 10000, 10000, 10000},
//                    {10000, 10000, 4, 10000, 10, 10000, 2, 10000, 10000},
//                    {10000, 10000, 10000, 14, 10000, 2, 10000, 1, 6},
//                    {8, 11, 10000, 10000, 10000, 10000, 1, 10000, 7},
//                    {10000, 10000, 2, 10000, 10000, 10000, 6, 7, 10000}
//                    };

    //make_heap(weight.begin(),weight.end());
    analysed[0]=true;
    weight[0] = 0;
    cout<<"started";
    dijkstra(graph, 0);
    for(int i = 0; i < V; i++) cout<<weight[i]<<' ';


}
