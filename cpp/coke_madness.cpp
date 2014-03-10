#include<iostream>

using namespace std;

int main(){
    int no_test;
    cin>>no_test;
    for(int i = 1; i <= no_test; i++){
        int min_till_now = 1,no_input, sum = 0;

        cin>>no_input;
        while(no_input--){
            int input;
            cin>>input;

            sum = sum+input;

            if(sum < min_till_now){
                min_till_now = sum;
            }

        }//Scenario #1: 7

        if(min_till_now >= 0) cout<<"Scenario #"<<i<<':'<<" 1\n\n";
        else
            cout<<"Scenario #"<<i<<": "<<-(min_till_now-1)<<endl<<endl;


    }


}
