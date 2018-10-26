#include <iostream>
#include <functional>

class Test
{
public:
	int add(int a, int b, int c)
	{
		return a + b + c;
	}
};

int add(int a, int b, int c)
{
	std::cout << &a << " " << &b << " " << &c << std::endl;
	return a + b + c;
}

int run(std::function<int(int, int, int)> func, int a, int b, int c)
{
	return func(a, b, c);
}

int run(std::function<int(int, int)> func, int a, int b)
{
	return func(a, b);
}

int main()
{
	std::cout << add(1, 2, 3) << std::endl;
	
	int i = 5, j = 5, k = 5;
	std::cout << &i << " " << &j << " " << &k << std::endl;
	std::cout << add(std::forward<int>(i), std::forward<int>(j), std::forward<int>(k)) << std::endl;

	std::cout << add(1, 2, 3) << std::endl;
	std::cout << add(4, 5, 6) << std::endl;

	//BIND
	auto calc = std::bind(add, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);

	Test test;
	auto calc2 = std::bind(&Test::add, test, std::placeholders::_1, 500, std ::placeholders::_3);

	std::cout << calc(1, 2, 3) << std::endl;
	std::cout << calc(4, 5, 6) << std::endl;
	std::cout << calc(7, 8, 9) << std::endl;

	std::cout << run(add, 4, 5, 500) << std::endl;
	// std::cout << run(calc2, 4, 5) << std::endl;// THIS SHIT DOESN'T WORK AND I DON'T KNOW WHY

	return 0;
}
