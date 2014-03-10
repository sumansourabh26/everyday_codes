#include<iostream>
#include <iomanip>
#include<cstdio>
#include<ios>
#include<cmath>
using namespace std;
#define sqr 1.7320508075688772935274463415059
int main(){
    int no;
    cin>>no;
    while(no--){
        double d,e,f;
        cin>>d>>e>>f;
        double s = (d+e+f)/2;
        double ans=((d*d+e*e+f*f)*sqr/4 + 3*sqrt(s*(s-d)*(s-e)*(s-f)))/2;
        //cout<<ans<<endl;
        cout.precision(2);
        cout<<fixed<< floor(ans*100+0.5) /100;
    }
}
