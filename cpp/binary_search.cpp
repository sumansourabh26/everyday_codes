#include<iostream>
#include<math.h>
#include<string>
using namespace std;

void search(int start, int end, int to_find, int i[])
{
    if(start==end)
        if(i[start]==to_find)
            cout<<"found";
        else cout<<"not found";
    else if(i[(start+end+1)/2] <= to_find )
        search((start+end+1)/2, end ,to_find, i );
    else
        search(start,(start+end-1)/2  ,to_find, i );
}

int main()
{
    int a[] = {0,3,7,134,156,157,1223,1233};
    while(true)
    {
        int i;
        cin>>i;
        search(0,7,i,a);
    }
}
