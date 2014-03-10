#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
void add(string &s1, string &s2);

string answer;

int main(){
    string s1, s2;
    int no_of_input;
    cin>>no_of_input;
    for(int i = 0; i<no_of_input;i++){
        cin>>s1>>s2;
        add(s1,s2);
        //cout<<answer<<endl;
        int j= 0;
        for(; ;j++){
            if(answer[j]!='0') break;
        }
        //cout<<"j:"<<j<<endl;
        cout<<answer.substr(j)<<endl;
    }
}

void add(string &s1, string &s2){
    answer = "";
    string::iterator itr_s1 = s1.begin(), itr_s2 = s2.begin();
    int carry = 0;

    for(; itr_s1 < s1.end()&& itr_s2 < s2.end() ;itr_s1++, itr_s2++) {
        char ans = (*itr_s1+ *itr_s2 - 96)+carry;
        carry = ans/10;
        char digit = ans%10 + 48;
        answer.push_back(digit);
    }
    if(itr_s1==s1.end()){
        for(;itr_s2 < s2.end();itr_s2++){
            char ans = (*itr_s2 - 48)+carry;
            carry = ans/10;
            char digit = ans%10 + 48;
            answer.push_back(digit);
        }
        if(carry!= 0)
            answer.push_back(carry+48);
    }
    else if(itr_s2==s2.end()){
        for(;itr_s1 < s1.end();itr_s1++){
            char ans = (*itr_s1 - 48)+carry;
            carry = ans/10;
            char digit = ans%10 + 48;
            answer.push_back(digit);
            //cout<<digit<<endl<<carry<<endl<<endl;
        }
        if(carry!= 0)
            answer.push_back(carry+48);
    }
}

