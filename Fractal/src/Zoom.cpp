#include "Zoom.hpp"

namespace fract
{

void ZoomList::add(uint16_t x, uint16_t y, double scale)
{
	
	this->zooms.push_back(getZoom(x, y, scale));

	this->m_xCenter += (x - (double)this->m_width / 2) * this->m_scale;
	this->m_yCenter += (y - (double)this->m_height / 2) * this->m_scale;

	this->m_scale = this->m_scale * scale;

	std::cout << this->m_xCenter << " " << this->m_yCenter << " " << this->m_scale << std::endl;
}

Zoom ZoomList::getZoom(uint16_t x, uint16_t y, double scale)
{
	Zoom z;
	z.x = x;
	z.y = y;
	z.scale = scale;
	return z;
}

std::pair<double, double> ZoomList::doZoom(uint16_t x, uint16_t y)
{
	return std::pair<double, double>(0, 0);
}

} //namespace fract