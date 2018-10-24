#include <iostream>

class Test
{
private:
	int one{1}, two{2};

public:
	void run()
	{
		int three = 3;
		int four = 4;

		// REGULAR LAMBDA EXPRESSION, WITH PASEDD "ACCESS" - NOT ARGUMENTS
		auto pLambda1 = [three, four]()
		{
			std::cout << three << "\t" << four << std::endl;
		};
		pLambda1();

		// WHEN PASSING 'this' TO LAMBDA EXPRESSIONS IN CLASSES IT IS BY REFERENCE BY DEFAULT
		// IF USING '&' AND 'this' AT THE SAME TIME '&' HAS TO BE FIRST
		std::cout << &(this->one) << std::endl;
		auto pLambda2 = [&, this]()
		{
			std::cout << &(this->one) << std::endl;
			std::cout << this->one << "\t" << this->two << "\t" << three << std::endl;
		};
		pLambda2();
	}
};

void test(void (*pFunc)(std::string), std::string name)
{
	pFunc(name);
}

void runDivide(double (*divide)(double, double))
{
	auto rval = divide(3, 9);
	std::cout << rval << std::endl;
}

int main()
{
	// LAMBDA EXPRESSIONS
	auto func = [](std::string name) { std::cout << name << std::endl; };
	func("BLEGH");

	// ARE COMPATIBLE WITH FUNCTION POINTERS
	test(func, std::string{"WHAT"});

	// THEY TAKE ARGUMENTS LIKE REGULAR FUNCTIONS
	auto pAdd = [](int &i1, int &i2) { return i1 + i2; };
	int i1 = 34;
	int i2 = 45;
	std::cout << pAdd(i1, i2) << std::endl;

	// AND THEY CAN DETERMINE THEIR RETURN TYPE ON THEIR OWN - BUT TRAILING RETURN TYPE IS NECESSARY AT TIMES
	auto pDivide = [](double a, double b) -> double {
		if(b == 0 || a == 0)
		{
			return (int)0;
		}

		return a / b;
	};
	runDivide(pDivide);

	std::string name{"JENS"};
	// PASSING VARIABLES BY VALUE (COPY)
	[name, i2]() { std::cout << name << "\t" << i2 << std::endl; }();
	// PASSING ALL LOCAL VARIABLES BY REFERENCE (NO COPY)
	[&]() { std::cout << name << "\t" << i2 << std::endl; std::cout << i1 << std::endl; }();

	Test test2;
	test2.run();

	return 0;
}
