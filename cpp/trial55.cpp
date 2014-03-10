#include<iostream>
#include<vector>

using namespace std;

void fillvector(vector<int>& a);

int main()
{
    vector<int> myvector;
    myvector.push_back(10);
    myvector.push_back(20);
    myvector.push_back(30);

    fillvector(myvector);
    cout<<myvector.at(1);
}

void fillvector(vector<int>& v)
{
    v[1]=100;
}
