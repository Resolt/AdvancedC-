#include "BitMap.hpp"

namespace fract
{

void BitMap::setPixel(uint16_t x, uint16_t y, uint8_t red, uint8_t green, uint8_t blue)
{
	uint8_t *pPixel = this->m_pPixel.get();

	pPixel += (y * 3) * this->m_width + (x * 3);	

	pPixel[0] = blue;
	pPixel[1] = green;
	pPixel[2] = red;
}

void BitMap::setPixelScale(double x, double y, uint8_t red, uint8_t green, uint8_t blue)
{
	if(x > 1.000 || x < -1.000 || y > 1.000 || y < -1.000)
	{
		return;
	}

	uint8_t *pPixel = this->m_pPixel.get();

	uint16_t x_pos = std::round((this->m_width) * (x + 1) / 2);
	uint16_t y_pos = std::round((this->m_height-1) * (y + 1) / 2);

	// std::cout << x << " " << x_pos << "\t" << y << " " << y_pos << std::endl; 

	setPixel(x_pos, y_pos, red, green, blue);
}

void BitMap::setAllPixels(uint8_t red, uint8_t green, uint8_t blue, bool scale)
{
	if(scale)
	{
		double x_inc = 2.000 / this->m_width;
		double y_inc = 2.000 / this->m_height;

		for (double x = -1.000; x <= 1.000; x += x_inc)
		{
			for (double y = -1.000; y <= 1.000; y += y_inc)
			{
				setPixelScale(x, y, red, green, blue);
			}
		}
	}
	else
	{
		for (uint16_t x = 0; x < this->m_width; x++)
		{
			for (uint16_t y = 0; y < this->m_height; y++)
			{
				setPixel(x, y, red, green, blue);
			}
		}
	}	
}

bool BitMap::write(const std::string &fileName)
{
	// INSTANTIATE THE STRUCTS
	BitMapFileHeader fileHeader;
	BitMapInfoHeader infoHeader;

	// SET THE TOTAL SIZE OF THE FILE
	fileHeader.fileSize = sizeof(BitMapFileHeader) + sizeof(BitMapInfoHeader) + this->m_width * this->m_height * 3;
	// SET THE DATA OFFSET
	fileHeader.dataOffset = sizeof(BitMapFileHeader) + sizeof(BitMapInfoHeader);

	// SET INFOHEADER DATA
	infoHeader.width = this->m_width;
	infoHeader.height = this->m_height;

	// OPEN THE FILE
	std::ofstream file;
	file.open(fileName, std::ios::out|std::ios::binary);

	// CHECK THAT FILE IS OPEN
	if(!file)
	{
		return false;
	}

	// WRITE THE DATA TO FILE - REINTERPRET CASTS ARE STILL VERY DANGEROUS BUT IN THIS CASE IT SUITS THE PURPOSE
	file.write(reinterpret_cast<const char *>(&fileHeader), sizeof(BitMapFileHeader));
	file.write(reinterpret_cast<const char *>(&infoHeader), sizeof(BitMapInfoHeader));
	file.write(reinterpret_cast<const char *>(this->m_pPixel.get()), this->m_width * this->m_height * 3);

	// WRAP IT UP
	file.close();
	return true;
}

} //namespace fract
