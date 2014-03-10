#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){

    string s1,s2;
    cin>>s1>>s2;
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
