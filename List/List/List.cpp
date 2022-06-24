#include "TechTalk_Linear.h"

// Linear List ���� ����Ʈ
inline LinearList::LinearList(int count)
	: _container(new int[count]), _size(0), _capacity(count)
{
	for (int i = 0; i < count; ++i)
	{
		_container[i] = 0;
	}
}

inline LinearList::LinearList(const LinearList& other)
	: _container(new int[other._capacity]), _size(other._size), _capacity(other._capacity)
{
	for (int i = 0; i < _size; ++i)
	{
		_container[i] = other._container[i];
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
	// 1. �뷮_capacity�� ������ �� �̻� �����͸� ���� �� ���ٸ� �ƹ��͵� ���� �ʴ´�.
	if (_size == _capacity)
	{
		return;
	}

	// 2. ����
	for (int i = _size; i != pos; --i)
	{
		// 2-1. ��ġ i�� �� _size���� pos�� ���� ������ �ϳ��� �տ��� �ڷ� ����
		_container[i] = _container[i - 1];
	}

	// 3. _size ������Ʈ
	++_size;

	// 4. ��ġ pos�� value �Ҵ�
	_container[pos] = value;
}

int LinearList::Remove(int pos)
{
	// 1. ����ִٸ� -1 ��ȯ
	if (_size == 0)
	{
		return -1;
	}

	// 2. ������ ��ȯ�� ���� ������ ��� ����
	int removed = _container[pos];
	
	// 3. ������ ���� �� �̵�
	for (int i = pos; i != _size; ++i)
	{
		// 3-1. ��ġ i�� pos���� _size�� ���� ������ �ϳ��� �ڿ��� ������ ����
		_container[i] = _container[i + 1];
	}

	// 4. _size ������Ʈ
	++_size;
	
	// 5. ������ ��� ��ȯ
	return removed;
}

bool LinearList::Find(int value)
{
	// _container ��ü�� Ž��
	for (int i = 0; i < _size; i++)
	{
		// value�� �ִٸ� true
		if (_container[i] == value)
		{
			return true;
		}
	}

	// ���ٸ� false
	return false;
}

int LinearList::GetElement(int pos)
{
	// ���Ե� �����Ͱ� �ִ� == pos�� _size���� �۰ų� ����.
	if (pos <= _size)
	{
		return _container[pos];
	}
	else
	{
		return -1;
	}
}

// Linked List ���� ����Ʈ
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