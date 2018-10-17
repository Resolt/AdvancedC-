#include <iostream>

template<class T, class K>
class Test
{
private:
	T obj1;
	K obj2;

public:
	Test(T obj)
	{
		this->obj1 = obj;
		this->obj2 = (float)0.0005f;
	};

	Test(K obj)
	{
		this->obj1 = (double)5.3;
		this->obj2 = obj;
	};

	Test(T obj1, K obj2)
	{
		this->obj1 = obj1;
		this->obj2 = obj2;
	};

	friend std::ostream &operator << (std::ostream &out, const Test &other)
	{
		out << other.obj1 << " " << other.obj2;
		return out;
	}
};