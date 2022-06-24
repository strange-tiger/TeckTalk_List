#pragma once

#include <utility>

// ���� ����Ʈ
class LinearList
{
public:
    LinearList() = default;

    explicit LinearList(size_t count);

    LinearList& operator=(LinearList rhs);

    ~LinearList();

    void clear();

    // pos�� value�� �����մϴ�.
    // ���̻� ���� �� ���� ����� �ƹ��͵� ���� �ʽ��ϴ�.
    // ����)
    // ���� ���� ����Ʈ�� { 1, 2, 3 }�̶�� �� ��,
    // Insert(1, 4); �� ȣ���ϸ�
    // { 1, 4, 2, 3 }���� �����Ͱ� ���Ե˴ϴ�.
    void Insert(int pos, int value);

    // pos�� ���Ҹ� �����ϰ�, ���ŵ� ���Ҹ� ��ȯ�մϴ�.
    // ���� ���Ұ� ���� ��� -1�� ��ȯ�մϴ�.
    // ����)
    // ���� ���� ����Ʈ�� { 1, 2, 3 }�̶�� �� ��,
    // Remove(1); �� ȣ���ϸ�
    // { 1, 3 }���� �ٲ��, 2�� ��ȯ�˴ϴ�.
    int Remove(int pos);

    // ���� ����Ʈ���� value�� ã���ϴ�. ã���� true, �ƴϸ� false�Դϴ�.
    // ����)
    // ���� ���� ����Ʈ�� { 1, 2, 3 }�̶�� �� ��,
    // Find(1);�� ȣ���ϸ� true,
    // Find(4);�� ȣ���ϸ� false�Դϴ�.
    bool Find(int value);

    // pos�� ����Ǿ� �ִ� ���� ��ȯ�մϴ�.
    // ���Ե� �����Ͱ� ���� ���, -1�Դϴ�.
    // ����)
    // ���� ���� ����Ʈ�� { 1, 2, 3 }�̶�� �� ��,
    // GetElement(0);�̸� 1,
    // GetElement(2);�̸� 3�Դϴ�.
    // GetElement(4);�̸� -1�Դϴ�.
    int GetElement(int pos);
private:
    int*    _container = nullptr;
    size_t  _size = 0;
    size_t  _capacity = 0;
};

// ���� ���� ����Ʈ
class LinkedList
{
    struct Node
    {
        // ����� ������ �˾Ƽ� ����
    };
public:
    // pos�� ����Ǿ� �ִ� ���� ��ȯ�մϴ�.
    // ã�� �� ���� ��� -1�Դϴ�.
    // ����)
    // ���� ���� ����Ʈ�� { 1, 2, 3 }�̶�� �� ��,
    // GetElement(0);�̸� 1,
    // GetElement(2);�̸� 3�Դϴ�.
    // GetElement(4);�̸� -1�Դϴ�.
    int GetElement(int pos);

    // ���� ����Ʈ�� ���� ������ �����͸� �����մϴ�.
    // ����)
    // ���� ���� ����Ʈ�� { 1, 2, 3 }�̶�� �� ��,
    // Insert(10);�̸� { 10, 1, 2, 3 }�Դϴ�.
    void Insert(int value);

    // pos�� ����� �����͸� �����ϰ� ��ȯ�մϴ�.
    // �����Ͱ� ���� ��� -1�Դϴ�.
    // ����)
    // ���� ���� ����Ʈ�� { 1, 2, 3 }�̶�� �� ��,
    // Remove(1);�̸� ��ȯ���� 2, ����Ʈ�� { 1, 3 }�Դϴ�.
    // Remove(4);�̸� ��ȯ���� -1�Դϴ�.
    int Remove(int pos);

    // value�� �ִٸ� true, ������ false�Դϴ�.
    bool Find(int value);
};

// ����
class Stack
{
public:
    // ���ÿ� value�� �����մϴ�.
    // �� �� ��� �ƹ��͵� ���� �ʽ��ϴ�.
    void Push(int value);

    // ���ÿ��� �����͸� ������, ��ȯ�մϴ�.
    // ���ÿ� �����Ͱ� ���� ��� -1�� ��ȯ�մϴ�.
    int Pop();

    // ���ÿ� ���� ���� �ִ� �����͸� ��ȯ�մϴ�.
    // ���ÿ� �����Ͱ� ���� ��� -1�� ��ȯ�մϴ�.
    int Top();

    // ������ ����ٸ� true, �ƴϸ� false�Դϴ�.
    bool IsEmpty();
};

// ���� ť
class Queue
{
public:
    // ť�� value�� �����մϴ�.
    // �� �� ��� �ƹ��͵� ���� �ʽ��ϴ�.
    void Enqueue(int value);

    // ť���� �����͸� ������, ��ȯ�մϴ�.
    // ť�� �����Ͱ� ���� ��� -1�� ��ȯ�մϴ�.
    int Dequeue();

    // ť���� �տ� �ִ� ���Ҹ� ��ȯ�մϴ�.
    // ť�� �����Ͱ� ���� ��� -1�� ��ȯ�մϴ�.
    int GetFront();

    // ť���� �ڿ� �ִ� ���Ҹ� ��ȯ�մϴ�.
    // ť�� �����Ͱ� ���� ��� -1�� ��ȯ�մϴ�.
    int GetBack();

    // ť�� ����ٸ� true, �ƴϸ� false�Դϴ�.
    bool IsEmpty();
};