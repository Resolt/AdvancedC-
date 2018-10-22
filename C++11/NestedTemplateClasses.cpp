#include "NestedTemplateClasses.hpp"

int main()
{
	Ring<std::string> circ(5);

	std::vector<std::string> inputs{"A", "B", "C", "D", "E", "F", "G"};

	for(auto &i : inputs)
	{
		circ.add(i);
	}

	for (size_t i = 0; i < circ.getSize(); i++)
	{
		std::cout << circ.get(i) << std::endl;
	}

	// Ring<std::string>::iterator it;

	for (Ring<std::string>::iterator it = circ.begin(); it != circ.begin(); it++)
	{
		std::cout << *it << std::endl;
	}

	return 0;
}
