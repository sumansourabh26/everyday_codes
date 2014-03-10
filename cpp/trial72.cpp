#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string add(string s1, string s2);
int main(){

    string s1,s2;
    cin>>s1>>s2;
    string answer;
    string::iterator itr_s1 , itr_s2 ;
    string sum = "0", zero = "";


    for(itr_s2 = s2.end()-1;itr_s2 >= s2.begin() ;itr_s2--) {
        int carry =0;
        string temp_product="";
        for(itr_s1 = s1.end()-1;itr_s1 >= s1.begin(); itr_s1-- ){
            char digit = ((((*itr_s1)-48)*((*itr_s2)-48) + carry )  %10) + 48;
            carry = (((*itr_s1)-48)*((*itr_s2)-48) + carry )/10;
            temp_product.push_back(digit);
        }
        reverse(temp_product.begin(), temp_product.end());
        temp_product.append(zero.begin(), zero.end());
        zero.append("0");
        sum = add(temp_product, sum);
    }
    cout<<sum;
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
       // cout<<digit<<endl<<carry<<endl<<endl;
    }
    if(itr_s1<s1.begin()){
        for(;itr_s2 >= s2.begin();itr_s2--){
            char ans = (*itr_s2 - 48)+carry;
            carry = ans/10;
            char digit = ans%10 + 48;
            answer.push_back(digit);
         //   cout<<digit<<endl<<carry<<endl<<endl;
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
           // cout<<digit<<endl<<carry<<endl<<endl;
        }
        if(carry!= 0)
            answer.push_back(carry+48);
    }

    reverse(answer.begin(),answer.end());
    return answer;
}



