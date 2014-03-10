#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

class Person
{
public:
	// default constructor
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
	vecPerson.push_back(Person(28,"Alison"));

	using namespace boost::lambda;
	std::sort(vecPerson.begin(),vecPerson.end(),
		ret<bool>( (&_1 ->* &Person::age) < (&_2 ->* &Person::age) ) );

	for(size_t i=0; i<vecPerson.size(); ++i)
		std::cout<<vecPerson[i].age<<", "<<vecPerson[i].name<<std::endl;

	return 0;
}
