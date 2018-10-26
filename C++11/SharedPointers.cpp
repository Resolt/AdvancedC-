#include <iostream>
#include <memory>

class Test
{
private:
public:
	Test()
	{
		std::cout << "spawnt" << std::endl;
	}

	void greet()
	{
		std::cout << "hai" << std::endl;
	}

	~Test()
	{
		std::cout << "is ded" << std::endl;
	}
};

int main()
{
	std::shared_ptr<Test> pTest1(new Test);

	std::shared_ptr<Test> pTest2 = std::make_shared<Test>();

	std::shared_ptr<Test> pTest3 = pTest1;

	std::cout << pTest1 << " " << pTest3 << std::endl;

	pTest1->greet();

	{
		std::shared_ptr<Test> pTest4 = std::make_shared<Test>();
	}

	std::cout << "finish" << std::endl;

	return 0;
}