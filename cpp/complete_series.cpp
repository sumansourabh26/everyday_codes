#include<iostream>
using namespace std;

int main(){
    int no;
    cin>>no;
    while(no--){
        long long a3, al3, sum;
        cin>>a3>>al3>>sum;

        long long n = 2*sum/(a3+al3);
        cout<<n<<endl;
        long long d = (al3-a3)/(n-5);
        long long a = a3-2*d;
        long long initial = a;
        for(int i = 0; i < n; i++){
            cout<<initial<<' ';
            initial = initial + d;
        }
        cout<<endl;
    }
}
