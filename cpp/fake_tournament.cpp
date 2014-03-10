
#include<iostream>
#include<vector>

using namespace std;

int main(){
    int no_of_input;
    cin>>no_of_input;

    long long int q;
    for(int i = 0; i < no_of_input; i++){
        cin>>q;
        cout<< (q-1)*250 + 192;
    }

}
