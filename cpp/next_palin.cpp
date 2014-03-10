#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(){
    while(true){
        string input;
        cin>>input;
        int length = input.length();

        string::iterator right = input.begin()+(length/2),
                        left = input.begin()+((length-1)/2);

        //cout<< *left<<' '<<*right<<endl;
        if(*left>*right){
            cout<<input.substr(0,length/2);
        }

        else if(*left<=*right){
            *left++;
            *right = *left;
        }
        else if(*left==*right && *left!=9){


        }

    }
}
