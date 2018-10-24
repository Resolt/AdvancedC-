#include <iostream>

class Test
{
	int id{3};
	std::string name{"WHAT"};

public:
	Test() = default;
	Test(int id) : id(id){};
	Test(const Test &other) = default;
	Test &operator=(const Test &other) = delete;

	void print()
	{
		std::cout << id << "\t" << name << std::endl;
	}
};

int main()
{
	Test test1;
	test1.print();

	Test test2(100);
	test2.print();

	Test test3 = test2;
	test3.print();
	// test1 = test3; // DOESN'T WORK AS ASSINGMENT OPERATOR FUNCITON IS SET TO 'delete'

	return 0;
}
