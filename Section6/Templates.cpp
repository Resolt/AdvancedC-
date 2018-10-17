#include "Templates.hpp"

template<class T>
void print(T n)
{
	std::cout << "Template version: " << n << std::endl;
}

void print(int n)
{
	std::cout << "Non-template version: " << n << std::endl;
}

template<class T>
void show()
{
	std::cout << T() << std::endl;
}

int main()
{
	std::string str = "WHAT";

	Test<std::string, int> test1(str, 5);

	std::cout << test1 << std::endl;

	Test<std::string, int> test2(str);

	std::cout << test2 << std::endl;

	Test<std::string, int> test3(10);

	std::cout << test3 << std::endl;

	print<std::string>("STRING");

	print(5);
	print<>(5);
	print(0.0004f);

	show<double>();

	return 0;
}
