#include <iostream>

class Test {
private:
	size_t id;
	std::string name;

public:
	Test(size_t &idcount) : name("")
	{
		idcount++;
		this->id = idcount;
	};
	Test(size_t &idcount, const std::string &name) : name(name)
	{
		idcount++;
		this->id = idcount;
	};

	void print() { std::cout << this->id << "\t" << this->name << std::endl; };

	void setName(const std::string &name){
		this->name = name;
	};

	const Test &operator = (const Test &other)
	{
		std::cout << "Operator =" << std::endl;

		this->id = 100;
		this->name = "HEH";

		return *this;
	};

	friend std::ostream & operator << (std::ostream &out, const Test &test)
	{
		out << test.id << "\t" << test.name;
		return out;
	};

	Test(const Test &other)
	{
		std::cout << "Copy constructor!" << std::endl;

		// this->id = other.id;
		// this->name = other.name;

		*this = other;
	}
};

int main(int argc, char const *argv[])
{
	size_t count = 0;
	Test test1(count, "Robert");
	test1.print();

	Test test2(count);
	test2.print();

	Test test3(count, "OPERATOR");
	test3.print();
	test3 = test1;
	test3.print();

	Test test4 = test1;
	test4.print();

	test1.setName("WHAT");

	test4.print();

	std::cout << std::endl;

	std::cout << test1 << "\t" << test2 << "\t" << test3 << "\t" << test4 << std::endl;

	return 0;
}
