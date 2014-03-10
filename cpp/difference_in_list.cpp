#include<iostream>
#include<vector>
#include<cstdlib>
#include<algorithm>
using namespace std;

int main(){
    int length;
    cin>> length;

    int diff;
    cin>>diff;

    vector<int> input(length);
    for(int counter = 0; counter < length; counter++){
        cin>>input[counter];
    }
    sort(input.begin(), input.end());

    int sum = 0;
    vector<int> diff_temp(length);

    for(int i = 0; i<length;i++){
        diff_temp[i]=input[i] - input[0];
    }

    for(int i = 0; i<length; i++){
        int diff_now = diff_temp[i];
        for(int j = i+1; j<length;j++){
            if ( abs(diff_temp[j] - diff_now) == diff){
                sum = sum + 1;
                break;
            }
        }
    }
    cout<<sum;
}
