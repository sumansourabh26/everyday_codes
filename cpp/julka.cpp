#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string add(string &s1, string &s2);
string subtract(string &s1, string &s2);
string divideby2(string &s1);
int main (){

    string s1;
    for(int i = 0; i < 10; i++){
        string in1, in2;
        cin>>in1>>in2;
        string sum = add(in1,in2);
        string sumby2 = divideby2(sum);
        string diffby2 = subtract(in1, sumby2);
        cout<<sumby2<<endl<<diffby2<<endl;
    }
}
string divideby2(string &s1){
    string::iterator itr = s1.end()-1, itr2 = s1.end()-2;
    string answer;
    for(;itr != s1.begin()-1;itr--,itr2--){
        if(itr2- s1.begin() >= 0){
            if(*itr2%2 == 0){
                answer.push_back((*itr)/2 + 24);
            }
            else if(*itr2%2 != 0){
                answer.push_back((*itr)/2 + 29);
                *itr2 = *itr2 - 1;
            }
        }
        else{
            if(*itr != '0')
                answer.push_back((*itr)/2 + 24);
        }
    }
    reverse(answer.begin(),answer.end());
    return answer;

}
string add(string &s1, string &s2){
    string answer;
    string::iterator itr_s1 = s1.end()-1, itr_s2 = s2.end()-1;
    int carry = 0;

    for(; itr_s1 >= s1.begin()&& itr_s2 >= s2.begin() ;itr_s1--, itr_s2--) {
        char ans = (*itr_s1+ *itr_s2 - 96)+carry;
        carry = ans/10;
        char digit = ans%10 + 48;
        answer.push_back(digit);
    }
    if(itr_s1<s1.begin()){
        for(;itr_s2 >= s2.begin();itr_s2--){
            char ans = (*itr_s2 - 48)+carry;
            carry = ans/10;
            char digit = ans%10 + 48;
            answer.push_back(digit);
        }
        if(carry!= 0)
            answer.push_back(carry+48);
    }
    else if(itr_s2<s2.begin()){
        for(;itr_s1 >= s1.begin();itr_s1--){
            char ans = (*itr_s1 - 48)+carry;
            carry = ans/10;
            char digit = ans%10 + 48;
            answer.push_back(digit);
            //cout<<digit<<endl<<carry<<endl<<endl;
        }
        if(carry!= 0)
            answer.push_back(carry+48);
    }

    reverse(answer.begin(),answer.end());
    return answer;
}

string subtract(string &s1, string &s2){
    string answer;
    string::iterator itr_s1 = s1.end()-1, itr_s2 = s2.end()-1;

    for(; itr_s1 >= s1.begin()&& itr_s2 >= s2.begin() ;itr_s1--, itr_s2--) {
        if(*itr_s1>= *itr_s2){
            char digit = (*itr_s1 - *itr_s2 ) + 48;
            answer.push_back(digit);
        }
        else{
            *(itr_s1 -1) = *(itr_s1 - 1) -1;
            char digit = (10 + *itr_s1 - *itr_s2) + 48;
            answer.push_back(digit);
        }
    }
    if(itr_s1 >= s1.begin() ){
        for(; itr_s1 >= s1.begin(); itr_s1--){
            if(*itr_s1 < 48){
                *(itr_s1 -1) = *(itr_s1 -1 ) -1;
                char digit = 10 + *itr_s1;
                answer.push_back(digit);
            }
            if(*itr_s1 >= 48){
                answer.push_back(*itr_s1);
            }
        }
    }
    while(true){
        if(*(answer.end()-1)== 48){
            answer.erase(answer.end()-1);
        }
        else
            break;
    }
    reverse(answer.begin(),answer.end());
    return answer;
}

