#include <iostream>

class Parent
{
private:
	int dogs;
	std::string text;

public:
	Parent() : Parent("hello") // CALLING THE OTHER CONSTRUCTOR FROM DEFAULT CONSTRUCTOR
	{
		dogs = 5;
		std::cout << "No parameter parent constructor" << std::endl;
	}
	Parent(std::string text): text(text)
	{
		dogs = 5;
		std::cout << "String parent constructor" << std::endl;
	}
};

class Child: public Parent
{
public:
	Child() = default; // NOTE THAT ONLY PARENT CONSTRUCTORS ARE CALLED
	Child(std::string text) : Parent(text) // EXPLICITLY CALLING THE PARENT CONSTRUCTOR
	{
		std::cout << "Uhm what?" << std::endl;
	}
};

int main()
{
	Parent jens("hello");
	Child boerge;

	return 0;
}
