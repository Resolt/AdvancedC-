#include <iostream>
#include <typeinfo>

int main()
{
	int integer;
	double dub;
	std::string str;

	std::cout << typeid(integer).name() << std::endl;
	std::cout << typeid(dub).name() << std::endl;
	std::cout << typeid(str).name() << std::endl;

	decltype(dub) name;

	std::cout << typeid(name).name() << std::endl;

	return 0;
}
