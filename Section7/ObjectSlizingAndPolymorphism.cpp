#include <iostream>

class Parent
{
private:
	int num;

public:
	Parent() : num(1)
	{

	}

	Parent(const Parent &other) : num(1)
	{
		std::cout << "Copy parent" << std::endl;
	}

	virtual void print()
	{
		std::cout << "Parent" << std::endl;
	}

	int getOne()
	{
		return this->num;
	}

};

class Child: public Parent
{
private:
	int two;

public:
	Child(): two(2)
	{

	}

	void print()
	{
		std::cout << "Child" << std::endl;
	}

	int getTwo()
	{
		return this->two;
	}
};

int main()
{
	Parent p1;
	p1.print();

	Child c1;
	c1.print();

	Parent &p2 = c1;
	p2.print();

	Parent p3 = Child();
	p3.print();

	std::cout << p1.getOne() << std::endl;
	
	std::cout << c1.getOne() << std::endl;
	std::cout << c1.getTwo() << std::endl;

	std::cout << p2.getOne() << std::endl;

	std::cout << p3.getOne() << std::endl;
	// std::cout << p3.getTwo() << std::endl; // THIS WON'T WORK DUE TO 'UPCASTING' WHICH HAS CAUSED 'OBJECT SLIZING'. SINCE THE TYPE IS NOW PARENT THE UNIQUE FEATURES OF CHILD HAVE BEEN "SLICED" AWAY.

	return 0;
}
