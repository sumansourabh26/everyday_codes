#include<iostream>
#include<algorithm>

using namespace std;


int main(){
    vector<int> a = {0,1,2,3,4,5,6,7,8,9};
    int ans=0;
    do{
        if(a[0]!=0&&a[2]!=2&&a[4]!=4&&a[6]!=6&&a[8]!=8)
            ans++;
    }
    while(next_permutation(a.begin(),a.end()));
    cout<<ans;
}
