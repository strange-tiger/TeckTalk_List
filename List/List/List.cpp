#include "TechTalk_Linear.h"

// Linear List 선형 리스트
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
	// 1. 용량_capacity가 부족해 더 이상 데이터를 넣을 수 없다면 아무것도 하지 않는다.
	if (_size == _capacity)
	{
		return;
	}

	// 2. 삽입
	for (int i = _size; i != pos; --i)
	{
		// 2-1. 위치 i가 뒤 _size부터 pos에 달할 때까지 하나씩 앞에서 뒤로 복사
		_container[i] = _container[i - 1];
	}

	// 3. _size 업데이트
	++_size;

	// 4. 위치 pos에 value 할당
	_container[pos] = value;
}

int LinearList::Remove(int pos)
{
	// 1. 비어있다면 -1 반환
	if (_size == 0)
	{
		return -1;
	}

	// 2. 데이터 반환을 위해 삭제될 요소 저장
	int removed = _container[pos];
	
	// 3. 데이터 삭제 및 이동
	for (int i = pos; i != _size; ++i)
	{
		// 3-1. 위치 i가 pos부터 _size에 달할 때까지 하나씩 뒤에서 앞으로 복사
		_container[i] = _container[i + 1];
	}

	// 4. _size 업데이트
	++_size;
	
	// 5. 삭제된 요소 반환
	return removed;
}

bool LinearList::Find(int value)
{
	// _container 전체를 탐색
	for (int i = 0; i < _size; i++)
	{
		// value가 있다면 true
		if (_container[i] == value)
		{
			return true;
		}
	}

	// 없다면 false
	return false;
}

int LinearList::GetElement(int pos)
{
	// 삽입된 데이터가 있다 == pos가 _size보다 작거나 같다.
	if (pos <= _size)
	{
		return _container[pos];
	}
	else
	{
		return -1;
	}
}

// Linked List 연결 리스트
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