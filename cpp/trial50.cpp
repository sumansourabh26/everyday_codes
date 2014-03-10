#include<iostream>

using namespace std;

int main(){
    int suman[4];
    suman[0]=100;
    suman[1]=101;
    suman[2]=102;
    suman[3]=103;

    int *p0 = &suman[0];
    int *p1 = &suman[1];
    int *p2 = &suman[2];
    int *p3 = &suman[3];
    cout<<p0<<endl<<p1<<endl<<p2<<endl<<p3<<endl;

    p0++;
    cout<<p0<<endl<<p1<<endl<<*p0<<endl<<*p1<<endl;
    *p0 = *p0+1000;
    cout<<*p0<<endl<<*p1;


}
