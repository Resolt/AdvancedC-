#include "Zoom.hpp"

namespace fract
{

ZoomList::ZoomList(uint16_t width, uint16_t height) : m_width(width), m_height(height)
{

}

void ZoomList::add(const Zoom &zoom)
{
	zooms.push_back(zoom);
}

std::pair<double, double> ZoomList::doZoom(uint16_t x, uint16_t y)
{
	return std::pair<double, double>(0, 0);
}

} //namespace fract