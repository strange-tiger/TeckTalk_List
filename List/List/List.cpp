#include "TechTalk_Linear.h"
#include <iostream>

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
	if (_size >= _capacity || pos >= _capacity || pos < 0)
	{
		return;
	}

	// 2. 삽입
	if (_container[pos] != 0)
	{
		for (int i = _capacity - 1; i > pos; --i)
		{
			// 2-1. 위치 i가 뒤 _size부터 pos에 달할 때까지 하나씩 앞에서 뒤로 복사
			_container[i] = _container[i - 1];
		}
	}

	// 3. 위치 pos에 value 할당
	_container[pos] = value;

	// 4. _size 업데이트
	++_size;
}

int LinearList::Remove(int pos)
{
	// 1. 비어있다면 -1 반환
	if (_size == 0 || pos >= _capacity || pos < 0)
	{
		return -1;
	}

	// 2. 데이터 반환을 위해 삭제될 요소 저장
	int removed = _container[pos];
	
	// 3. 데이터 삭제 및 이동
	for (int i = pos; i <= _size; ++i)
	{
		// 3-1. 위치 i가 pos부터 _size에 달할 때까지 하나씩 뒤에서 앞으로 복사
		_container[i] = _container[i + 1];
	}

	// 4. _size 업데이트
	--_size;
	
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
	// 삽입된 데이터가 있다 == pos가 _size보다 작고 0보다 크거나 같다.
	if (pos < _size && pos >= 0)
	{
		return _container[pos];
	}
	else
	{
		return -1;
	}
}

// Linked List 연결 리스트
LinkedList::Node::Node(int data, Node* prev, Node* next)
	: Data(data), Prev(prev), Next(next)
{

}

int LinkedList::GetElement(int pos)
{
	Node* where;

	// 1. pos 위치의 Node를 찾는다.
	if (pos <= _size - pos)
	{
		where = _start;
		// _start부터 pos만큼 Node를 이동
		for (int i = 0; i <= pos; ++i)
		{
			where = where->Next;
		}
	}
	else
	{
		where = _end;
		// _end부터 pos만큼 Node를 이동
		for (int i = _size; i >= pos; --i)
		{
			where = where->Prev;
		}
	}

	// 2. 찾았다면 Node의 데이터를 반환하고, 못 찾았다면 -1을 반환한다.
	if (pos < _size && pos >= 0)
	{
		return where->Data;
	}
	else
	{
		return -1;
	}
}

void LinkedList::Insert(int value)
{
	// 1. 새로운 Node를 생성한다.
	Node* nextNode = _start->Next;
	Node* newNode = new Node(value, _start, nextNode);

	// 2. 새로운 Node와 앞뒤의 Node를 연결한다.
	_start->Next = newNode;
	nextNode->Prev = newNode;

	// 3. _size를 업데이트한다.
	++_size;
}

int LinkedList::Remove(int pos)
{
	Node* removed;

	// 1. pos 위치의 Node를 찾는다.
	if (pos <= _size - pos)
	{
		removed = _start;
		// _start부터 pos만큼 노드를 이동
		for (int i = 0; i <= pos; ++i)
		{
			removed = removed->Next;
		}
	}
	else
	{
		removed = _end;
		// _end부터 pos만큼 노드를 이동
		for (int i = _size; i > pos; --i)
		{
			removed = removed->Prev;
		}
	}

	// 2. 찾았다면 Node를 제거하고 값을 반환한다.
    // Node가 없는 경우 -1을 반환한다.
	// 데이터가 있다 == pos가 _size보다 작고 0보다 크거나 같다.
	if (pos < _size && pos >= 0)
	{
		Node* removedPrev = removed->Prev;
		Node* removedNext = removed->Next;

		int temp = removed->Data;
		
		removedPrev->Next = removedNext;
		removedNext->Prev = removedPrev;

		delete removed;

		// 3. _size를 업데이트한다.
		--_size;
		return temp;
	}
	else
	{
		return -1;
	}
}

bool LinkedList::Find(int value)
{
	// 1. Node 전체를 탐색한다.
	for (Node* i = _start->Next; i != _end; i = i->Next)
	{
		// 2-1. value가 있다면 true를 반환한다.
		if (i->Data == value)
		{
			return true;
		}
	}

	// 2-2. 없다면 false를 반환한다.
	return false;
}

int main()
{
	/*
	LinearList lst(3);

	lst.Insert(4, 4);
	lst.Insert(3, 3);
	lst.Insert(2, 2);
	lst.Insert(1, 1);
	lst.Insert(0, 0);

	std::cout << "선형 리스트" << '\n';
	std::cout << lst.Remove(3) << '\n';
	std::cout << "-1" << '\n';
	std::cout << lst.Remove(0) << '\n';
	std::cout << "0" << '\n';

	std::cout << std::boolalpha << lst.Find(0) << '\n';
	std::cout << "false" << '\n';
	std::cout << std::boolalpha << lst.Find(1) << '\n';
	std::cout << "true" << '\n';
	
	std::cout << lst.GetElement(0) << '\n';
	std::cout << "1" << '\n';
	std::cout << lst.GetElement(1) << '\n';
	std::cout << "2" << '\n';
	std::cout << lst.GetElement(2) << '\n';
	std::cout << "-1" << '\n';
	std::cout << lst.GetElement(3) << '\n';
	std::cout << "-1" << '\n';

	lst.clear();
	lst.~LinearList();
	*/

	LinkedList list;


	// 삽입 Insert() : 리스트의 시작 지점에 데이터 value를 삽입한다.
	for (int i = 1; i <= 3; ++i)
	{
		list.Insert(i); // start [1][2][3] end
	}

	std::cout << "연결 리스트" << '\n';
	std::cout << list.Remove(3) << '\n';
	std::cout << "3" << '\n';
	std::cout << list.Remove(0) << '\n';
	std::cout << "0" << '\n';
	std::cout << list.Remove(3) << '\n';
	std::cout << "-1" << '\n';

	std::cout << std::boolalpha << list.Find(0) << '\n';
	std::cout << "false" << '\n';
	std::cout << std::boolalpha << list.Find(1) << '\n';
	std::cout << "true" << '\n';

	std::cout << list.GetElement(0) << '\n';
	std::cout << "1" << '\n';
	std::cout << list.GetElement(1) << '\n';
	std::cout << "2" << '\n';
	std::cout << list.GetElement(2) << '\n';
	std::cout << "-1" << '\n';
	std::cout << list.GetElement(3) << '\n';
	std::cout << "-1" << '\n';

	list.~LinkedList();

	return 0;
}