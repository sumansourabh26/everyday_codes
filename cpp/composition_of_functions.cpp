#include<iostream>
#include<math.h>
#include<string>
using namespace std;

double f(double x)
{
    return x*x;
}

double g(double x)
{
    return x+100;
}

double h(double x, double (*fx)(double z), double (*gx)(double y))
{
    return (*fx)((*gx)(x));
}

int main()
{
    double x;cin>>x;
    cout<< h(x, &f, &g);
}
