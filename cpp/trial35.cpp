#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void fun(vector<int> chef)
{
    vector<int>::iterator target;
    target=min_element(chef.begin(),chef.end());
    *(target-1)=*(target-1)+*target;
    *(target+1)=*(target+1)+*target;
    *target = -1* *target;
    for(target=chef.begin();target!=chef.end();target++)
        cout<<*target<<endl;
}

int main()
{
    int trials;
    cin>>trials;

    for(int i=0;i<trials;i++)
    {
        int no_of_chef;cin>>no_of_chef;
        vector<int> chef;
        vector<int>::iterator itr;
        for(int i=0;i<no_of_chef;i++)
        {
            int value;cin>>value;
            chef.push_back(value);
        }
        //cout<<
        fun(chef);
    }
}
