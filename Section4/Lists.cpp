#include <iostream>
#include <list>

main(int argc, char const *argv[])
{
	std::string str = "ABC";

	std::string::iterator iter = str.begin();
	while(iter != str.end())
	{
		std::cout << *iter;
		iter++;
	}
	std::cout << std::endl;

	for(auto &c : str)
	{
		std::cout << c;
	}
	std::cout << std::endl;

	return 0;
}
