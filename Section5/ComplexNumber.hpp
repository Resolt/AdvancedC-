#include <iostream>

class Complex
{
private:
	double real, imaginary;

public:
	Complex(): real(0), imaginary(0) {};
	Complex(const double &real, const double &imaginary) : real(real), imaginary(imaginary) {};
	Complex(const Complex &other) // COPY CONSTRUCTOR
	{
		this->real = other.real;
		this->imaginary = other.imaginary;
		std::cout << "Complex copy" << std::endl;
	};
	const Complex &operator = (const Complex &other) // OVERLOADED ASSIGNMENT OPERATOR
	{
		this->real = other.real;
		this->imaginary = other.imaginary;

		std::cout << "Ass. operator" << std::endl;

		return *this;
	}

	const Complex &operator + (const Complex &other) // OVERLOADED ASSIGNMENT OPERATOR
	{
		this->real += other.real;
		this->imaginary += other.imaginary;

		std::cout << "Plus. operator" << std::endl;

		return *this;
	}

	friend std::ostream &operator<<(std::ostream &out, const Complex &other)
	{
		out << "(" << other.getReal() << ", " << other.getImaginary() << ")";

		return out;
	};

	double getReal() const { return this->real; };
	double getImaginary() const { return this->imaginary; };
};