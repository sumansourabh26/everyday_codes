#include<cstdio>

using namespace std;
class pai{
public:
    int integer, position;
};
int myfind(pai table[], int &no, int &n);
int main(){
    //ios::sync_with_stdio(false);
    int no_inp, no_q;
    scanf("%d%d",&no_inp,&no_q);

    pai table[no_inp];

    int no, dis=0;
    if(no_inp!=0){
        scanf("%d",&no);
        table[0].integer=no;
        table[0].position=0;
        dis++;
    }

    for(int i = 1; i < no_inp; i++){
        scanf("%d",&no);
        if(table[dis-1].integer != no){
            table[dis].integer = no;
            table[dis].position = i;
            dis++;
        }
    }
    int ans;
    while(no_q--){
        scanf("%d",&no);
        int ans = myfind(table, no, dis);
        printf("%d\n",ans);
    }
}
int myfind(pai table[], int &no,int& n){
    int low = 0, high = n-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(table[mid].integer>no){
            high = mid-1;
        }
        else if(table[mid].integer<no){
            low = mid+1;
        }
        else{
            return mid;
        }
    }
    return -1;
}
