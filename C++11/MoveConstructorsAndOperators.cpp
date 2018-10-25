#include <iostream>
#include <vector>

class Test
{
private:
	static const size_t SIZE = 100;
	int *_pBuffer{nullptr}; // nullptr MAKES SURE THAT WE AREN'T ALLOCATING MEMORY

public:
	Test()
	{
		this->_pBuffer = new int[this->SIZE];
		std::fill(this->_pBuffer, this->_pBuffer + this->SIZE, 0);
	}

	Test(int i) : Test()
	{
		for (size_t k = i; k < this->SIZE; k++)
		{
			this->_pBuffer[k] = 7 * k;
		}
	}

	Test(const Test &other)
	{
		this->_pBuffer = new int[this->SIZE];
		std::copy(other._pBuffer, other._pBuffer + this->SIZE, this->_pBuffer);
	}

	Test(Test &&other) // THIS HERE IS THE MOVE CONSTRUCTOR
	{
		std::cout << "Move constructor" << std::endl;
		this->_pBuffer = other._pBuffer; // SET THE POINTER OF BUFFER TO THE SAME AS THE BUFFER OF THE RVALUE OBJECT
		std::cout << this->_pBuffer << " " << other._pBuffer << std::endl;
		other._pBuffer = nullptr; // THIS DOESN'T SEEM TO BE NECESSARY WITH THIS COMPILER, BUT IT MAKES SURE THAT THE DESTRUCTOR OF THE RVALUE DOESN'T DESTROY THE BUFFER DATA
	}

	Test &operator=(const Test &other)
	{
		this->_pBuffer = new int[this->SIZE];
		std::copy(other._pBuffer, other._pBuffer + this->SIZE, this->_pBuffer);

		return *this;
	}

	Test &operator=(Test &&other)
	{
		std::cout << "Move assignment operator" << std::endl;
		delete[] this->_pBuffer;
		this->_pBuffer = other._pBuffer;
		other._pBuffer = nullptr;

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
		delete[] this->_pBuffer;
	}
};

std::ostream &operator<<(std::ostream &out, const Test &test)
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
	std::vector<Test> vec;
	vec.push_back(Test(90));

	vec[0].print();

	Test test1;
	test1 = getTest();
	// test1.print();

	return 0;
}
