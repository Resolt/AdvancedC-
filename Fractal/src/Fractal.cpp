#include "Fractal.hpp"

namespace fract
{

Fractal::Fractal(std::string &fileName, uint16_t width, uint16_t height)
{
	BM = BitMap(width, height);
	mand = Mandel();
	ZoomList zoomList(width, height);
	zoomList.add(width / 2, height / 2, 4.0 / width);
	zoomList.add(width / 2, height / 2, 4.0 / width);
	drawFractal();
	BM.write(fileName);
}

void Fractal::drawFractal()
{
	uint32_t iters;
	// uint8_t red, green, blue;
	uint8_t color;
	double x_scale, y_scale;

	uint16_t f_scale = std::min(this->BM.getWidth(), this->BM.getHeight());

	uint16_t shift = (double)this->BM.getWidth() * 0.25;
	shift = shift * std::min(this->BM.getWidth(), this->BM.getHeight()) / std::max(this->BM.getWidth(), this->BM.getHeight());
	// uint16_t shift = (double)f_scale * 0.25;

	std::unique_ptr<size_t[]> histogram(new size_t[Mandel::MAX_IT]{0});

	std::unique_ptr<uint16_t[]> IterMap(new uint16_t[this->BM.getHeight() * this->BM.getWidth()]{0});

	for (uint16_t x = 0; x < this->BM.getWidth(); x++)
	{
		for (uint16_t y = 0; y < this->BM.getHeight(); y++)
		{
			x_scale = (x - (double)this->BM.getWidth() / 2 - shift) * 2.0 / f_scale;
			y_scale = (y - (double)this->BM.getHeight() / 2) * 2.0 / f_scale;

			iters = this->mand.getIterations(x_scale, y_scale);

			IterMap[y * this->BM.getWidth() + x] = iters;

			if (iters < Mandel::MAX_IT)
			{
				histogram[iters]++;
			}
		}
	}

	size_t histSum = 0;
	for (size_t i = 0; i < Mandel::MAX_IT; i++)
	{
		histSum += histogram[i];
	}

	uint16_t cIters;
	double hue;

	uint8_t red, green, blue;

	for (uint16_t x = 0; x < this->BM.getWidth(); x++)
	{
		for (uint16_t y = 0; y < this->BM.getHeight(); y++)
		{
			cIters = IterMap[y * this->BM.getWidth() + x];

			red = 0;
			green = 0;
			blue = 0;

			if (cIters != Mandel::MAX_IT)
			{
				color = 256 * (double)cIters / Mandel::MAX_IT;

				hue = 0.0;

				for (size_t i = 0; i < cIters; i++)
				{
					hue += (double)histogram[i] / histSum;
				}

				red = pow(255, hue);
			}

			BM.setPixel(x, y, red, green, blue);
		}
	}
}

} // namespace fract