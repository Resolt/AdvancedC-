#include <iostream>
#include <vector>
#include <map>

int main(int argc, char const *argv[])
{
	std::multimap<int, std::string> lookup;

	lookup.insert(std::make_pair(30, "Mike"));
	lookup.insert(std::make_pair(29, "Annette"));
	lookup.insert(std::make_pair(30, "Nete"));
	lookup.insert(std::make_pair(100, "Mette"));

	for (std::multimap<int, std::string>::iterator it = lookup.begin(); it != lookup.end(); it++)
	{
		std::cout << std::get<0>(*it) << "\t" << std::get<1>(*it) << std::endl;
	}

	return 0;
}
