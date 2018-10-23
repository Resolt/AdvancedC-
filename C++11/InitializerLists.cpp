#include <iostream>
#include <vector>
#include <initializer_list>

class Test
{
public:
	Test(std::initializer_list<std::string> texts): texts(texts) {}

	void print(std::initializer_list<std::string> texts)
	{
		for(auto text : texts)
		{
			std::cout << text << "\t";
		}
		std::cout << std::endl;
	}

	void print()
	{
		for (auto &text : this->texts)
		{
			std::cout << text << "\t";
		}
		std::cout << std::endl;
	}

private:
	std::vector<std::string> texts;
};

int main()
{
	Test test{"apple", "Banana", "batman"};
	test.print();

	test.print({"WHAT", "THE", "FORK"});

	return 0;
}
