#include<iostream>
#include<algorithm>

using namespace std;



int main(){
    //cout<<"enter number to be checked\n";
    while(true){
        int input;
        cin>>input;
        int i;
        for(i = 1; i < input; i++){
            int sum = i, temp = i;

            while(temp!=0){
                sum = sum + temp%10;
                temp = temp/10;
            }

            if(sum==input){
                cout<<"found:"<<i<<endl;
                break;
            }
        }
    }
}
