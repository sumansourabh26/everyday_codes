#include<simplecpp>
#include<string>
#include<vector>
#include<algorithm>
int main( )
{
int main( )
{
   using namespace std;   
   vector <int> v1;
   
   v1.push_back( 10 );
   v1.push_back( 20 );
   v1.push_back( 30 );

   cout << "The size of v1 is " << v1.size( ) << endl;
   v1.clear( );
   cout << "The size of v1 after clearing is " << v1.size( ) << endl;
}
