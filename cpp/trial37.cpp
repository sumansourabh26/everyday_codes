#include<iostream>
#include<vector>
using namespace std;

int main(){
    int length;cin>>length;
    vector<int> a, b;
    vector<int>::iterator itr;
    for(int i = 0; i<length;i++){
        a.push_back(i+1);
    }
    for(int i= 0 ; i<length ;i++){
        b.push_back(a[length-i-1]);
    }
     for(itr = b.begin(); itr != b.end(); itr++){
        cout<< *itr<<endl;
    }

    while(a != b){
        m =
    }

}
