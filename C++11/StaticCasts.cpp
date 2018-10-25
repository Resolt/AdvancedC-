#include <iostream>

class Parent
{
};

class Brother: public Parent
{
};

class Sister: public Parent
{
};

int main()
{
	Parent parent;
	Brother brother;
	Sister sister;

	float f = 3.000456;

	std::cout << (double)f << " " << static_cast<double>(f) << std::endl;
	std::cout << (int)f << " " << static_cast<int>(f) << std::endl;

	Parent *pp = &sister;
	Parent sisterslicer = sister; // OBJECT SLICING FOR LULS

	Brother *pB = static_cast<Brother *>(&parent); // VERY UNSAFE - ALL TYPES OF SHIT COULD GO WRONG, BUT IT IS POSSIBLE TO POINT "THE OTHER WAY" BY USING STATIC CASTS LIKE THIS - JUST NEVER DO IT IRL

	std::cout << pB << " " << &parent << std::endl;

	return 0;
}
