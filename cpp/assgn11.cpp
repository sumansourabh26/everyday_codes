#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<unordered_map>
using namespace std;

struct vertex{
    int balance;
    list<string> pre;
    list<string> suff;
};

int main(){
    int str_length;
    cin>>str_length;

    int sub_length;
    cin>>sub_length;

    unordered_map<string, vertex > vert;
    unordered_map<string, vector<string> > pre, suff;

    string sub[str_length-sub_length+1];
    for(int i = 0; i < str_length-sub_length+1; i++){
        cin>> sub[i];
    }
    for(int i = 0; i < str_length-sub_length+1; i++){
        for(int j = 0; j < str_length-sub_length+1; j++){
            if(sub[i].substr(1) == sub[j].substr(0,sub_length-1)){
                suff[sub[i]].push_back(sub[j].substr(0,sub_length-1));
            }
            if(sub[j].substr(1) == sub[i].substr(0,sub_length-1)){
                pre[sub[i]].push_back(sub[j].substr(0,sub_length-1));
            }
        }
    }
    int counterneg = 0 , counterpos = 0;
    for(int i = 0; i < str_length-sub_length+1 ; i++){
        if(suff[sub[i]].size() > pre[sub[i]].size()){
            counterpos++;
        }
        if(suff[sub[i]].size() < pre[sub[i]].size()){
            counterneg++;
        }
        if((counterneg > 1)|| (counterpos > 1)){
            cout<<"NOT POSSIBLE";
            break;
        }
    }
}


