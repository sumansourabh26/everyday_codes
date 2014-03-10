#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

int main()
{
    cout<<"enter the term";
    int i = 0;
    double x;
    cin>>x;
    double a = floor(x);
    while(a != x && i<5)
    {
        cout<<"the "<<i<<"th term is"<<a<<"\n";
        x = 1/(x - a);
        i = i + 1;
        a = floor(x);
    }
}

