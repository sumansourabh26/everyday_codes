#include<iostream>
#include<math.h>
#include<string>
using namespace std;

double f(double x)
{
    return x*x - 2;
}

double g(double x)
{
    return sin(x) - 0.3;
}

double bijection(double xL,double xR, double epsilon, double(*pf)(double x))
{
    bool xL_is_positive = (*pf)(xL) >0;
    while(xR-xL>=epsilon)
    {
        double xM = (xL+xR)/2;
        bool xM_is_positive = (*pf)(xM)>0;
        if(xL_is_positive == xM_is_positive)
            xL = xM;
        else
            xR = xM;
    }
    return xL;
}
# define HALF_PI (1.570796326794897)
int main()
{
    double y = bijection(1.3,1.5,.0000000001,&f);
    cout<<"sqrt 2: "<<y<<" check square: "<< y*y<<endl;

    double z = bijection(0, HALF_PI ,0.000000001,&g);
    cout<<"sin inverse of 0.3: "<<y<<" check sin : "<< sin(z)<<endl;
}
