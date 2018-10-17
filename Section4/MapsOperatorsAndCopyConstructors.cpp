#include <iostream>
#include <string>
#include <vector>
#include <map>

class Person
{

private:
	std::string name;
	size_t age;

public:
	Person(): name(""), age(0) {}
	Person(const Person &other)
	{
		std::cout << "Person Copy" << std::endl;
		this->name = other.name;
		this->age = other.age;
	}
	Person(std::string name, int age) : name(name), age(age){}

	void print() { std::cout << this->name << "\t" << this->age << std::endl; }

	bool operator < (const Person &other) const {
		return this->age < other.age;
	}

	bool operator > (const Person &other) const
	{
		return this->age > other.age;
	}

	size_t operator % (const Person &other) const
	{
		if(this->age >= other.age)
		{
			std::cout << this->name << std::endl;
			return this->age;
		}
		else
		{
			std::cout << other.name << std::endl;
			return other.age;
		}
	}
};

int main(int argc, char const *argv[])
{
	// TESTING OUT COPY CONSTRUCTORS
	Person mike(std::string("Mike"), 27);
	Person malene(std::string("Malene"), 26);
	Person mikesClone = mike;

	std::map<int, Person> people;
	people[50] = Person("Mike", 27);
	people[25] = Person("Lolitta", 18);
	people[5] = Person("Jamie", 30);

	people.insert(std::make_pair(55, Person("LOL", 123)));

	for (std::map<int, Person>::iterator it = people.begin(); it != people.end(); it++)
	{
		it->second.print();
	}

	// TESTING OUT MAPS AND KEYS
	std::map<std::string, uint32_t> ages;

	ages["LOL"] = 40;
	ages["TEST"] = 888;

	std::cout << ages["LOL"] << std::endl;

	for (auto &str : std::vector<std::string>{"HEY", "TEST"}) 
	{
		if(ages.find(str) != ages.end())
		{
			std::cout << str << std::endl;
		}
	}

	// OPERATORS
	std::cout << (int)(mike > malene) << std::endl;
	std::cout << mike % malene << std::endl;

	return 0;
}
