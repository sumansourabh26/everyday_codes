#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    while(true){
        int no;
        scanf("%d",&no);//cin>>no;
        if(no==0)break;
        int child[no], cost[no];
        for(int i = 0; i < no; i++) scanf("%llu",&child[i]);// cin>>child[i];
        for(int i = 0; i < no; i++) scanf("%llu",&cost[i]);//cin>>cost[i];
        unsigned long long ans = 0;
        sort(child,child+no);
        sort(cost, cost+no);
        for(int i = 0; i < no; i++){
            ans = ans + child[i]*cost[no-1-i];
        }
        cout<<ans<<endl;
    }
}
