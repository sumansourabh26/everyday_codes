#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <typeinfo>

using namespace std;

struct node
{
	char key;
	node* lt;
	node* rt;

	node(char k)w
	{
		key = k;
		lt = NULL;
		rt = NULL;
	}

};


bool isproper(int* Case, string &l1, string &l2, int type, node* &t)
{
	if (l1.size() <= 1)
	{
		if (l1.size() == 1) t = new node(l1[0]);
		if (l1 == l2)
		return true;
		else
		return false;
	}

	if (type  == 1)
	{
		char root = l1[0];
		int index = l2.find(root);
		string left2 =  l2.substr(0,index);
		string right2 = l2.substr(index + 1, l2.size() - index);
		string left1 =  l1.substr(1,index);
		string right1 = l1.substr(index + 1, l1.size() - index);
		list<int> tl,tr;
			tl.push_back(Case[0]);
			tl.push_back(Case[2]);
			tr.push_back(Case[1]);
			tr.push_back(Case[3]);

		node* t1 = NULL, *t2 = NULL;
		t = new node(root);
		bool lef = isproper(Case,left1,left2,givetype(tl),t1);
		bool rig = isproper(Case,right1,right2,givetype(tr),t2);
		t->lt = t1;
		t->rt = t2;

		return lef && rig;
	}

	if (type == 2)
	{}

	if (type == 3)
	{
		char root = l2[l3.size() - 1];
		int index = l2.find(root);
		string left3 =  l3.substr(0,index);
		string right3 = l3.substr(index, l3.size() - index);
		string left1 =  l1.substr(0,index);
		string right1 = l1.substr(index + 1, l1.size() - index);
		list<int> tl,tr;
			tl.push_back(Case[2]);
			tl.push_back(Case[4]);
			tr.push_back(Case[3]);
			tr.push_back(Case[5]);

		node* t1 = NULL, *t2 = NULL;
		t = new node(root);
		bool lef = isproper(Case,left1,left3,givetype(tl),t1);
		bool rig = isproper(Case,right1,right3,givetype(tr),t2);
		t->lt = t1;
		t->rt = t2;
		return lef && rig;
	}
}


int givetype(list<int> &two)			// for two strings
{
	two.sort();
	if (*(two.begin()) == 0)
	{
		list<int> :: iterator temp = two.end();
		temp--;
		if (*temp == 1) return 1;
		else if (*temp == 2) return 2;
	}
	else return 3;
}


bool proper(int* Case, string &l1, string &l2, string &l3, vector<int> type, node* &t)
{
	if (l1.size() <= 1)
	{
		if (l1.size() == 1) t = new node(l1[0]);
		if (l1 == l2)
		return true;
		else
		return false;
	}

	if (type[0] == 0 && type[1] == 0 && type[2] == 1)
	{
		if (l1 != l2) return false;

		char root = l1[0];
		int index = l3.find(root);
		string left3 =  l3.substr(0,index);
		string right3 = l3.substr(index + 1, l3.size() - index);
		string left1 =  l1.substr(1,index);
		string right1 = l1.substr(index + 1, l1.size() - index);
		list<int> tl,tr;
			tl.push_back(Case[0]);
			tl.push_back(Case[2]);
			tr.push_back(Case[1]);
			tr.push_back(Case[3]);

		node* t1 = NULL, *t2 = NULL;
		t = new node(root);
		bool lef = isproper(Case,left1,left3,givetype(tl),t1);
		bool rig = isproper(Case,right1,right3,givetype(tr),t2);
		t->lt = t1;
		t->rt = t2;

		return lef && rig;
	}

	if (type[0] == 0 && type[1] == 0 && type[2] == 2)
	{
		if (l1 != l2) return false;
	}

	if (type[0] == 0 && type[1] == 1 && type[2] == 2)
	{
		char root = l1[0];
		int index = l2.find(root);
		string left3 =  l3.substr(0,index);
		string right3 = l3.substr(index , l1.size() - index);
		string left2 =  l1.substr(0,index);
		string right2 = l1.substr(index + 1, l1.size() - index);
		string left1 =  l1.substr(1,index);
		string right1 = l1.substr(index + 1, l1.size() - index);
		list<int> tl1,tr1;
			tl1.push_back(Case[0]);
			tl1.push_back(Case[2]);
			tl1.push_back(Case[4]);
			tr1.push_back(Case[1]);
			tr1.push_back(Case[3]);
			tr1.push_back(Case[5]);
			tl1.sort();
			tr1.sort();
		vector<int> tl,tr;
		for (int i = 0; i < 3; i++)
		{
			list<int> :: iterator temp1 = tl1.begin(), temp2 = tr1.begin();
			tl[i] = *temp1;
			tr[i] = *temp2;
			temp1++;
			temp2++;
		}

		node* t1 = NULL, *t2 = NULL;
		t = new node(root);
		bool lef = proper(Case,left1,left2,left3,tl,t1);
		bool rig = proper(Case,right1,right2,right3,tr,t2);
		t->lt = t1;
		t->rt = t2;
		return lef && rig;
	}

	if (type[0] == 0 && type[1] == 2 && type[2] == 2)
	{

	}

	if (type[0] == 0 && type[1] == 1 && type[2] == 1)
	{
		if (l3 != l2) return false;
		char root = l1[0];
		int index = l3.find(root);
		string left3 =  l3.substr(0,index);
		string right3 = l3.substr(index + 1, l3.size() - index);
		string left1 =  l1.substr(1,index);
		string right1 = l1.substr(index + 1, l1.size() - index);
		list<int> tl,tr;
			tl.push_back(Case[0]);
			tl.push_back(Case[2]);
			tr.push_back(Case[1]);
			tr.push_back(Case[3]);

		node* t1 = NULL, *t2 = NULL;
		t = new node(root);
		bool lef = isproper(Case,left1,left3,givetype(tl),t1);
		bool rig = isproper(Case,right1,right3,givetype(tr),t2);
		t->lt = t1;
		t->rt = t2;
		return lef && rig;
	}

	if (type[0] == 1 && type[1] == 1 && type[2] == 2)
	{
		if (l1 != l2) return false;
		char root = l3[l3.size() - 1];
		int index = l2.find(root);
		string left3 =  l3.substr(0,index);
		string right3 = l3.substr(index, l3.size() - index);
		string left1 =  l1.substr(0,index);
		string right1 = l1.substr(index + 1, l1.size() - index);
		list<int> tl,tr;
			tl.push_back(Case[2]);
			tl.push_back(Case[4]);
			tr.push_back(Case[3]);
			tr.push_back(Case[5]);

		node* t1 = NULL, *t2 = NULL;
		t = new node(root);
		bool lef = isproper(Case,left1,left3,givetype(tl),t1);
		bool rig = isproper(Case,right1,right3,givetype(tr),t2);
		t->lt = t1;
		t->rt = t2;
		return lef && rig;
	}

	if (type[0] == 1 && type[1] == 2 && type[2] == 2)
	{
		if (l3 != l2) return false;
		char root = l3[l3.size() - 1];
		int index = l1.find(root);
		string left3 =  l3.substr(0,index);
		string right3 = l3.substr(index, l3.size() - index);
		string left1 =  l1.substr(0,index);
		string right1 = l1.substr(index + 1, l1.size() - index);
		list<int> tl,tr;
			tl.push_back(Case[2]);
			tl.push_back(Case[4]);
			tr.push_back(Case[3]);
			tr.push_back(Case[5]);

		node* t1 = NULL, *t2 = NULL;
		t = new node(root);
		bool lef = isproper(Case,left1,left3,givetype(tl),t1);
		bool rig = isproper(Case,right1,right3,givetype(tr),t2);
		t->lt = t1;
		t->rt = t2;
		return lef && rig;
	}



	/*

	if (type1 == type2)
	{
		if (l1 != l2) return false;
		else
		{
			if (type1 == 0)
			char root = l1[0];

			if (type3 == 1)
			{
				int index = l3.find(root);
				string left =  l3.substr(0,index);
				string right = l3.substr(index + 1, inS.size() - index);
			}
		}
	}

	if (type3 == type2)
	{
		if (l3 != l2) return false;
		else
	}

	if (type1 == type3)
	{
		if (l1 != l3) return false;
		else
	}


	*/

}

int main()
{
    string preS,inS,postS;
    cin >> preS >> inS >> postS;

	int func[90][6]={{0,0,1,1,2,2},{0,0,1,2,1,2},{0,0,1,2,2,1},{0,0,2,1,1,2},
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


    for (int i = 0; i < 90; i++)
    {
		node* temp = NULL;
		/*
		bool found =


		char node = preS[0];
		int index = inS.find(node);

		string left = inS.substr(0,index);
		string right = inS.substr(index + 1, inS.size() - index);
		*/
		bool found =

	}





}

