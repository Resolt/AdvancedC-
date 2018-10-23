#include <iostream>
#include <vector>

int main()
{
	//C++98
	int values[] = {1, 4, 5, 6, 7, 3, 345, 2, 4, 6, 7, 6};

	class C
	{
	public:
		std::string text;
		size_t id;
	};

	C c1 = {"Hello", 5};

	std::cout << c1.text << std::endl;

	struct S
	{
		std::string text;
		size_t id;
	};

	S s1 = {"Hello", 6};

	std::cout << s1.text << std::endl;

	struct
	{
		std::string text;
		size_t id;
	} r1 = {"What", 0}, r2 = {"Test", 1};

	std::cout << r1.text << "\t" << r2.text << std::endl;

	std::vector<std::string> strings;

	strings.push_back("1");
	strings.push_back("2");
	strings.push_back("3");
	strings.push_back("4");

	std::cout << *(strings.end()-1) << std::endl;

	//C++11

	int value{5};

	std::cout << value << std::endl;

	std::string str{"WHAT"};

	std::cout << str << std::endl;

	int numbers[]{1, 2, 3, 7, 5, 6};

	std::cout << *(numbers+3) << std::endl;

	int *pInts = new int[3]{1, 2, 3};
	std::cout << pInts[2] << std::endl;

	int *pSomething{&values[6]};
	std::cout << *pSomething << std::endl;

	int *pSomething2{};
	int *pSomething3{nullptr};
	std::cout << pSomething2 << " " << pSomething3 << std::endl;

	int numbers1[5]{};
	std::cout << numbers1[1] << std::endl;

	std::vector<std::string> strings2{"SRSLY", "OMG", "WTF", "BBQ"};
	std::cout << strings2[3] << std::endl;

	return 0;
}
