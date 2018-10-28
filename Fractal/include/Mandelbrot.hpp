#ifndef MANDELBROT_HPP_
#define MANDELBROT_HPP_

#include <cstdint>

namespace fract
{

class Mandel
{
private:

public:
	Mandel() {};
	virtual ~Mandel(){};

	static uint16_t getIterations(double x, double y);
	static const uint16_t MAX_IT = 1000;
};

} // namespace fract

#endif