#include<iostream>
#include<string.h>
#include<vector>

using namespace std;

int main(){
    string s1 = "1001100", s2 = "11";
    vector<int> s1_vec;
    for(int i = 0;i < s1.size(); i++){
        s1_vec.push_back(s1[i]);
    }
    vector<int> s2_vec;
    for(int i = 0;i < s2.size(); i++){
        s2_vec.push_back(s2[i]);
    }

    string s3;
    string::iterator itr;
    for(itr = s1.begin();itr < s1.end();itr++){
        s3.assign(itr, itr+s2.size());
        if(s3==s2){
            cout<<"found";
            break;
        }
    }
    if(itr==s1.end())
        cout<<"ghanta";
}
