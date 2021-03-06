#ifndef BITMAPFILE_HPP_
#define BITMAPFILE_HPP_

#include <memory>
#include <fstream>
#include <math.h>

#include "Mandelbrot.hpp"

namespace fract
{

class BitMap
{
private:
	uint16_t m_width{0}, m_height{0};
	std::unique_ptr<uint8_t[]> m_pPixel{nullptr};

public:
	BitMap(){};
	BitMap(uint16_t width, uint16_t height) : m_height(height), m_width(width), m_pPixel(new uint8_t[width * height * 3]{0}){};
	virtual ~BitMap(){};

	BitMap &operator = (const BitMap &other)
	{
		this->m_height = other.m_height;
		this->m_width = other.m_width;

		size_t l = this->m_width * this->m_height * 3;

		this->m_pPixel = std::unique_ptr<uint8_t[]>(new uint8_t[l]{0});

		for (size_t i = 0; i < l; i++)
		{
			this->m_pPixel[i] = other.m_pPixel[i];
		}
	}

	uint16_t getWidth() { return this->m_width; };
	uint16_t getHeight() { return this->m_height; };

	void setPixel(uint16_t x, uint16_t y, uint8_t red, uint8_t green, uint8_t blue);
	void setPixelScale(double x, double y, uint8_t red, uint8_t green, uint8_t blue);
	void setAllPixels(uint8_t red, uint8_t green, uint8_t blue, bool scale);
	
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

} // namespace fract

#endif
