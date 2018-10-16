#include "ComplexNumber.hpp"

int main()
{
	Complex com1;
	Complex com2(5, 4);
	Complex com3 = com2;
	com1 = com2;
	std::cout << com1 << com2 << Complex(3, 2) << std::endl;

	Complex com4 = com1 + com2;
	com4 = com4 + com3;

	std::cout << com4 << std::endl;

	return 0;
}
