#include<simplecpp>
#include<string>
#include<vector>
#include<algorithm>
int main( )
{
   using namespace std;
   vector <int> v1;
   vector <int>::iterator v1_Iter;
   
   v1.push_back( 1 );
   v1.push_back( 2 );

   for ( v1_Iter = v1.begin( ) ; v1_Iter != v1.end( ) ; v1_Iter++ )
      cout << *v1_Iter << endl;
}
