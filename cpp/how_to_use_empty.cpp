#include<simplecpp>
#include<string>
#include<vector>
#include<algorithm>int main( )
{
   using namespace std;   
   vector <int> v1;

   v1.push_back( 10 );

   if ( v1.empty( ) )
      cout << "The vector is empty." << endl;
   else
      cout << "The vector is not empty." << endl;
}
