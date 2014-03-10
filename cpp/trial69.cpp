#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(){
    string s1,s2;
    cin>>s1>>s2;
    string answer;
    string::iterator itr_s1 = s1.end()-1, itr_s2 = s2.end()-1;
    int carry = 0;

    for(; itr_s1 >= s1.begin()&& itr_s2 >= s2.begin() ;itr_s1--, itr_s2--) {
        char ans = (*itr_s1+ *itr_s2 - 96)+carry;
        carry = ans/10;
        char digit = ans%10 + 48;
        answer.push_back(digit);
        cout<<digit<<endl<<carry<<endl<<endl;
    }
    if(itr_s1<s1.begin()){
        for(;itr_s2 >= s2.begin();itr_s2--){
            char ans = (*itr_s2 - 48)+carry;
            carry = ans/10;
            char digit = ans%10 + 48;
            answer.push_back(digit);
            cout<<digit<<endl<<carry<<endl<<endl;
        }
        if(carry!= 0)
            answer.push_back(carry+48);
    }
    if(itr_s2<s2.begin()){
        for(;itr_s1 >= s1.begin();itr_s1--){
            char ans = (*itr_s1 - 48)+carry;
            carry = ans/10;
            char digit = ans%10 + 48;
            answer.push_back(digit);
            cout<<digit<<endl<<carry<<endl<<endl;
        }
        if(carry!= 0)
            answer.push_back(carry+48);
    }

    reverse(answer.begin(),answer.end());
    cout<<answer;



}
