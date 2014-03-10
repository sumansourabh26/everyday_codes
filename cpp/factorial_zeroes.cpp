#include<iostream>

using namespace std;
int y = 5;

int main(){
    int no_of_input;
    cin>>no_of_input;
    for(int i = 0; i < no_of_input;i++){
        int a ;//, b =2;
        cin>>a;

        int sum = 0;
        while(a>=y){
            int d = (a/y);
            sum = sum + d;
            a = d;
        }
        cout<<sum<<endl;
    }


}
