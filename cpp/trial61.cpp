#include<iostream>
#include<vector>

using namespace std;

class string_pair{
public:

    vector<int> s1;
    vector<int> s2;
    void setval(vector<int> str, vector<int>substr){
        s1 = str; s2 = substr;
    }

    void match(){
        vector<int> s3;
        vector<int>::iterator itr;
        int size_s2 = s2.size();
        for(itr = s1.begin();itr < s1.end();itr++){
            s3.assign(itr, itr+size_s2);
            if(s3==s2){
                cout<<1<<endl;
                break;
            }
        }
        if(itr==s1.end()+1-size_s2){
            cout<<0<<endl;
        }
    }
};

int main(){
    string_pair series[24];

    string str, substr;
    vector<int> str_vec, substr_vec;

    for(int i = 0; i<24;i++){
        cin>>str;
        cin>>substr;
        for(int j= 0; j<str.size(); j++){
            str_vec.push_back(str[j]);
        }
        for(int j= 0; j<substr.size(); j++){
            substr_vec.push_back(substr[j]);
        }
        series[i].setval(str_vec, substr_vec);
    }
    for(int i = 0; i<24;i++){
        series[i].match();
    }
}
