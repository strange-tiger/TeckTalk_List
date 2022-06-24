#include "TechTalk_Linear.h"

inline LinearList::LinearList(size_t count)
	: _container(new int[count]), _size(count), _capacity(count)
{
	for (size_t i = 0; i < count; ++i)
	{
		_container[i] = 0;
	}
}

LinearList& LinearList::operator=(LinearList rhs)
{
	std::swap(_container, rhs._container);
	std::swap(_size, rhs._size);
	std::swap(_capacity, rhs._capacity);

	return *this;
}

inline LinearList::~LinearList()
{
	clear();
}

void LinearList::clear()
{
	delete[] _container;
	_container = nullptr;
	_size = 0;
	_capacity = 0;
}

void LinearList::Insert(int pos, int value)
{
	if (_size == _capacity)
	{
		return;
	}

	for (int i = _size; i != pos; --i)
	{
		_container[i] = _container[i - 1];
	}
	++_size;

	_container[pos] = value;
}

int LinearList::Remove(int pos)
{
	return 0;
}

bool LinearList::Find(int value)
{
	return false;
}

int LinearList::GetElement(int pos)
{
	return 0;
}

int LinkedList::GetElement(int pos)
{
	return 0;
}

void LinkedList::Insert(int value)
{

}

int LinkedList::Remove(int pos)
{
	return 0;
}

bool LinkedList::Find(int value)
{
	return false;
}