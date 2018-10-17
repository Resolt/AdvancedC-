#include "iostream"
#include "fstream"
#include "vector"

int main()
{
	size_t w = 1920;
	size_t h = 1080;

	size_t elems = w * h * 3;

	// float * nums = new float[elems];
	std::vector<float> nums(elems);

	// WRITE

	std::ofstream ofile;
	ofile.open("test.bin", std::ios::binary);

	if (ofile.is_open())
	{
		std::cout << "A" << std::endl;
		ofile.write(reinterpret_cast<const char *>(&h), sizeof(h));
		std::cout << "B" << std::endl;
		ofile.write(reinterpret_cast<const char *>(&w), sizeof(w));
		std::cout << "C" << std::endl;
		// ofile.write(reinterpret_cast<char *>(nums), sizeof(float) * elems);
		ofile.write(reinterpret_cast<const char *>(&nums[0]), elems * sizeof(float));

		ofile.close();
	}

	// READ

	size_t w_new, h_new;

	std::ifstream ifile;
	ifile.open("test.bin", std::ios::binary);

	if(ifile.is_open())
	{
		std::cout << "A" << std::endl;
		ifile.read(reinterpret_cast<char *>(&h_new), sizeof(h_new));
		std::cout << "B" << std::endl;
		ifile.read(reinterpret_cast<char *>(&w_new), sizeof(w_new));
		std::cout << "C" << std::endl;

		size_t elems_new = w_new * h_new * 3;

		std::cout << w_new << std::endl
							<< h_new << std::endl
							<< elems_new << std::endl;

		// float * nums_new = new float[elems_new];
		std::vector<float> nums_new(elems_new);

		ifile.read(reinterpret_cast<char *>(&nums_new[0]), sizeof(float) * elems_new);

		ifile.close();
	}

	std::remove("test.bin");

	return 0;
}

