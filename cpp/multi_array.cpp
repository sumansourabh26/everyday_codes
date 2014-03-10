#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<vector<int> > numbers;
    vector<int> num1;

    num1.push_back(00);
    num1.push_back(10);
    num1.push_back(20);

    numbers.push_back(num1);
    cout<<numbers[0][2]<<endl;
    numbers.push_back(num1);
    cout<<numbers[1][2]<<endl;
}
