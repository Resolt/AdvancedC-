#include <iostream>
#include <memory>

class Test
{
private:

public:
	Test()
	{
		std::cout << "Created" << std::endl;
	}

	void greet()
	{
		std::cout << "Hai" << std::endl;
	}

	~Test()
	{
		std::cout << "Is ded" << std::endl;
	}
};

int main()
{
	Test * wat = new Test();
	wat->greet();
	delete wat; // THIS IS NEEDED IN ORDER TO FREE UP THE MEMORY

	std::unique_ptr<int> pInt(new int);

	int i = 7;

	*pInt = i;

	std::cout << &pInt << " " << *pInt << std::endl;
	// std::cout << &pTest << " " << pTest << " " << *pTest << std::endl; // THIS DOESN'T WORK AS unique_ptr ISN'T A REGULAR POINTER

	int *p = &i;

	std::cout << &p << " " << p << " " << *p << std::endl;

	// OBJECT
	std::unique_ptr<Test> pTest(new Test);
	pTest->greet(); // WE CLEARLY HAVE INSTANTIATED THIS ON THE HEAP, BUT IT DOESN'T NEED TO BE DELETED IN ORDER TO FREE UP THE MEMORY WHEN IT GOES OUT OF SCOPE

	// THIS CAN BE DEMONSTRATED LIKE THIS
	{
		std::unique_ptr<Test> pTest(new Test);
		pTest->greet();
	}

	std::cout << "finish" << std::endl;
	
	return 0;
}
