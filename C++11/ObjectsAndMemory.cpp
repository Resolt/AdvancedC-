#include <iostream>
#include <vector>

class Test
{
private:
	static const size_t SIZE = 100;
	int * _pBuffer;

public:
	Test()
	{
		std::cout << "Constructor" << std::endl;
		// _pBuffer = new int[this->SIZE]{}; // THE {} MAKES SURE THAT THE BUFFER IS ALL 0s
		this->_pBuffer = new int[this->SIZE]; // ALLOCATE THE MEMORY BUT DON'T FILL IT
		std::fill(this->_pBuffer, this->_pBuffer + this->SIZE, 0); // USE A MORE CIVILIZED WAY OF FILLING THE BYTES "THIS IS AN ALTERNATIVE TO memset, NOT THE {}"
	}

	Test(int i) : Test()
	{
		std::cout << "Parameterized constructor" << std::endl;
		for (size_t k = i; k < this->SIZE; k++)
		{
			this->_pBuffer[k] = 7 * k;
		}
	}

	Test(const Test &other)
	{
		std::cout << "Copy constructor" << std::endl;
		this->_pBuffer = new int[this->SIZE];
		// memcpy(_pBuffer, other._pBuffer, this->SIZE * sizeof(int)); // THIS WOULD BE AN OLD WAY OF COPYING THE BYTES, AND IT REQUIRES string.h TO BE INCLUDED
		std::copy(other._pBuffer, other._pBuffer + this->SIZE, this->_pBuffer); // THIS IS NEWER AND NICER
	}

	Test &operator=(const Test &other)
	{
		std::cout << "Assignment" << std::endl;
		this->_pBuffer = new int[this->SIZE];
		std::copy(other._pBuffer, other._pBuffer + this->SIZE, this->_pBuffer);

		return *this;
	}

	void print()
	{
		for (size_t k = 0; k < this->SIZE; k++)
		{
			std::cout << this->_pBuffer[k] << std::endl;
		}
	};

	~Test()
	{
		std::cout << "Desctructor" << std::endl;
		delete [] this->_pBuffer;
	}
};

std::ostream &operator << (std::ostream &out, const Test &test)
{
	std::cout << "Hello from test";
	return out;
}

Test getTest()
{
	return Test();
}

void check(const Test &value)
{
	std::cout << "lvalue function" << std::endl;
}

void check(Test &&value)
{
	std::cout << "rvalue function" << std::endl;
}

int main()
{
	int value1 = 7;
	int *pValue1 = &value1;
	int *pValue2 = &++value1;
	std::cout << *pValue1 << " " << *pValue2 << " " << value1 << std::endl;

	// int *pValue4 = &value1++; // DOESN'T WORK AS &value1++ GETS AN RVALUE
	// vvv THIS WOULD HAVE TO BE DONE INSTEAD vvv
	int *pValue4 = &value1;
	value1++;
	std::cout << *pValue4 << " " << value1 << std::endl;

	Test lols1(80);

	Test lols2 = lols1;

	Test lols3;
	lols3 = lols2;

	lols3.print();

	std::vector<Test> vec;
	vec.push_back(Test());

	Test *pTest1 = &lols1;
	// Test *pTest2 = &getTest(); // DOESN'T WORK AS getTest RETURN IS AN RVALUE

	Test &rtest1 = lols3;

	Test *ptest1;
	ptest1 = &lols3;

	std::cout << &rtest1 << " " << ptest1 << " " << &lols3 << std::endl;

	// Test &rtest2 = getTest(); // AGAIN THIS DOESN'T WORK AS IT RETURNS AN RVALUE
	const Test &rtest2 = getTest(); // THIS WORKS BECAUSE OF CONST - IT IS AN RVALUE REFERENCE

	Test test4(Test(95)); // I HAVE NO IDEA WHY A COPY CONSTRUCTOR IS NOT CALLED HERE

	Test &ltest1 = lols1;
	Test &&rtest3 = getTest();

	// SMALL DEMONSTATION OF WHAT IS RVALUE AND WHAT IS LVALUE
	check(ltest1);
	check(rtest3);
	check(getTest());
	check(Test());
	// Test &&rtest3 = ptest1;

	// PRETTY STANDARD POINTER STUFF
	// std::cout << pValue1 << "\t" << pTest1 << std::endl;
	// std::cout << *pValue1 << "\t\t" << *pTest1 << std::endl;

	// int *pValue2 = &++value1;
	// std::cout << *pValue2 << "\t" << value1 << std::endl;
	// (*pValue2)++;
	// std::cout << *pValue2 << "\t" << value1 << std::endl;

	// int *pValue3;
	// ++value1;
	// pValue3 = &value1;
	// std::cout << *pValue3 << "\t" << value1 << std::endl;
	// value1++;
	// std::cout << *pValue3 << "\t" << value1 << std::endl;

	return 0;
}
