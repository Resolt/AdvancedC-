#include <iostream>

class Test
{
};

template<typename T>
void call(T &&arg)
{
	// check(static_cast<T>(arg)); // STATIC CAST IS THE KEY ELEMENT OF THE PERFECT FORWARDING
	check(std::forward<T>(arg)); // SAME THING IS ACHIEVED HERE BUT MORE CLEARLY WRITTEN (STD IS ALWAYS A BETTER WAY)
}

void check(Test &&test)
{
	std::cout << "rvalue" << std::endl;
}

void check(Test &test)
{
	std::cout << "lvalue" << std::endl;
}

int main()
{
	Test test;
	auto &&t = Test(); // THE AUTO KEYWORD COLLAPSES FROM THE RVALUE EXPLICIT IDENTIFIER TO AN LVALUE - BECAUSE IT CAN! IT'S A C++ RULE I GUESS

	call(t);

	call(Test());

	return 0;
}
