#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
    int no;
    cin>>no;
    int total = 1;
    for(int i = 2; i <= no; i++){
        for(int j = 1; j <= sqrt(i); j++){
            if(i%j == 0) total++;
        }
        total = total;
    }
    cout<<total;
}
