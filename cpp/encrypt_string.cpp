#include<iostream>
using namespace std;

int main(){
    int no;
    cin>>no;
    string input;
    char out;
    while(n--){
        cin>>input;
        int size = input.size();
        int shift;
        cin>>shift;
        int temp;
        for(int i = 0; i < size; i++){
            if(input[i]<=90){
                temp = (input[i]+shift);
                if(temp>90)
                    temp = (temp - 90)%26 + 64 ;
                out = temp;
                cout<<out;
            }
            else{
                temp = (input[i]+shift);
                if(temp>122)
                    temp = (temp - 122)%26 + 96 ;
                out = temp;
                cout<<out;
            }
        }
        cout<<endl;
    }
}
