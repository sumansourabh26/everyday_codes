#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
	Person() : age(0) {}
	Person(int age, std::string name) {
		this->age = age; this->name = name;
	}

	int age;
	std::string name;
};

int main()
{
	std::vector<Person> vecPerson;
	vecPerson.push_back(Person(24,"Calvin"));
	vecPerson.push_back(Person(30,"Benny"));
	vecPerson.push_back(Person(30,"Alice"));
	vecPerson.push_back(Person(28,"Alison"));

	cout<<vecPerson.begin()->age<<endl;

	sort(vecPerson.begin(),vecPerson.end(),[](Person x, Person y) {return x.age < y.age;} );

	for(size_t i=0; i<vecPerson.size(); ++i)
		std::cout<<vecPerson[i].age<<", "<<vecPerson[i].name<<std::endl;
}
