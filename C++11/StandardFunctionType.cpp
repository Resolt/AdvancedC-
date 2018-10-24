#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

class Check
{
private:
	std::string match;

public:
	Check(std::string match) : match(match) {};
	bool operator()(std::string &test)
	{
		return test == match;
	}
};

void run(std::function<bool(std::string &)> check)
{
	std::string test = "B";
	std::cout << check(test) << std::endl;
}

int main()
{
	// DEFINE A FUNCTION FOR ANOTHER FUNTION MUCH LIKE IT IS DONE IN R (LAPPLY)
	std::vector<std::string> vec{"A", "B", "WHAT", "LOL"};
	std::string match = "LOL";
	size_t count = count_if(
		vec.begin(),
		vec.end(),
		[&match](std::string &str)
		{
			return str == match;
		}
	);
	std::cout << count <<	std::endl;
	// OR LIKE THIS
	auto lambda = [&match](std::string &str) { return str == match; };
	count = count_if(
		vec.begin(),
		vec.end(),
		lambda
	);
	std::cout << count << std::endl;

	// THIS ALSO WORKS WITH FUNCTORS
	Check check("WHAT");
	count = count_if(
		vec.begin(),
		vec.end(),
		check
	);
	std::cout << count << std::endl;

	// AND FINALLY THE STANDARD FUNCTION TYPE
	run(check);
	run(lambda);

	// STANDARD FUNCTION IS COMPATIBLE WITH LAMBDA EXPRESSIONS
	std::function<bool(int, int)> func = [](int a, int b) { return a == b; };
	if(func(5, 5))
	{
		std::cout << "WOOT" << std::endl;
	}

	// MUTABLE LAMBDA
	int cats = 5;
	[cats]() mutable { cats = 8; std::cout << cats << std::endl; }();
	std::cout << cats << std::endl;

	return 0;
}