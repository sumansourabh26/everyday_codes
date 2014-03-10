#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    while(true){
        int length;
        cin>>length;
        if (length==0) break;
        vector<int> a(length,0);
        for(int i = 0; i < length; i++){
            cin>>a[i];
        }
        sort(a.begin(),a.end());
        int i; int ans = 0;
        for(i = length-1; i >= 0; i--){
            if(ans >= a[i]){
                cout<<ans<<endl;
                break;
            }
            else{
                ans = ans+1;
            }
        }
        if(i == -1) cout<<length<<endl;
    }
}
