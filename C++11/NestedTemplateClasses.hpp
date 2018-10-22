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
		return interator(0, *this);
	}

	iterator end()
	{
		return iterator(this->buzz.size(), *this);
	}

	void print()
	{
		for (auto &c : this->buff)
		{
			std::cout << c << std::endl;
		}
	}

	class iterator;
};

template <typename T>
class Ring<T>::iterator
{
private:
	size_t pos;
	Ring &circ;

public:
	// iterator(){};
	iterator(size_t &pos, Ring &circ) : pos(pos), circ(circ){};

	// iterator(const iterator &other)
	// {
	// 	this->pos = other.pos;
	// 	this->circ = other.circ;
	// }

	iterator &operator ++ (int)
	{
		this->pos++;
		return *this;
	}

	T &operator *()
	{
		return this->circ.get(this->pos);
	}
};

#endif