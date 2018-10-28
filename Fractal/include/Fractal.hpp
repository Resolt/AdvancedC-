#ifndef FRACTAL_HPP_
#define FRACTAL_HPP_

#include "Mandelbrot.hpp"
#include "BitMap.hpp"

namespace fract
{

class Fractal
{
private:
	BitMap BM;
	Mandel mand;

	void drawFractal();

public:
	Fractal(std::string &fileName, uint16_t width, uint16_t height);

};

struct Zoom
{
	uint16_t x{0};
	uint16_t y{0};
	double scale{0.0};

	Zoom(uint16_t x, uint16_t y, double scale) : x(x), y(y), scale(scale){};
};

}

#endif