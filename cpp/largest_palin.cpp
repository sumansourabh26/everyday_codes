
#include<iostream>
#include<string>
#include<vector>

using namespace std;

string str;

int main(){

    while(1){
        string in;
        cin>>in;
        str.assign(in.begin(), in.end());
        int len = in.length();
        vector<vector <int> > palin(len, vector<int>(len,-1));

        for(int i = 0; i < len; i++){
            palin[i][i] = 1;
        }


    }

}
