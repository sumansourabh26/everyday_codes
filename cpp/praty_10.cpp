#include<stdio.h>
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<utility>
using namespace std;


// 0->pre
// 1->in
// 2->post

bool isCorrect(string s){
	for(unsigned int i=0; i<s.length(); i++){
		if(s[i]=='0')
			return false;
	}
	return true;
}

struct treeString
{
	string left, right;
	char root;
};

int functionStates[][6]={{0,0,1,1,2,2},{0,0,1,2,1,2},{0,0,1,2,2,1},{0,0,2,1,1,2},
                        {0,0,2,1,2,1},{0,0,2,2,1,1}, {0,1,0,1,2,2},{0,1,0,2,1,2},
                        {0,1,0,2,2,1},{0,1,1,0,2,2},{0,1,1,2,0,2},{0,1,1,2,2,0},
                        {0,1,2,0,1,2},{0,1,2,0,2,1},{0,1,2,1,0,2},{0,1,2,1,2,0},
                        {0,1,2,2,0,1},{0,1,2,2,1,0}, {0,2,0,1,1,2},{0,2,0,1,2,1},
                        {0,2,0,2,1,1},{0,2,1,0,1,2},{0,2,1,0,2,1},{0,2,1,1,0,2},
                        {0,2,1,1,2,0},{0,2,1,2,0,1},{0,2,1,2,1,0},{0,2,2,0,1,1},
                        {0,2,2,1,0,1},{0,2,2,1,1,0}, {1,0,0,1,2,2},{1,0,0,2,1,2},
                        {1,0,0,2,2,1},{1,0,1,0,2,2},{1,0,1,2,0,2},{1,0,1,2,2,0},
                        {1,0,2,0,1,2},{1,0,2,0,2,1},{1,0,2,1,0,2},{1,0,2,1,2,0},
                        {1,0,2,2,0,1},{1,0,2,2,1,0}, {1,1,0,0,2,2},{1,1,0,2,0,2},
                        {1,1,0,2,2,0},{1,1,2,0,0,2},{1,1,2,0,2,0},{1,1,2,2,0,0},
                        {1,2,0,0,1,2},{1,2,0,0,2,1},{1,2,0,1,0,2},{1,2,0,1,2,0},
                        {1,2,0,2,0,1},{1,2,0,2,1,0}, {1,2,1,0,0,2},{1,2,1,0,2,0},
                        {1,2,1,2,0,0},{1,2,2,0,0,1},{1,2,2,0,1,0},{1,2,2,1,0,0},
                        {2,0,0,1,1,2},{2,0,0,1,2,1},{2,0,0,2,1,1},{2,0,1,0,1,2},
                        {2,0,1,0,2,1},{2,0,1,1,0,2}, {2,0,1,1,2,0},{2,0,1,2,0,1},
                        {2,0,1,2,1,0},{2,0,2,0,1,1},{2,0,2,1,0,1},{2,0,2,1,1,0},
                        {2,1,0,0,1,2},{2,1,0,0,2,1},{2,1,0,1,0,2},{2,1,0,1,2,0},
                        {2,1,0,2,0,1},{2,1,0,2,1,0}, {2,1,1,0,0,2},{2,1,1,0,2,0},
                        {2,1,1,2,0,0},{2,1,2,0,0,1},{2,1,2,0,1,0},{2,1,2,1,0,0},
                        {2,2,0,0,1,1},{2,2,0,1,0,1},{2,2,0,1,1,0},{2,2,1,0,0,1},
                        {2,2,1,0,1,0},{2,2,1,1,0,0}};

treeString partition(int i, int traversalType, string s){
	//i is leftLength
	treeString ans;
	if(traversalType==0){
		ans.left=s.substr(1, i);
		ans.right=s.substr(i+1);
		ans.root=s[0];
	}
	else if(traversalType==1){
		ans.left=s.substr(0, i);
		ans.right=s.substr(i+1);
		ans.root=s[i];
	}
	else if(traversalType==2){
		ans.left=s.substr(0, i);
		ans.right=s.substr(i, s.length()-i-1);
		ans.root=s[s.length()-1];
	}
	return ans;
}

pair<string, string> checkState(string s1, string s2, string s3, int i1, int i2, int i3, int func[6]){

	if(s1.length()==0)
		return make_pair("", "");
	if(s1.length()==1)
	{
		if(s1==s2 && s2==s3)
		{
			return make_pair(s1, s1);
		}
		else
		return make_pair("", "");
	}
	//cout<<s1<<" "<<s2<<" "<<s3<<" "<<i1<<" "<<i2<<" "<<i3<<endl<<endl;

	if(i1==0 && i2==0 && i3==1){
		if(s1!=s2){
			return pair<string, string>("0", "0");
		}
		else{
            unsigned int rootIndex=s3.find(s1[0]);

            if(rootIndex<0 || rootIndex >= s1.length())
                return pair<string, string>("0", "0");
            else{
                string left1=s1.substr(1, rootIndex), left2=s2.substr(1, rootIndex), left3=s3.substr(0, rootIndex);

                string right1=s1.substr(rootIndex+1), right2=s2.substr(rootIndex+1), right3=s3.substr(rootIndex+1);

                pair<string, string> left=checkState(left1, left2, left3, func[0], func[0], func[2], func);
                pair<string, string> right=checkState(right1, right2, right3, func[1], func[1], func[3], func);

                if(!(isCorrect(left.first) && isCorrect(right.first)))
                {
                    return pair<string, string>("0", "0");
                }
                return pair<string, string>(s1[0]+left.first+right.first, left.second+s1[0]+right.second);
            }
		}

	}
	else if(i1==0 && i2==1 && i3==0){
		if(s1!=s3){

			return pair<string, string>("0", "0");
		}
		unsigned int rootIndex=s2.find(s1[0]);

		if(rootIndex<0 || rootIndex >= s1.length())
			return pair<string, string>("0", "0");

		string left1=s1.substr(1, rootIndex), left2=s2.substr(0, rootIndex), left3=s3.substr(1, rootIndex);

		string right1=s1.substr(rootIndex+1), right2=s2.substr(rootIndex+1), right3=s3.substr(rootIndex+1);

		pair<string, string> left=checkState(left1, left2, left3, func[i1*2], func[i2*2], func[i3*2], func);
		pair<string, string> right=checkState(right1, right2, right3, func[i1*2+1], func[i2*2+1], func[i3*2+1], func);

		if(!(isCorrect(left.first) && isCorrect(right.first)))
		{
			return pair<string, string>("0", "0");
		}
		return make_pair(s1[0]+left.first+right.first, left.second+s1[0]+right.second);

	}

	else if(i1==1 && i2==0 && i3==0){
		if(s2!=s3){

			return pair<string, string>("0", "0");
		}
		unsigned int rootIndex=s1.find(s2[0]);

		if(rootIndex<0 || rootIndex >= s1.length())
			return pair<string, string>("0", "0");

		string left1=s1.substr(0, rootIndex), left2=s2.substr(1, rootIndex), left3=s3.substr(1, rootIndex);

		string right1=s1.substr(rootIndex+1), right2=s2.substr(rootIndex+1), right3=s3.substr(rootIndex+1);

		pair<string, string> left=checkState(left1, left2, left3, func[i1*2], func[i2*2], func[i3*2], func);
		pair<string, string> right=checkState(right1, right2, right3, func[i1*2+1], func[i2*2+1], func[i3*2+1], func);

		if(!(isCorrect(left.first) && isCorrect(right.first)))
		{
			return pair<string, string>("0", "0");
		}
		return make_pair(s2[0]+left.first+right.first, left.second+s2[0]+right.second);

	}

	else if(i1==0 && i2==2 && i3==0){
		if(s1!=s3){

			return pair<string, string>("0", "0");
		}

		vector<pair<string, string> > v;
		for(unsigned int k=1; k<=s1.length()-1; k++)
		{
			string left1=s1.substr(1, k), left2=s2.substr(0, k), left3=s3.substr(1, k);
			string right1=s1.substr(k+1), right2=s2.substr(k, s1.length()-1-k), right3=s3.substr(k+1);

			pair<string, string> left=checkState(left1, left2, left3, func[i1*2], func[i2*2], func[i3*2], func);
			pair<string, string> right=checkState(right1, right2, right3, func[i1*2+1], func[i2*2+1], func[i3*2+1], func);

			if(isCorrect(left.first) && isCorrect(right.first))
				v.push_back(make_pair(s1[0]+left.first+right.first, left.second+s1[0]+right.second));
		}
		sort(v.begin(), v.end());
		return v[0];
	}

	else if(i1==0 && i2==0 && i3==2){
		if(s1!=s2){

			return pair<string, string>("0", "0");
		}

		vector<pair<string, string> > v;
		for(unsigned int k=1; k<=s1.length()-1; k++)
		{
			string left1=s1.substr(1, k), left2=s2.substr(1, k), left3=s3.substr(0, k);
			string right1=s1.substr(k+1), right2=s2.substr(k+1), right3=s3.substr(k, s1.length()-1-k);

			pair<string, string> left=checkState(left1, left2, left3, func[i1*2], func[i2*2], func[i3*2], func);
			pair<string, string> right=checkState(right1, right2, right3, func[i1*2+1], func[i2*2+1], func[i3*2+1], func);

			if(isCorrect(left.first) && isCorrect(right.first))
				v.push_back(make_pair(s1[0]+left.first+right.first, left.second+s1[0]+right.second));
		}
		sort(v.begin(), v.end());
		return v[0];
		//check all
	}

	else if(i1==2 && i2==0 && i3==0){
		if(s3!=s2){

			return pair<string, string>("0", "0");
		}

		vector<pair<string, string> > v;
		for(unsigned int k=1; k<=s1.length()-1; k++)
		{
			string left1=s1.substr(0, k), left2=s2.substr(1, k), left3=s3.substr(1, k);
			string right1=s1.substr(k, s1.length()-1-k), right2=s2.substr(k+1), right3=s3.substr(k+1);

			pair<string, string> left=checkState(left1, left2, left3, func[i1*2], func[i2*2], func[i3*2], func);
			pair<string, string> right=checkState(right1, right2, right3, func[i1*2+1], func[i2*2+1], func[i3*2+1], func);

			if(isCorrect(left.first) && isCorrect(right.first))
				v.push_back(make_pair(s2[0]+left.first+right.first, left.second+s2[0]+right.second));
		}
		sort(v.begin(), v.end());
		return v[0];
	}



	else if(i1==0 && i2==1 && i3==2){
		unsigned int rootIndex=s2.find(s1[0]);

		if(rootIndex<0 || rootIndex >= s1.length())
			return pair<string, string>("0", "0");

		string left1=s1.substr(1, rootIndex), left2=s2.substr(0, rootIndex), left3=s3.substr(0, rootIndex);

		string right1=s1.substr(rootIndex+1), right2=s2.substr(rootIndex+1), right3=s3.substr(rootIndex+1, s1.length()-1-rootIndex);

		pair<string, string> left=checkState(left1, left2, left3, func[i1*2], func[i2*2], func[i3*2], func);
		pair<string, string> right=checkState(right1, right2, right3, func[i1*2+1], func[i2*2+1], func[i3*2+1], func);

		if(!(isCorrect(left.first) && isCorrect(right.first)))
		{
			return pair<string, string>("0", "0");
		}
		return make_pair(s1[0]+left.first+right.first, left.second+s1[0]+right.second);

	}

	else if(i1==0 && i2==2 && i3==1){
		unsigned int rootIndex=s3.find(s1[0]);

		if(rootIndex<0 || rootIndex >= s1.length())
			return pair<string, string>("0", "0");

		string left1=s1.substr(1, rootIndex), left2=s2.substr(0, rootIndex), left3=s3.substr(0, rootIndex);

		string right1=s1.substr(rootIndex+1), right2=s2.substr(rootIndex+1, s1.length()-1-rootIndex), right3=s3.substr(rootIndex+1);

		pair<string, string> left=checkState(left1, left2, left3, func[i1*2], func[i2*2], func[i3*2], func);
		pair<string, string> right=checkState(right1, right2, right3, func[i1*2+1], func[i2*2+1], func[i3*2+1], func);

		if(!(isCorrect(left.first) && isCorrect(right.first)))
		{
			return pair<string, string>("0", "0");
		}
		return make_pair(s1[0]+left.first+right.first, left.second+s1[0]+right.second);

	}

	else if(i1==1 && i2==2 && i3==0){
		unsigned int rootIndex=s1.find(s3[0]);

		if(rootIndex<0 || rootIndex >= s1.length())
			return pair<string, string>("0", "0");

		string left1=s1.substr(0, rootIndex), left2=s2.substr(0, rootIndex), left3=s3.substr(1, rootIndex);

		string right1=s1.substr(rootIndex+1), right2=s2.substr(rootIndex+1, s1.length()-1-rootIndex), right3=s3.substr(rootIndex+1);

		pair<string, string> left=checkState(left1, left2, left3, func[i1*2], func[i2*2], func[i3*2], func);
		pair<string, string> right=checkState(right1, right2, right3, func[i1*2+1], func[i2*2+1], func[i3*2+1], func);

		if(!(isCorrect(left.first) && isCorrect(right.first)))
		{
			return pair<string, string>("0", "0");
		}
		return make_pair(s3[0]+left.first+right.first, left.second+s3[0]+right.second);

	}

	else if(i1==1 && i2==0 && i3==2){
		unsigned int rootIndex=s1.find(s2[0]);

		if(rootIndex<0 || rootIndex >= s1.length())
			return pair<string, string>("0", "0");

		string left1=s1.substr(0, rootIndex), left2=s2.substr(1, rootIndex), left3=s3.substr(0, rootIndex);

		string right1=s1.substr(rootIndex+1), right2=s2.substr(rootIndex+1), right3=s3.substr(rootIndex+1, s1.length()-1-rootIndex);

		pair<string, string> left=checkState(left1, left2, left3, func[i1*2], func[i2*2], func[i3*2], func);
		pair<string, string> right=checkState(right1, right2, right3, func[i1*2+1], func[i2*2+1], func[i3*2+1], func);

		if(!(isCorrect(left.first) && isCorrect(right.first)))
		{
			return pair<string, string>("0", "0");
		}
		return make_pair(s2[0]+left.first+right.first, left.second+s2[0]+right.second);

	}

	else if(i1==2 && i2==1 && i3==0){
		unsigned int rootIndex=s2.find(s3[0]);

		if(rootIndex<0 || rootIndex >= s1.length())
			return pair<string, string>("0", "0");

		string left1=s1.substr(0, rootIndex), left2=s2.substr(0, rootIndex), left3=s3.substr(1, rootIndex);

		string right1=s1.substr(rootIndex+1, s1.length()-1-rootIndex), right2=s2.substr(rootIndex+1), right3=s3.substr(rootIndex+1);

		pair<string, string> left=checkState(left1, left2, left3, func[i1*2], func[i2*2], func[i3*2], func);
		pair<string, string> right=checkState(right1, right2, right3, func[i1*2+1], func[i2*2+1], func[i3*2+1], func);

		if(!(isCorrect(left.first) && isCorrect(right.first)))
		{
			return pair<string, string>("0", "0");
		}
		return make_pair(s3[0]+left.first+right.first, left.second+s3[0]+right.second);

	}

	else if(i1==2 && i2==0 && i3==1){
		unsigned int rootIndex=s3.find(s2[0]);

		if(rootIndex<0 || rootIndex >= s1.length())
			return pair<string, string>("0", "0");

		string left1=s1.substr(0, rootIndex), left2=s2.substr(1, rootIndex), left3=s3.substr(0, rootIndex);

		string right1=s1.substr(rootIndex+1, s1.length()-1-rootIndex), right2=s2.substr(rootIndex+1), right3=s3.substr(rootIndex+1);

		pair<string, string> left=checkState(left1, left2, left3, func[i1*2], func[i2*2], func[i3*2], func);
		pair<string, string> right=checkState(right1, right2, right3, func[i1*2+1], func[i2*2+1], func[i3*2+1], func);

		if(!(isCorrect(left.first) && isCorrect(right.first)))
		{
			return pair<string, string>("0", "0");
		}
		return make_pair(s2[0]+left.first+right.first, left.second+s2[0]+right.second);

	}

	else if(i1==1 && i2==1 && i3==0){
		if(s1!=s2){

			return pair<string, string>("0", "0");
		}
		unsigned int rootIndex=s1.find(s3[0]);

		if(rootIndex<0 || rootIndex >= s1.length())
			return pair<string, string>("0", "0");

		string left1=s1.substr(0, rootIndex), left2=s2.substr(0, rootIndex), left3=s3.substr(1, rootIndex);

		string right1=s1.substr(rootIndex+1), right2=s2.substr(rootIndex+1), right3=s3.substr(rootIndex+1);

		pair<string, string> left=checkState(left1, left2, left3, func[i1*2], func[i2*2], func[i3*2], func);
		pair<string, string> right=checkState(right1, right2, right3, func[i1*2+1], func[i2*2+1], func[i3*2+1], func);

		if(!(isCorrect(left.first) && isCorrect(right.first)))
		{
			return pair<string, string>("0", "0");
		}
		return make_pair(s3[0]+left.first+right.first, left.second+s3[0]+right.second);

	}

	else if(i1==0 && i2==1 && i3==1){
		if(s3!=s2){

			return pair<string, string>("0", "0");
		}
		unsigned int rootIndex=s3.find(s1[0]);

		if(rootIndex<0 || rootIndex >= s1.length())
			return pair<string, string>("0", "0");

		string left1=s1.substr(1, rootIndex), left2=s2.substr(0, rootIndex), left3=s3.substr(0, rootIndex);

		string right1=s1.substr(rootIndex+1), right2=s2.substr(rootIndex+1), right3=s3.substr(rootIndex+1);

		pair<string, string> left=checkState(left1, left2, left3, func[i1*2], func[i2*2], func[i3*2], func);
		pair<string, string> right=checkState(right1, right2, right3, func[i1*2+1], func[i2*2+1], func[i3*2+1], func);

		if(!(isCorrect(left.first) && isCorrect(right.first)))
		{
			return pair<string, string>("0", "0");
		}
		return make_pair(s1[0]+left.first+right.first, left.second+s1[0]+right.second);

	}

	else if(i1==1 && i2==0 && i3==1){
		if(s1!=s3){

			return pair<string, string>("0", "0");
		}
		unsigned int rootIndex=s3.find(s2[0]);

		if(rootIndex<0 || rootIndex >= s1.length())
			return pair<string, string>("0", "0");

		string left1=s1.substr(0, rootIndex), left2=s2.substr(0, rootIndex), left3=s3.substr(0, rootIndex);

		string right1=s1.substr(rootIndex+1), right2=s2.substr(rootIndex+1), right3=s3.substr(rootIndex+1);

		pair<string, string> left=checkState(left1, left2, left3, func[i1*2], func[i2*2], func[i3*2], func);
		pair<string, string> right=checkState(right1, right2, right3, func[i1*2+1], func[i2*2+1], func[i3*2+1], func);

		if(!(isCorrect(left.first) && isCorrect(right.first)))
		{
			return pair<string, string>("0", "0");
		}
		return make_pair(s2[0]+left.first+right.first, left.second+s2[0]+right.second);

	}

	else if(i1==0 && i2==2 && i3==2){
		if(s3!=s2){

			return pair<string, string>("0", "0");
		}

		vector<pair<string, string> > v;
		for(unsigned int k=1; k<=s1.length()-1; k++)
		{
			string left1=s1.substr(1, k), left2=s2.substr(0, k), left3=s3.substr(0, k);
			string right1=s1.substr(k+1), right2=s2.substr(k, s1.length()-1-k), right3=s3.substr(k, s1.length()-1-k);

			pair<string, string> left=checkState(left1, left2, left3, func[i1*2], func[i2*2], func[i3*2], func);
			pair<string, string> right=checkState(right1, right2, right3, func[i1*2+1], func[i2*2+1], func[i3*2+1], func);

			if(isCorrect(left.first) && isCorrect(right.first))
				v.push_back(make_pair(s1[0]+left.first+right.first, left.second+s1[0]+right.second));
		}
		sort(v.begin(), v.end());
		return v[0];
	}

	else if(i1==2 && i2==0 && i3==2){
		if(s1!=s3){

			return pair<string, string>("0", "0");
		}

		vector<pair<string, string> > v;
		for(unsigned int k=1; k<=s1.length()-1; k++)
		{
			string left1=s1.substr(0, k), left2=s2.substr(1, k), left3=s3.substr(0, k);
			string right1=s1.substr(k, s1.length()-1-k), right2=s2.substr(k+1), right3=s3.substr(k, s1.length()-1-k);

			pair<string, string> left=checkState(left1, left2, left3, func[i1*2], func[i2*2], func[i3*2], func);
			pair<string, string> right=checkState(right1, right2, right3, func[i1*2+1], func[i2*2+1], func[i3*2+1], func);

			if(isCorrect(left.first) && isCorrect(right.first))
				v.push_back(make_pair(s2[0]+left.first+right.first, left.second+s2[0]+right.second));
		}
		sort(v.begin(), v.end());
		return v[0];
	}

	else if(i1==2 && i2==2 && i3==0){
		if(s1!=s2){

			return pair<string, string>("0", "0");
		}

		vector<pair<string, string> > v;
		for(unsigned int k=1; k<=s1.length()-1; k++)
		{
			string left1=s1.substr(0, k), left2=s2.substr(0, k), left3=s3.substr(1, k);
			string right1=s1.substr(k, s1.length()-1-k), right2=s2.substr(k, s1.length()-1-k), right3=s3.substr(k+1);

			pair<string, string> left=checkState(left1, left2, left3, func[i1*2], func[i2*2], func[i3*2], func);
			pair<string, string> right=checkState(right1, right2, right3, func[i1*2+1], func[i2*2+1], func[i3*2+1], func);

			if(isCorrect(left.first) && isCorrect(right.first))
				v.push_back(make_pair(s3[0]+left.first+right.first, left.second+s3[0]+right.second));
		}
		sort(v.begin(), v.end());
		return v[0];
	}
	else if(i1==0 && i2==0 && i3==0)
	{
			if(s1!=s2 || s2!=s3 || s1!=s3)
				return pair<string, string>("0", "0");

			vector<pair<string, string> > v;
		for(unsigned int k=1; k<=s1.length()-1; k++)
		{
			string left1=s1.substr(1, k), left2=s2.substr(1, k), left3=s3.substr(1, k);
			string right1=s1.substr(k+1), right2=s2.substr(k+1), right3=s3.substr(k+1);

			pair<string, string> left=checkState(left1, left2, left3, func[i1*2], func[i2*2], func[i3*2], func);
			pair<string, string> right=checkState(right1, right2, right3, func[i1*2+1], func[i2*2+1], func[i3*2+1], func);

			if(isCorrect(left.first) && isCorrect(right.first))
				v.push_back(make_pair(s1[0]+left.first+right.first, left.second+s1[0]+right.second));
		}
		sort(v.begin(), v.end());
		return v[0];
	}

	else if(i1==1 && i2==1 && i3==1)
	{
			if(s1!=s2 || s2!=s3 || s1!=s3)
				return pair<string, string>("0", "0");

			vector<pair<string, string> > v;
		for(unsigned int k=1; k<=s1.length()-1; k++)
		{
			string left1=s1.substr(0, k), left2=s2.substr(0, k), left3=s3.substr(0, k);
			string right1=s1.substr(k+1), right2=s2.substr(k+1), right3=s3.substr(k+1);

			pair<string, string> left=checkState(left1, left2, left3, func[i1*2], func[i2*2], func[i3*2], func);
			pair<string, string> right=checkState(right1, right2, right3, func[i1*2+1], func[i2*2+1], func[i3*2+1], func);

			if(isCorrect(left.first) && isCorrect(right.first))
				v.push_back(make_pair(s1[k]+left.first+right.first, left.second+s1[k]+right.second));
		}
		sort(v.begin(), v.end());
		return v[0];
	}
	else if(i1==2 && i2==2 && i3==2)
	{
			if(s1!=s2 || s2!=s3 || s1!=s3)
				return pair<string, string>("0", "0");

			vector<pair<string, string> > v;
		for(unsigned int k=1; k<=s1.length()-1; k++)
		{
			string left1=s1.substr(0, k), left2=s2.substr(0, k), left3=s3.substr(0, k);
			string right1=s1.substr(k, s1.length()-1-k), right2=s2.substr(k, s1.length()-1-k), right3=s3.substr(k, s1.length()-1-k);

			pair<string, string> left=checkState(left1, left2, left3, func[i1*2], func[i2*2], func[i3*2], func);
			pair<string, string> right=checkState(right1, right2, right3, func[i1*2+1], func[i2*2+1], func[i3*2+1], func);

			if(isCorrect(left.first) && isCorrect(right.first))
				v.push_back(make_pair(s1[s1.length()-1]+left.first+right.first, left.second+s1[s1.length()-1]+right.second));
		}
		sort(v.begin(), v.end());
		return v[0];
	}



	else if(i1==1 && i2==1 && i3==2){
		if(s1!=s2){

			return pair<string, string>("0", "0");
		}
		unsigned int rootIndex=s1.find(s3[s3.length()-1]);

		if(rootIndex<0 || rootIndex >= s1.length())
			return pair<string, string>("0", "0");

		string left1=s1.substr(0, rootIndex), left2=s2.substr(0, rootIndex), left3=s3.substr(0, rootIndex);

		string right1=s1.substr(rootIndex+1), right2=s2.substr(rootIndex+1), right3=s3.substr(rootIndex+1, s1.length()-1-rootIndex);

		pair<string, string> left=checkState(left1, left2, left3, func[i1*2], func[i2*2], func[i3*2], func);
		pair<string, string> right=checkState(right1, right2, right3, func[i1*2+1], func[i2*2+1], func[i3*2+1], func);

		if(!(isCorrect(left.first) && isCorrect(right.first)))
		{
			return pair<string, string>("0", "0");
		}
		return make_pair(s3[s3.length()-1]+left.first+right.second, left.second+s3[s3.length()-1]+right.second);

	}
	else if(i1==1 && i2==2 && i3==1){
		if(s1!=s3){

			return pair<string, string>("0", "0");
		}
		unsigned int rootIndex=s3.find(s1[s1.length()-1]);

		if(rootIndex<0 || rootIndex >= s1.length())
			return pair<string, string>("0", "0");

		string left1=s1.substr(0, rootIndex), left2=s2.substr(0, rootIndex), left3=s3.substr(0, rootIndex);

		string right1=s1.substr(rootIndex+1), right2=s2.substr(rootIndex+1, s1.length()-1-rootIndex), right3=s3.substr(rootIndex+1);

		pair<string, string> left=checkState(left1, left2, left3, func[i1*2], func[i2*2], func[i3*2], func);
		pair<string, string> right=checkState(right1, right2, right3, func[i1*2+1], func[i2*2+1], func[i3*2+1], func);

		if(!(isCorrect(left.first) && isCorrect(right.first)))
		{
			return pair<string, string>("0", "0");
		}
		return make_pair(s1[s3.length()-1]+left.first+right.first, left.second+ s1[s3.length()-1]+right.second);
	}
	else if(i1==2 && i2==1 && i3==1){
		if(s3!=s2){

			return pair<string, string>("0", "0");
		}
		unsigned int rootIndex=s3.find(s1[s1.length()-1]);

		if(rootIndex<0 || rootIndex >= s1.length())
			return pair<string, string>("0", "0");

		string left1=s1.substr(0, rootIndex), left2=s2.substr(0, rootIndex), left3=s3.substr(0, rootIndex);

		string right1=s1.substr(rootIndex+1, s1.length()-1-rootIndex), right2=s2.substr(rootIndex+1), right3=s3.substr(rootIndex+1);

		pair<string, string> left=checkState(left1, left2, left3, func[i1*2], func[i2*2], func[i3*2], func);
		pair<string, string> right=checkState(right1, right2, right3, func[i1*2+1], func[i2*2+1], func[i3*2+1], func);

		if(!(isCorrect(left.first) && isCorrect(right.first)))
		{
			return pair<string, string>("0", "0");
		}
		return make_pair(s1[s3.length()-1]+left.first+right.first, left.second+s1[s3.length()-1]+right.second);
	}
	else if(i1==2 && i2==2 && i3==1){
		if(s1!=s2){

			return pair<string, string>("0", "0");
		}
		unsigned int rootIndex=s3.find(s1[s1.length()-1]);

		if(rootIndex<0 || rootIndex >= s1.length())
			return pair<string, string>("0", "0");

		string left1=s1.substr(0, rootIndex), left2=s2.substr(0, rootIndex), left3=s3.substr(0, rootIndex);

		string right1=s1.substr(rootIndex+1, s1.length()-1-rootIndex), right2=s2.substr(rootIndex+1, s1.length()-1-rootIndex), right3=s3.substr(rootIndex+1);

		pair<string, string> left=checkState(left1, left2, left3, func[i1*2], func[i2*2], func[i3*2], func);
		pair<string, string> right=checkState(right1, right2, right3, func[i1*2+1], func[i2*2+1], func[i3*2+1], func);

		if(!(isCorrect(left.first) && isCorrect(right.first)))
		{
			return pair<string, string>("0", "0");
		}
		return make_pair(s1[s3.length()-1]+left.first+right.first, left.second+s1[s3.length()-1]+right.second);

	}
	else if(i1==2 && i2==1 && i3==2){
		if(s1!=s3){

			return pair<string, string>("0", "0");
		}
		unsigned int rootIndex=s2.find(s1[s1.length()-1]);

		if(rootIndex<0 || rootIndex >= s1.length())
			return pair<string, string>("0", "0");

		string left1=s1.substr(0, rootIndex), left2=s2.substr(0, rootIndex), left3=s3.substr(0, rootIndex);

		string right1=s1.substr(rootIndex+1, s1.length()-1-rootIndex), right2=s2.substr(rootIndex+1), right3=s3.substr(rootIndex+1, s1.length()-1-rootIndex);\

		pair<string, string> left=checkState(left1, left2, left3, func[i1*2], func[i2*2], func[i3*2], func);
		pair<string, string> right=checkState(right1, right2, right3, func[i1*2+1], func[i2*2+1], func[i3*2+1], func);

		if(!(isCorrect(left.first) && isCorrect(right.first)))
		{
			return pair<string, string>("0", "0");
		}
		return make_pair(s1[s3.length()-1]+left.first+right.first, left.second+s1[s3.length()-1]+right.second);
	}

	else if(i1==1 && i2==2 && i3==2){
		if(s3!=s2){

			return pair<string, string>("0", "0");
		}
		unsigned int rootIndex=s1.find(s2[s2.length()-1]);

		if(rootIndex<0 || rootIndex >= s1.length())
			return pair<string, string>("0", "0");

		string left1=s1.substr(0, rootIndex), left2=s2.substr(0, rootIndex), left3=s3.substr(0, rootIndex);

		string right1=s1.substr(rootIndex+1), right2=s2.substr(rootIndex+1, s1.length()-1-rootIndex), right3=s3.substr(rootIndex+1, s1.length()-1-rootIndex);

		pair<string, string> left=checkState(left1, left2, left3, func[i1*2], func[i2*2], func[i3*2], func);
		pair<string, string> right=checkState(right1, right2, right3, func[i1*2+1], func[i2*2+1], func[i3*2+1], func);

		if(!(isCorrect(left.first) && isCorrect(right.first)))
		{
			return pair<string, string>("0", "0");
		}
		return make_pair(s2[s3.length()-1]+left.first+right.first, left.second+s2[s3.length()-1]+right.second);
	}


}

int main(){


	string pre, in, post;

        cin>>pre;
		cin>>in;
		cin>>post;

		for(int i=0; i<90; i++){
			unsigned int rootIndex;
			for(rootIndex=0; in[rootIndex]!=pre[0]; rootIndex++);
			string leftIn=in.substr(0, rootIndex), rightIn=in.substr(rootIndex+1);
			string leftPre=pre.substr(1, rootIndex), rightPre=pre.substr(rootIndex+1);
			string leftPost=post.substr(0, rootIndex), rightPost=post.substr(rootIndex, post.length()-rootIndex-1);

			//char root=pre[0];

			pair<string, string> left=checkState(leftPre, leftIn, leftPost, functionStates[i][0], functionStates[i][2], functionStates[i][4], functionStates[i]);
			pair<string, string> right=checkState(rightPre, rightIn, rightPost, functionStates[i][1], functionStates[i][3], functionStates[i][5], functionStates[i]);

			if( isCorrect(left.first) && isCorrect(right.first)){
                printf("%i %i %i %i %i %i\n", functionStates[i][0], functionStates[i][1], functionStates[i][2], functionStates[i][3], functionStates[i][4], functionStates[i][5]);
			}
		}

}
