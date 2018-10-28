#ifndef FRACTAL_HPP_
#define FRACTAL_HPP_

#include <iostream>
#include <math.h>
#include <cstdint>

#include "Mandelbrot.hpp"
#include "BitMap.hpp"
#include "Zoom.hpp"

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

} // namespace fract

#endif