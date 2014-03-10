#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int friends, no_of_flowers;
    cin>>friends>>no_of_flowers;

    vector<int> flowers(no_of_flowers);

    for(int i = 0; i < no_of_flowers;i++){
        cin>>flowers[i];
    }
    sort(flowers.begin(), flowers.end());

    vector<int>::iterator itr = flowers.end() -1;
    long long sum=0;
    for(int i = 1; ;i++ ){
        for(int j = 0;j<friends;j++){
            if(itr==flowers.begin()){
                sum = sum + i*(*itr);
                break;
            }
            else{
                sum = sum + i*(*itr);
                itr--;
            }
        }
        if(itr==flowers.begin()){
            break;
        }

    }
    cout<<sum;
}
