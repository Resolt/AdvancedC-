#include <vector>
#include <iostream>

int main(int argc, char const *argv[])
{
	std::vector<std::string> strings(10);

	// for (std::vector<std::string>::iterator iter = strings.begin(); iter != strings.end(); iter++)
	// {
	// 	*iter = "A";
	// }

	char a = 65;

	for (auto & string : strings)
	{
		string = a;
		a++;
	}

	for(const auto &string : strings)
	{
		//std::cout << string << std::endl;
	}

	std::vector<double> nums;

	size_t cap = nums.capacity();

	for (size_t i = 0; i < 10000; i++)
	{
		nums.push_back(i);

		if(cap != nums.capacity())
		{
			cap = nums.capacity();
			std::cout << "Cap: " << cap << std::endl;
		}
	}

	nums.clear();

	std::cout << "Size: " << nums.size() << std::endl;
	std::cout << "Capacity: " << nums.capacity() << std::endl;

	std::vector<std::vector<uint64_t>> twodim(3, std::vector<uint64_t>(4, 7));

	for(auto &row : twodim)
	{
		for(auto &col : row)
		{
			std::cout << col;
		}
		std::cout << std::endl << std::flush;
	}

	return 0;
}
