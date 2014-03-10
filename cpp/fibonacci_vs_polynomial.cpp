
#include<iostream>
using namespace std;

int poly(int a[],int n,int x ){
    int sum = 0;
    for(int i = n; i>=0; i--){
        sum = sum*x + a[i];
    }
    return sum;
}

int main(){

}
