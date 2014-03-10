#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int total, no;
    cin>>no>>total;

    vector<int> price(no);

    for(int i=0; i<no;i++){
        cin>>price[i];
    }
    sort(price.begin(), price.end());

    int sum = 0, counter = 0;
    for(int i = 0; i < no; i++){
        sum = sum+price[i];
        if(sum <= total){
            counter = counter+1;
        }
        else
            break;
    }
    cout<<counter;
}
