#include <iostream>

class Complex
{
private:
	double real, imaginary;

public:
	Complex(): real(0), imaginary(0)
	{
		std::cout << "Default" << std::endl;
	};
	Complex(const double &real, const double &imaginary) : real(real), imaginary(imaginary)
	{
		std::cout << "Overload" << std::endl;
	};
	Complex(const Complex &other) // COPY CONSTRUCTOR
	{
		std::cout << "Copy" << std::endl;
		this->real = other.real;
		this->imaginary = other.imaginary;
	};
	const Complex &operator = (const Complex &other)
	{
		std::cout << "=" << std::endl;
		this->real = other.real;
		this->imaginary = other.imaginary;
		return *this;
	}

	friend Complex operator + (const Complex &c1, const Complex &c2)
	{
		std::cout << "+" << std::endl;
		return Complex(c1.getReal() + c2.getReal(), c1.getImaginary() + c2.getImaginary());
	}

	friend Complex operator + (const double &d, const Complex &c)
	{
		std::cout << "+dl" << std::endl;
		return Complex(c.getReal() + d, c.getImaginary());
	}

	friend Complex operator + (const Complex &c, const double &d)
	{
		std::cout << "+dr" << std::endl;
		return Complex(c.getReal() + d, c.getImaginary());
	}

	friend std::ostream &operator << (std::ostream &out, const Complex &other)
	{
		std::cout << "Out" << std::endl;
		out << "(" << other.getReal() << ", " << other.getImaginary() << ")";
		return out;
	};

	friend bool operator == (const Complex &c1, const Complex &c2)
	{
		std::cout << "==" << std::endl;
		return c1.getReal() == c2.getReal() && c1.getImaginary() == c2.getImaginary();
	}

	friend bool operator != (const Complex &c1, const Complex &c2)
	{
		std::cout << "!=" << std::endl;
		return !(c1.getReal() == c2.getReal() && c1.getImaginary() == c2.getImaginary());
	}

	Complex operator ! ()
	{
		std::cout << "!" << std::endl;
		return Complex(real, -imaginary);
	}

	double getReal() const { return this->real; };
	double getImaginary() const { return this->imaginary; };
};