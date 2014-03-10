#include<simplecpp>
main_program{
int a,b,c,d,e;
bool prime;
cin>>a;

for(b=2;b<a;b++)
{
 for(c=2,prime=true;(c<b)&&(prime==(true));c++)
 {if(b%c==0)
  prime=false;}
 if (prime==true)
  (cout<<b<<",");
}}
