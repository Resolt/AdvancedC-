#ifndef RING_HPP_
#define RING_HPP_

#include <iostream>
#include <vector>

template <typename T>
class Ring
{
private:
	std::vector<T> buff;
	size_t point = 0;

public:
	Ring(size_t size)
	{
		this->buff.resize(size);
	}

	class iterator;

	void add(T obj)
	{
		this->buff[this->point] = obj;
		if (this->point == this->buff.size() - 1)
		{
			this->point = 0;
		}
		else
		{
			this->point++;
		}
	}

	T &get(size_t i)
	{
		return this->buff[i];
	}

	size_t getSize()
	{
		return this->buff.size();
	}

	iterator begin()
	{
		return iterator(0, *this);
	}

	iterator end()
	{
		return iterator(this->buff.size(), *this);
	}

	void print()
	{
		for (auto &c : this->buff)
		{
			std::cout << c << std::endl;
		}
	}

};

template <typename T>
class Ring<T>::iterator
{
private:
	size_t pos;
	Ring &circ;

public:
	iterator(size_t pos, Ring &circ) : pos(pos), circ(circ){};

	iterator &operator ++ (int)
	{
		this->pos++;
		return *this;
	}

	T &operator *()
	{
		return this->circ.get(this->pos);
	}

	friend bool operator == (const iterator &iter1, const iterator &iter2)
	{
		return iter1.pos == iter2.pos && &(iter1.circ) == &(iter2.circ);
	}

	friend bool operator != (const iterator &iter1, const iterator &iter2)
	{
		return iter1.pos != iter2.pos || &(iter1.circ) != &(iter2.circ);
	}
};

#endif