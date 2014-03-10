
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include <tr1/unordered_map>

using namespace std::tr1;
using namespace std;

vector<char> incycle;
unordered_map<char, vector<char> > adjacency;
unordered_map<char, int> complete; //vertices whose dfs is incomplete will have -1 complete no.
unordered_map<char, bool> visited;
char terminal;
bool to_print;

int go = 1;

bool cycle_found(char &start){
    complete[start] = -1;
    visited[start]=true;

    for(int i = 0; i < adjacency[start].size(); i++){
        char temp = adjacency[start][i];
        if(!visited[temp]){
            visited[temp]=true;
            if(cycle_found(temp)&&to_print){
                if(temp==terminal){
                    to_print = false;
                }
                //cout<<temp<<' ';
                incycle.push_back(temp);
                return true;
            }
        }
        else{
            if(complete[temp]==-1){
                to_print = true;
                terminal = temp;
                return true;
            }
        }
    }

    complete[start]=go;
    //cout<<"compltete no of "<<start<<' '<<go<<endl;
    go++;
    return false;
}
int main(){
    string input;
    while(cin>>input){
        char c1 = input[0], c2 = input[2];
        adjacency[c1].push_back(c2);
    }
    for(int i = 65; i < 91; i++){
        to_print = false;
        complete.clear();
        visited.clear();
        char terminal = ';';

        char start = i;
        if(!visited[start]){
            if(cycle_found(start)&&to_print){
                incycle.push_back(start);
                //cout<<start<<' ';
                break;
            }
        }
    }
    sort(incycle.begin(), incycle.end());
    for(int i = 0; i < incycle.size(); i++){
        cout<<incycle[i]<<' ';
    }

}
