#include <iostream>
#include <set>

int main(int argc, char const *argv[])
{
	std::set<int> numbers;

	numbers.insert(10);
	numbers.insert(20);
	numbers.insert(30);
	numbers.insert(10);
	numbers.insert(20);
	numbers.insert(30);
	numbers.insert(5);

	for (std::set<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
	{
		std::cout << *it << std::endl;
	}

	for (std::set<int>::iterator itFind = numbers.find(26); itFind != numbers.end(); itFind++)
	{
		std::cout << *itFind << std::endl;
	}

	if(numbers.count(20))
	{
		std::cout << "Found it" << std::endl;
	}

	return 0;
}
