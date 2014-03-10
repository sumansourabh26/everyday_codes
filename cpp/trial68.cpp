#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
void add(string s1, string s2);
void subtract(string s1, string s2);
int main(){
    int no_of_input;
    cin>>no_of_input;

    string input[no_of_input];
    for(int i = 0; i<no_of_input; i++){
        cin>>input[i];
    }

    for(int i = 0; i < no_of_input; i++){
        if(input[i].find('*') < 1000){
            int pos = input[i].find('*');
            string s1;
            s1.assign(input[i], 0,pos);
            string s2;
            //cout<<s1.size();
            s2.assign(input[i], pos + 1, input[i].size() - pos - 1);
            //cout<<s2;cout<<s2.size();
           // multiply(s1,s2);
        }

        else if(input[i].find('+') < 1000){
            int pos = input[i].find('+');
            string s1;
            s1.assign(input[i], 0,pos);
            string s2;
            //cout<<s1.size();
            s2.assign(input[i], pos + 1, input[i].size() - pos - 1);
            //cout<<s2;cout<<s2.size();
            add(s1,s2);
        }
        else if(input[i].find('-') < 1000){
            int pos = input[i].find('-');
            string s1;
            s1.assign(input[i], 0,pos);
            string s2;
            //cout<<s1.size();
            s2.assign(input[i], pos + 1, input[i].size() - pos - 1);
            //cout<<s2;cout<<s2.size();
            subtract(s1,s2);
        }
    }
}

void add(string s1, string s2){
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

void subtract(string s1, string s2){
    cout<<s1<<' '<<s2<<endl;
    string answer;
    string::iterator itr_s1 = s1.end()-1, itr_s2 = s2.end()-1;

    for(; itr_s1 >= s1.begin()&& itr_s2 >= s2.begin() ;itr_s1--, itr_s2--) {
        if(*itr_s1>= *itr_s2){
            char digit = (*itr_s1 - *itr_s2 ) + 48;
            answer.push_back(digit);
        }
        else{
            //char ans = (10 + *itr_s1 - *itr_s2);
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
    cout<<answer;
}

