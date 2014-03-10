#include<iostream>
#include<vector>

using namespace std;

class string_pair{
public:

    vector<int> s1;
    vector<int> s2;
    void setval(vector<int> str, vector<int>substr){
        s1 = str; s2 = substr;
    }
    void match(){
        vector<int>::iterator itr_str = s1.begin(), itr_substr = s2.begin(),itr_first_match;
        bool found = false;

        for(; itr_str < s1.end()+1-s2.size(); ){
            if(found == true){
                    break;
            }
            else if ((*itr_str)==(*s2.begin())){
                itr_first_match = itr_str;

                while(true){
                    if(itr_substr == s2.end()){
                        cout<<1<<endl;found = true;
                        break;
                    }
                     else if(itr_str == s2.end()){
                        break;
                    }
                     else if((*itr_substr) == (*itr_str)){
                        itr_substr++;
                        itr_str++;
                    }
                    else if((*itr_substr) != (*itr_str)){
                        itr_str = itr_first_match+1;
                        itr_substr = s2.begin();
                        break;
                    }

                }

            }
            else{
                itr_str++;
            }


        }
        if(itr_str == s1.end()+1-s2.size()){
            cout<<0;
        }
    }

};

int main(){
    string_pair series[24];

    string str, substr;
    vector<int> str_vec, substr_vec;

    for(int i = 0; i<24;i++){
        cin>>str;
        cin>>substr;
        for(int j= 0; j<str.size(); j++){
            str_vec.push_back(str[j]);
        }
        for(int j= 0; j<substr.size(); j++){
            substr_vec.push_back(substr[j]);
        }
        series[i].setval(str_vec, substr_vec);
        series[i].match();
    }
}
