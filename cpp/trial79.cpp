#include<iostream>
#include<vector>
#include<string>
#include<math.h>
#include<cstdlib>

using namespace std;

void in(vector<vector<int>> *input,int no_of_lines);
void andf(vector<vector<int>> input1,vector<vector<int>> input2);


int main(){
    int no_of_input;
    cin>> no_of_input;
    for(int i = 0; i<no_of_input;i++){
        char cond;
        cin>>cond;
        if(cond=='&'||cond=='|'){
            int no_of_lines;
            cin>>no_of_lines;
            vector<vector<int>> input1(no_of_lines,vector<int>(32,0));
            in(&input1,no_of_lines);
            cout<<input1[2][2];
            cin>>no_of_lines;
            vector<vector<int>> input2(no_of_lines,vector<int>(32,0));
            in(&input2,no_of_lines);

        }
        if(cond=='~'||cond=='('){
            int no_of_lines;
            cin>>no_of_lines;
            vector<vector<int>> input1(no_of_lines,vector<int>(32,0));
            in(&input1,no_of_lines);



        }
    }
}

void in(vector<vector<int>> *input,int no_of_lines){
    for(int line = 0; line<no_of_lines;line++){
        int no_of_values;
        cin>>no_of_values;
        for(int value = 0; value<no_of_values;value++){
            int index;cin>>index;
            if (index>0)
                (*input)[line][index-1]= 1;
            else
                (*input)[line][-(index+1)] = -1;
        }
    }
}
void andf(vector<vector<int>> input1,vector<vector<int>> input2){

    for(int start = 0; start < input1.size()-1){

    }
}
