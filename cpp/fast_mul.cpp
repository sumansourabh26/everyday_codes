#include<cstdio>
#include<string>
#include<iostream>
//#include<algorithm>
using namespace std;
string& add(string &s1, string &s2);
void multiply(string &s1, string &s2);
string answer;

string sum;
int main(){
    string s1,s2;
    int no_of_input;
    //scanf("%d",&no_of_input);
    cin>>no_of_input;
    for(int i = 0; i<no_of_input;i++){
        cin>>s1>>s2;
        //scanf("%s%s",&s1,&s2);
        if(s1=="0"||s2=="0"){
            cout<<"0"<<endl;
        }
        else{
            multiply(s1,s2);
            int s = sum.size()-1;
            for(; s >=0; s--){
                if(sum[s] !='0')
                    break;
            }
            for(; s >= 0; s--){
                cout<<sum[s];
                //printf("%s",sum[s]);
            }
            cout<<endl;
        }
    }
}

void multiply(string &s1, string &s2){
    string::iterator itr_s1 , itr_s2 ;
    sum = "0";
    string zero = "",temp;
    int carry ;
    char ta;

    for(itr_s2 = s2.end()-1;itr_s2 >= s2.begin() ;itr_s2--) {
        temp = zero; carry = 0;
        for(itr_s1 = s1.end()-1; itr_s1 >= s1.begin(); itr_s1--){
            ta = ((*itr_s1)-48)*((*itr_s2)-48) +carry + 48;
            temp.push_back((ta - 48)%10 +48);
            carry = (ta - 48)/10;
        }
        temp.push_back(carry+48);
        sum = add(sum, temp);
        zero.push_back('0');
    }
}

string& add(string &s1, string &s2){
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
    return answer;
}
