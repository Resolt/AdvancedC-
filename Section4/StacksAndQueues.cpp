#include <iostream>
#include <stack>
#include <queue>

class Test {

private:
	std::string name;

public:
	Test(std::string name) : name(name){};
	~Test(){};

	void print() { std::cout << this->name << std::endl; };
};

int main(int argc, char const *argv[])
{
	std::stack<Test> testStack;

	testStack.push(Test("1"));
	testStack.push(Test("2"));
	testStack.push(Test("3"));

	while(testStack.size())
	{
		testStack.top().print();
		testStack.pop();
	}

	std::queue<Test> testQueue;

	testQueue.push(Test("1"));
	testQueue.push(Test("2"));
	testQueue.push(Test("3"));

	while(testQueue.size())
	{
		testQueue.front().print();
		testQueue.pop();
	}

	return 0;
}
