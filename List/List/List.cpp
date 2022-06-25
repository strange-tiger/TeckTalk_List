#include "TechTalk_Linear.h"
#include <iostream>

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
	if (_size >= _capacity || pos >= _capacity || pos < 0)
	{
		return;
	}

	// 2. ����
	if (_container[pos] != 0)
	{
		for (int i = _capacity - 1; i > pos; --i)
		{
			// 2-1. ��ġ i�� �� _size���� pos�� ���� ������ �ϳ��� �տ��� �ڷ� ����
			_container[i] = _container[i - 1];
		}
	}

	// 3. ��ġ pos�� value �Ҵ�
	_container[pos] = value;

	// 4. _size ������Ʈ
	++_size;
}

int LinearList::Remove(int pos)
{
	// 1. ����ִٸ� -1 ��ȯ
	if (_size == 0 || pos >= _capacity || pos < 0)
	{
		return -1;
	}

	// 2. ������ ��ȯ�� ���� ������ ��� ����
	int removed = _container[pos];
	
	// 3. ������ ���� �� �̵�
	for (int i = pos; i <= _size; ++i)
	{
		// 3-1. ��ġ i�� pos���� _size�� ���� ������ �ϳ��� �ڿ��� ������ ����
		_container[i] = _container[i + 1];
	}

	// 4. _size ������Ʈ
	--_size;
	
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
	// ���Ե� �����Ͱ� �ִ� == pos�� _size���� �۰� 0���� ũ�ų� ����.
	if (pos < _size && pos >= 0)
	{
		return _container[pos];
	}
	else
	{
		return -1;
	}
}

// Linked List ���� ����Ʈ
LinkedList::Node::Node(int data, Node* prev, Node* next)
	: Data(data), Prev(prev), Next(next)
{

}

int LinkedList::GetElement(int pos)
{
	Node* where;

	// 1. pos ��ġ�� Node�� ã�´�.
	if (pos <= _size - pos)
	{
		where = _start;
		// _start���� pos��ŭ Node�� �̵�
		for (int i = 0; i <= pos; ++i)
		{
			where = where->Next;
		}
	}
	else
	{
		where = _end;
		// _end���� pos��ŭ Node�� �̵�
		for (int i = _size; i >= pos; --i)
		{
			where = where->Prev;
		}
	}

	// 2. ã�Ҵٸ� Node�� �����͸� ��ȯ�ϰ�, �� ã�Ҵٸ� -1�� ��ȯ�Ѵ�.
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
	// 1. ���ο� Node�� �����Ѵ�.
	Node* nextNode = _start->Next;
	Node* newNode = new Node(value, _start, nextNode);

	// 2. ���ο� Node�� �յ��� Node�� �����Ѵ�.
	_start->Next = newNode;
	nextNode->Prev = newNode;

	// 3. _size�� ������Ʈ�Ѵ�.
	++_size;
}

int LinkedList::Remove(int pos)
{
	Node* removed;

	// 1. pos ��ġ�� Node�� ã�´�.
	if (pos <= _size - pos)
	{
		removed = _start;
		// _start���� pos��ŭ ��带 �̵�
		for (int i = 0; i <= pos; ++i)
		{
			removed = removed->Next;
		}
	}
	else
	{
		removed = _end;
		// _end���� pos��ŭ ��带 �̵�
		for (int i = _size; i > pos; --i)
		{
			removed = removed->Prev;
		}
	}

	// 2. ã�Ҵٸ� Node�� �����ϰ� ���� ��ȯ�Ѵ�.
    // Node�� ���� ��� -1�� ��ȯ�Ѵ�.
	// �����Ͱ� �ִ� == pos�� _size���� �۰� 0���� ũ�ų� ����.
	if (pos < _size && pos >= 0)
	{
		Node* removedPrev = removed->Prev;
		Node* removedNext = removed->Next;

		int temp = removed->Data;
		
		removedPrev->Next = removedNext;
		removedNext->Prev = removedPrev;

		delete removed;

		// 3. _size�� ������Ʈ�Ѵ�.
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
	// 1. Node ��ü�� Ž���Ѵ�.
	for (Node* i = _start->Next; i != _end; i = i->Next)
	{
		// 2-1. value�� �ִٸ� true�� ��ȯ�Ѵ�.
		if (i->Data == value)
		{
			return true;
		}
	}

	// 2-2. ���ٸ� false�� ��ȯ�Ѵ�.
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

	std::cout << "���� ����Ʈ" << '\n';
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


	// ���� Insert() : ����Ʈ�� ���� ������ ������ value�� �����Ѵ�.
	for (int i = 1; i <= 3; ++i)
	{
		list.Insert(i); // start [1][2][3] end
	}

	std::cout << "���� ����Ʈ" << '\n';
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