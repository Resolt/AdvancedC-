#ifndef BITMAPFILE_HPP_
#define BITMAPFILE_HPP_

#include <iostream>
#include <cstdint>
#include <memory>
#include <fstream>
#include <cmath>

#include "Mandelbrot.hpp"

namespace fract
{

class BitMap
{
private:
	uint32_t m_width{0}, m_height{0};
	std::unique_ptr<uint8_t[]> m_pPixel{nullptr};
	Mandel mand;

public:
	BitMap(uint32_t width, uint32_t height);
	virtual ~BitMap() {};

	void setPixel(uint16_t x, uint16_t y, uint8_t red, uint8_t green, uint8_t blue);
	void setPixelScale(double x, double y, uint8_t red, uint8_t green, uint8_t blue);
	void setAllPixels(uint8_t red, uint8_t green, uint8_t blue, bool scale);
	void drawFractal();
	bool write(const std::string &fileName);
};

#pragma pack(2)

struct BitMapFileHeader
{
	char header[2]{'B', 'M'};
	uint32_t fileSize;
	uint32_t reserved{0};
	uint32_t dataOffset;
};

struct BitMapInfoHeader
{
	uint32_t headerSize{40};
	uint32_t width;
	uint32_t height;
	uint16_t planes{1};
	uint16_t bitsPerPixel{24};
	uint32_t compression{0};
	uint32_t dataSize{0};
	uint32_t horizontalResolution{2400};
	uint32_t verticalResolution{2400};
	uint32_t colors{0};
	uint32_t importantColors{0};
};

}

#endif
