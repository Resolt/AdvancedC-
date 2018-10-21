#include <iostream>

struct Test
{
	virtual bool operator()(std::string &text) = 0;

	virtual ~Test(){};
};

struct MatchTest: public Test
{
	bool operator()(std::string &text)
	{
		return text == "lion";
	};
};

void check(std::string &text, Test &test)
{
	if (test(text))
	{
		std::cout << "Match!" << std::endl;
	}
	else
	{
		std::cout << "No match!" << std::endl;
	}
}

int main()
{
	MatchTest pred;
	std::string str = "lion";
	std::string fstr = "balls";
	check(str, pred);
	check(fstr, pred);

	return 0;
}
