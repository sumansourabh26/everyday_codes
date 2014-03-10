#include<iostream>
#include<string>

using namespace std;

int main(){
    int n;
    cin>>n;
    while(n--){
        string input;
        cin>>input;
        int siz = input.size();
        int i = 0;
        for( i = 0; i <= (siz-1)/2 ; i++){
            if(input[i] !=input[siz-i-1]){
                break;
            }
        }
        if(i > (siz-1)/2){cout<<"YES\n";}
        else cout<<"NO\n";
    }
}
