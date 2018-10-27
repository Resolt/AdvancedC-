#include "Mandelbrot.hpp"

#include <complex>

namespace fract
{

uint16_t Mandel::getIterations(double x, double y)
{
	std::complex<double> z = 0;
	std::complex<double> c(x, y);

	uint16_t iters = 0;

	while(iters < MAX_IT)
	{
		z = z * z + c;

		if(abs(z) > 2)
		{
			break;
		}

		iters++;
	}

	return iters;
}

}