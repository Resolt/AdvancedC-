#include <iostream>
#include <typeinfo>
#include <vector>

struct BALLS
{
	std::string str;
	BALLS(std::string str)
	{
		this->str = str;
	}
};

template<class T>
auto test(T value) -> decltype(value)
{
	return value;
}

template <class T, class S>
auto test2(T value, S value2) -> decltype(value + value2)
{
	return value + value2;
}

auto what()
{
	return 7;
}

int get()
{
	return 1022;
}

auto test3() -> decltype(get())
{
	return get();
}

int main(int argc, char const *argv[])
{
	std::string balls = "balls";

	auto moreBalls = balls;

	std::cout << moreBalls << std::endl;

	std::cout << typeid(decltype(moreBalls)).name() << std::endl;

	std::vector<int> ints{1, 2, 3, 4, 5, 6, 7, 8, 9};

	for (auto &i : ints)
	{
		i = 6;
	}

	for (auto &i : ints)
	{
		std::cout << i << std::endl;
	}

	std::cout << what() << std::endl;

	BALLS balss("WHAT");

	std::cout << test(balss).str << std::endl;

	std::cout << test2(5, 8) << std::endl;

	std::cout << test3() << std::endl;

	return 0;
}
