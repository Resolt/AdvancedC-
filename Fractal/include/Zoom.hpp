#ifndef ZOOM_HPP_
#define ZOOM_HPP_

#include <cstdint>
#include <vector>
#include <iostream>

namespace fract
{

struct Zoom
{
	uint16_t x{0}, y{0};
	double scale{0.0};

	// Zoom(uint16_t x, uint16_t y, double scale) : x(x), y(y), scale(scale){};
	// virtual ~Zoom()
	// {
	// 	std::cout << "No segfault" << std::endl;
	// };
};

class ZoomList
{
private:
	uint16_t m_width{0}, m_height{0};
	double m_xCenter{0.0}, m_yCenter{0.0}, m_scale{1.0};
	std::vector<Zoom> zooms;

public:
	ZoomList(uint16_t width, uint16_t height) : m_width(width), m_height(height){};
	virtual ~ZoomList() {};
	void add(uint16_t x, uint16_t y, double scale);
	Zoom getZoom(uint16_t x, uint16_t y, double scale);
	std::pair<double, double> doZoom(uint16_t x, uint16_t y);
};

} //namespace fract

#endif