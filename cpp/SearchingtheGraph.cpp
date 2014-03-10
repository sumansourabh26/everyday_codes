#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

vector<bool> visited;

void dfs(vector<vector<int> >& vertex, int &start){
    cout<<start+1<<' ';visited[start]=true;
    //cout<<"entering "<<start+1<<endl;
    for(int i = 0; i < vertex[start].size(); i++){
        if(!visited[vertex[start][i]] )
            dfs(vertex, vertex[start][i]);
        //else cout<< vertex[start][i]+1<<" already visited\n";
    }
}

void putinq(queue<int>& q,vector<vector<int> >& vertex, int &start){
    for(int i = 0; i < vertex[start].size(); i++){
        if(!visited[vertex[start][i]]) {
            q.push(vertex[start][i]);
            visited[vertex[start][i]]=true;
        }
        //else cout<< vertex[start][i]+1<<" already visited\n";
    }
}

void bfs(queue<int>& q,vector<vector<int> >& vertex, int &start){
    cout<<start+1<<' ';
    visited[start]=true;
    putinq(q,vertex,start);
    while(!q.empty()){
        int temp = q.front();
        cout<<temp+1<<' ';
        q.pop();
        //visited[temp]=true;
        putinq(q,vertex,temp);
        //cout<<"queue size: "<<q.size()<<endl;
    }
}

int main(){
    int noi;
    cin>>noi;
    for(int p = 1; p <= noi; p++){
        int n; cin>>n;
        vector<vector<int> > vertex(n);

        for(int i = 0; i < n; i++){
            int ver, no_neigh;
            cin>>ver>>no_neigh;
            //cout<<"putting in "<<ver<<endl;
            for(int j = 0; j < no_neigh; j++){
                int temp;
                cin>>temp;
                vertex[ver-1].push_back(temp-1);
            }
        }
        cout<<"graph "<<p<<endl;
        //cout<<"start\n";
        int start, traversal;
        while(true){
            cin>>start>>traversal;
            if(start==0 && traversal==0){
                break;
            }
            else{
                visited.assign(n,false);
                if(traversal==0){
                    start--;
                    dfs(vertex, start);
                    cout<<endl;
                }
                else{
                    start--;
                    queue<int> q;
                    bfs(q, vertex, start);
                    cout<<endl;
                }
            }
        }

    }
}
