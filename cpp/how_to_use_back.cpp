#include<simplecpp>
#include<string>
#include<vector>
#include<algorithm>

int main() {
   using namespace std;   
   vector <int> v1;
   
   v1.push_back( 10 );
   v1.push_back( 11 );
   v1.push_back( 13 );
   v1.push_back( 14 );

   int& i = v1.back();
   const int& ii = v1.front( );

   cout << "The last integer of v1 is " << i << endl;
   i--;
   cout << "The next-to-last integer of v1 is "<< ii << endl;
}
