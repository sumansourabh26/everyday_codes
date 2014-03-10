#include<iostream>
#include<stack>
using namespace std;

int main(){
    int no; cin>>n;
    char input;
    stack<char> symbol;
    while(n--){
        int count = 0;
        do{
            cin>>input;
            if(input=='(')
               count++;
            else if(input==')'){
                count--;
                cout<< symbol.top();
                symbol.pop();
            }
            else if(input=='+'||input=='-'||input=='*'||input=='/'||input=='^')
        }
    }
}
