#include <iostream>

class Parent
{
private:
	size_t pik;

public:
	Parent()
	{
		pik = 1234;
	}

	void print()
	{
		std::cout << "SERIOUSLY:\t" << pik << std::endl;
	}
};

class Brother: public Parent
{
};

class Sister: public Parent
{
};

int main()
{
	// C STYLE CASTS VS C++ STYLE CASTS
	float f = 3.000456;

	std::cout << (double)f << " " << static_cast<double>(f) << std::endl;
	std::cout << (int)f << " " << static_cast<int>(f) << std::endl;

	// OBJECTS
	Parent parent;
	Brother brother;
	Sister sister;

	Parent *pp = &sister;
	Parent sisterslicer = sister; // OBJECT SLICING FOR LULS

	// STATIC
	Brother *pB = static_cast<Brother *>(&parent); // VERY UNSAFE - ALL TYPES OF SHIT COULD GO WRONG, BUT IT IS POSSIBLE TO POINT "THE OTHER WAY" BY USING STATIC CASTS LIKE THIS - JUST NEVER DO IT IRL
	std::cout << pB << " " << &parent << std::endl;

	// DYNAMIC
	Parent *pp2 = &parent;
	Sister *pS = static_cast<Sister *>(pp2); // THIS SHOULD MAKE THE PROGRAM CRASH AT RUNTIME, AS THE CAST DOES SO THAT WE DON'T KNOW THAT WE'RE NOT POINTING TO THE RIGHT OBJECT TYPE
	// Sister *pS2 = dynamic_cast<Sister *>(pp2);
	Sister *sp = &sister;
	Parent *pp3 = dynamic_cast<Parent *>(sp);

	std::cout << sp << " " << pp3 << std::endl;

	//REINTERPRET
	//reinterpret_cast ALLOWS FOR CASTING FROM ANYTHING TO ANYTHING - RAGNAROK WILL FOLLOW
	Parent *ppp = reinterpret_cast<Parent *>(&f); // THIS WORKS - IT IS AWFUL
	(*ppp).print();

	return 0;
}
