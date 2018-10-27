#include "BitMap.hpp"
#include "Mandelbrot.hpp"

int main()
{
	// uint16_t w{3440}, h{1440};
	uint16_t w{860}, h{360};
	// uint16_t w{1000}, h{1000};

	fract::BitMap bm(w, h);

	bm.drawFractal();

	std::string fileName = "Fractal.bmp";
	bm.write(fileName);

	return 0;
}
