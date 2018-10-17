#include "ComplexNumber.hpp"

int main()
{
	Complex com1;
	Complex com2(5, 4);
	Complex com3 = com2;
	com1 = com2;
	std::cout << com1 << com2 << Complex(3, 2) << std::endl;

	Complex com4 = com1 + com2 + com3;
	// com4 = com4 + com3;

	std::cout << com4 << std::endl;

	Complex com5 = 15 + com1 + 2;
	std::cout << com5 << std::endl;

	// if (com1 == com2)
	// {
	// 	std::cout << "YES" << std::endl;
	// }

	if (com1 != Complex(0, 5))
	{
		std::cout << "YES" << std::endl;
	}

	std::cout << com1 << !com1 << std::endl;

	return 0;
}
