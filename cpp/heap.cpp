#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;
int main (){
    int myint[] = {1,2,3,4,56,-7};
    vector<int> v(myint, myint+5);

    make_heap(v.begin(),v.end());
    cout<< *v.begin()<<endl;
    v.push_back(100);
    make_heap(v.begin(),v.end());
    cout<< *(v.end()--)<<endl;
}
