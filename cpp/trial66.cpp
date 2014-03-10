#include<iostream>
#include<string>

using namespace std;

int main(){
    string input;
    cin>>input;

    int length = input.size();

    string::iterator itr, itr_r;

    if(length%2 == 0){
        char answer[length/2];
        int i,j; bool changed = false;
        for(i = length/2 - 1 , j = length/2 ; i>= 0 ; i--, j++){
            if(changed){
                answer[i]=input[i];
            }
            else {
                if(input[i]>input[j]){
                    changed = true;
                    answer[i]=input[i];
                }
                else if(input[j]>input[i]){
                    changed = true;
                    answer[i]=input[j];
                }
                else if(input[i]=input[j]){
                    answer[i]=input[i];
                }
            }

        }
        for(int i = 0; i < length/2; i++ ){
            cout<<answer[i];
        }
        for(int i = length/2 -1 ; i >= 0 ; i--){
            cout<<answer[i];
        }
    }



}
