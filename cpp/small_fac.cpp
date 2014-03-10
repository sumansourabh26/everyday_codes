#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string add(string s1, string s2);
string multiply(string s1, int s2);

int main(){
    string fact[101];
    fact[0]="1";
    fact[1]="1";
    for(int i = 2; i<=100; i++){
        fact[i] = multiply(fact[i-1], i);
    }
    int no_of_input;
    cin>>no_of_input;
    for(int i = 0; i < no_of_input; i++){
        int input;
        cin>>input;
        cout<<fact[input]<<endl;
    }
}

string multiply(string s1, int s2){
    string sum = "0", zero = "";
    for(int i = s2; i != 0; i = i/10 ){
        string temp = "";
        for(int j = 0; j < i%10; j++){
            temp = add(temp ,s1);
        }
        sum = add(sum, temp.append(zero.begin(), zero.end()));
        zero.append("0");
    }
    return sum;
}

string add(string s1, string s2){
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
        }
        if(carry!= 0)
            answer.push_back(carry+48);
    }

    reverse(answer.begin(),answer.end());
    return answer;
}
