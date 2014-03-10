#include<iostream>
using namespace std;
int myfind(int table[], int no, int mini, int maxi){
    if(maxi<mini){
        return -1;
    }
    else{
        int mid = (mini+maxi)/2;
        if(table[mid]>no){
            return myfind(table,no,mini,mid-1);
        }
        else if(table[mid]<no){
            return myfind(table,no,mid+1,maxi);
        }
        else{
            return mid;
        }
    }
}
int main(){
    string str = "12";
    cout<< (str[0]-48)*10+str[1]-48;
}
