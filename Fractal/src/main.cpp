#include "Fractal.hpp"

int main()
{
	// uint16_t w{3440}, h{1440};
	// uint16_t w{1000}, h{1000};
	uint16_t w{860}, h{360};

	std::string fileName = "Fractal.bmp";
	fract::Fractal fractal(fileName, w, h);

	return 0;
}
