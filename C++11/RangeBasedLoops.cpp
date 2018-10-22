#include <iostream>

int main()
{
	auto texts = {"one", "two", "three"};

	for (auto &txt : texts)
	{
		std::cout << txt << std::endl;
	}

	return 0;
}
