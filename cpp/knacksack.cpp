#include<iostream>
#include<vector>

using namespace std;

bool knack(vector<int>, vector<int>);

int total = 22;
int main(){
    vector<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(5);
    l.push_back(9);
    l.push_back(10);

    vector<int> answer;

    knack(l, answer);
}

bool knack(const vector<int> l,const vector<int> answer){
    if(total==0){
        for(int i=0; i<answer.size(); i++){
            cout<<answer[i]<<' ';
            return true;
        }
    }
    else if(l.size()==0){
            return false;
    }
    else{
            vector<int> l_copy = l;
            l_copy.erase(l_copy.begin());
            vector<int> answer_copy = answer;
            answer_copy.erase(answer_copy.begin());
            return(knack(l_copy,answer_copy) || knack(l,answer));
    }
}
