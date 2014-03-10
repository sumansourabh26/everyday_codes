#include<iostream>
#include<string.h>
#include<vector>
#include<sstream>
#include<map>
#include<cstdio>
using namespace std;
#define PB push_back
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
vs w; //stores each significant word of the phrase
string a; //acronym
int dp[95][95][95];
int solve(int apos,int wpos,int k)
{
	if(apos==a.size() && wpos==w.size()-1 && k) return 1;
	if(apos==a.size() || wpos==w.size()) return 0;
	int& res=dp[apos][wpos][k];
	if(res!=-1) return res;
	res=0;
	for(int i=k;i<w[wpos].size();i++)
		if(a[apos]==w[wpos][i]) res+=solve(apos+1,wpos,i+1);
	if(k) res+=solve(apos,wpos+1,0);
	return res;
}
int main()
{
	int n;
	while(cin>>n && n)
	{
		map<string,bool> sw;
		string s,abr;
		for(int i=0;i<n;i++){
			cin>>s;
			sw[s]=1; //mark insignificant words
		}
		getline(cin,s);
		while(getline(cin,s) && s!="LAST CASE")
		{
			w.clear();
			stringstream ss;
			ss<<s;
			ss>>a;
			abr=a;
			for(int i=0;i<a.size();i++) a[i]=tolower(a[i]);
			while(ss>>s)
				if(sw.find(s)==sw.end())
					w.PB(s);
			memset(dp,-1,sizeof(dp));
			int res=solve(0,0,0);
			if(res==0)
				cout<<abr<<" is not a valid abbreviation"<<endl;
			else
				cout<<abr<<" can be formed in "<<res<<" ways"<<endl;
		}
	}
}
