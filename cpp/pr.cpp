#include<iostream>
#include<string>
using namespace std;

class person{
	public:
	string name;
	int age;
	bool isgood;

	person(string n, int a, bool i){
		name = n;
		age = a;
		isgood = i;
	}
    person(){}
	person(string n, int a){
		name = n;
		age = a;
		isgood = true;
	}
	void print_age(){
		cout<<"age of "<<name<<" is "<<age<<endl;
	}

	int diff(person x){
		 return age - x.age;
	}

};


int main(){

	person p1("suman", 18,true), p2("q1wer", 12),p3;
    int x = 7;
	cout<< p1.diff(p2);
}
