#include <iostream>
#include <string>
#include<algorithm>

using namespace std;

int main (){
    while(1){
        cout<<"enter new text\n";
        vector<int> counter(26,0);
        string input; cin >> input;
        for(int i = 0; i < input.length(); i++){
            char x = input[i];
            int conv = x;
            counter[conv-65]++;
        }
        //sort(counter.begin(), counter.end());

        for(int i = 0; i < 26; i++){
            char x = i+65;
            cout<< "count of "<<x<<" is "<<counter[i]<<endl;
        }
    }
}
