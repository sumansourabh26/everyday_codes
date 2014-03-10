#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

double area(double a, double b, double c){
    double s  = (a+b+c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

int main(){
    int no_of_lines;
    cin>>no_of_lines;
    double a1,a2,a3,a4,a5,a6;

    for(int i = 0; i < no_of_lines; i++){
        cin>>a1>>a2>>a3>>a4>>a5>>a6;


        double s1 = a1*a1, s2=a2*a2, s3=a3*a3, s4=a4*a4, s5=a5*a5, s6=a6*a6;
        double volume;

        volume = sqrt((4*s1*s2*s3 - s1*(s2+s3-s6) - s2*(s3+s1-s5) -
                  s3*(s1+s2-s4)+(s2+s3-s6)*(s1+s3-s5)*(s1+s2-s4))) / 12;


        cout<<(volume*3)/(area(a1,a3,a5)+area(a2,a6,a3)+area(a4,a5,a6)+area(a1,a2,a4))<<endl;
    }


}
