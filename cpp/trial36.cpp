
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;


int main()
{
    const int VECTOR_SIZE = 8 ;

    // Define a template class vector of int
    typedef vector<int > IntVector ;

    //Define an iterator for template class vector of strings
    typedef IntVector::iterator IntVectorIt ;

    IntVector Numbers(VECTOR_SIZE) ;

    IntVectorIt start, end, it, location ;

    // Initialize vector Numbers
    Numbers[0] = 4 ;
    Numbers[1] = 10 ;
    Numbers[2] = 10 ;
    Numbers[3] = 30 ;
    Numbers[4] = 69 ;
    Numbers[5] = 70 ;
    Numbers[6] = 96 ;
    Numbers[7] = 100 ;

    start = Numbers.begin() ;   // location of first
                                // element of Numbers

    end = Numbers.end() ;       // one past the location
                                // last element of Numbers

    // print content of Numbers
    cout << "Numbers { " ;
    for(it = start; it != end; it++)
        cout << *it << " " ;
    cout << " }\n" << endl ;

    // return the minimum element in the Numbers
    location = min_element(Numbers.begin(), Numbers.end()) ;

    cout << "The minimum element in Numbers is: "
        << *location << endl ;
}
