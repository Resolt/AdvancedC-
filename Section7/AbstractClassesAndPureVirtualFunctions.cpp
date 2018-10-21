#include <iostream>

class Animal
{
public:
	virtual void speak() = 0;
	virtual void run() = 0;
};

class Dog: public Animal
{
public:
	virtual void speak()
	{
		std::cout << "Woof!" << std::endl;
	}
};

class Labrador: public Dog
{
public:
	Labrador()
	{
		std::cout << "New labrador" << std::endl;
	}
	virtual void run()
	{
		std::cout << "Fast!" << std::endl;
	}
};

int main()
{
	Labrador lab;
	lab.speak();
	lab.run();

	Animal *animals[5];
	animals[0] = &lab;

	return 0;
}
