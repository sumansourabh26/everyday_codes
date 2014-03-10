#include<iostream>
#include<math.h>
#include<string>
using namespace std;

void f(int x[])
{
    x[3] = x[3] +10;
}

int main()
{
    int a[] = {1,2,3,4,5};
    f(a);
    cout<<a[3];
}
