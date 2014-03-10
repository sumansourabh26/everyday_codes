#include<string>
#include<iostream>

using namespace std;

int main(){
    string input;
    char in;
    while(1){
        bool is_good = true, not_found = false, is_decided = false;
        int start_row = -1, start_col=-1;
        int end_col = 100000000, ex_end_row = 100000000;

        int length; cin>>length;

        for(int i = 0; i < length; i++){
            cin>> input;
            if(start_row == -1){
                int temp = input.find('#');
                if(temp < length){
                    start_col = temp;
                    start_row = i ;
                    for(int j = temp; j < length; j++){
                        if(input[j]=='#') end_col = j;
                        if(not_found&&input[j]=='#'){ is_good = false;

                        if(input[j]!='#') not_found = true;
                    }
                }
            }
        }
        cout<<is_good;
    }

}
