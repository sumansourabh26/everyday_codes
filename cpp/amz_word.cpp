#include<iostream>

using namespace std;

int main(){
    //while(1){
        int input;
        cin>>input;

        int total = 3, zt = 2;

        for(int i = 0; i<input-1; i++){
            zt = 2*(total-zt)+zt;
            total = total + zt;
        }
        cout<<total;

}
