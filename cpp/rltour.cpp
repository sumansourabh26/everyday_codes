#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<stack>
#include<stdio.h>
#include<queue>
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define in(x) scanf("%d",&x)
#define MOD 1000000007
#define INF 1e9
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
typedef long long ll;
typedef long l;

using namespace std;
const double pi = acos(-1.0);

int main()
{

      int t;
      in(t);
      while(t--)
      {
             int n,a;
             in(n);
             vector<int>v;
             for(int i=0;i<n;i++)
             {
                in(a);
                v.pb(a);
             }
             sort(v.begin(),v.end(),greater<int>());
             int arr[n];
             for(int i=0;i<n;i++)
             {
                in(arr[i]);
             }
             for(int i=n-1;i>=0;i--)
             {
                   int y=arr[i];
                   arr[i]=v[y];
                   v.erase(v.begin()+y);
             }
             for(int i=0;i<n;i++)
             {
                   if(i!=n-1)
                     printf("%d ",arr[i]);
                else
                     printf("%d\n",arr[i]);
             }
      }
    return 0;
}
