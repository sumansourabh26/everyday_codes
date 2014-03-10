#include<iostream>

using namespace std;

int main(){
    bool is_marked[20004];
    for(int i = 0; i < 20004; i++)
        is_marked[i]=false;
//    cout<<is_marked[10];
    int no_input;
    cin>>no_input;


    int sum = 0;
    int input;
    while(no_input--){
        cin>>input;
        if((is_marked[input-1])&&(is_marked[input+1])){
            sum = sum - 1;
        }
        else if((!is_marked[input-1])&&(!is_marked[input+1])){
            sum = sum + 1;
        }

        is_marked[input] = true;
        cout<<sum<<endl;
    }
    cout<<"Justice\n";
}
