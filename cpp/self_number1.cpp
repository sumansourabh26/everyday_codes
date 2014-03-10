#include<iostream>
#include<algorithm>

using namespace std;



int main(){
    for(int input = 1; input < 100000; input++){
        bool found = false;
        int i;
        for(i = 1; i < input; i++){
            int sum = i, temp = i;

            while(temp!=0){
                sum = sum + temp%10;
                temp = temp/10;
            }

            if(sum==input){
                found = true;
                break;
            }
        }
        if(!found) cout<<input<<endl;
    }
}
