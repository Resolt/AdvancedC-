#ifndef ZOOM_HPP_
#define ZOOM_HPP_

#include <cstdint>
#include <vector>

namespace fract
{

struct Zoom
{
	uint16_t x{0}, y{0};
	double scale{0.0};

	Zoom(uint16_t x, uint16_t y, double scale) : x(x), y(y), scale(scale){};
};

class ZoomList
{
private:
	uint16_t m_width{0}, m_height{0};
	std::vector<Zoom> zooms;

public:
	ZoomList(uint16_t width, uint16_t height);
	void add(const Zoom &zoom);
	std::pair<double, double> doZoom(uint16_t x, uint16_t y);
};

} //namespace fract

#endif