#include<iostream>
#include<string>
#include<algorithm>
#include<stack>

using namespace std;

string rpn(string input){

}

int main(){
    stack<char> s;
    char x;
    int no_of_lines;
    cin>>no_of_lines;
    for(int i = 0; i < no_of_lines;i++){
        int sum = 0;

        do{
            cin>>x;
            if(x==')'){
                cout<<s.top();
                s.pop();
                sum--;
            }
            else if(x=='('){
                sum++;
            }
            else if(x=='+'||x=='-'||x=='*'||x=='/'||x=='^'){
                s.push(x);
            }
            else{
                cout<<x;
            }
        }
        while(sum!=0);
        cout<<endl;
    }


}
