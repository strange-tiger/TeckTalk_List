#pragma once

#include <utility>

// 선형 리스트
class LinearList
{
public:
    LinearList() = default;

    explicit LinearList(size_t count);

    LinearList& operator=(LinearList rhs);

    ~LinearList();

    void clear();

    // pos에 value를 삽입합니다.
    // 더이상 넣을 수 없는 경우라면 아무것도 하지 않습니다.
    // 예시)
    // 기존 선형 리스트가 { 1, 2, 3 }이라고 할 때,
    // Insert(1, 4); 를 호출하면
    // { 1, 4, 2, 3 }으로 데이터가 삽입됩니다.
    void Insert(int pos, int value);

    // pos의 원소를 제거하고, 제거된 원소를 반환합니다.
    // 빼낼 원소가 없는 경우 -1를 반환합니다.
    // 예시)
    // 기존 선형 리스트가 { 1, 2, 3 }이라고 할 때,
    // Remove(1); 를 호출하면
    // { 1, 3 }으로 바뀌며, 2가 반환됩니다.
    int Remove(int pos);

    // 선형 리스트에서 value를 찾습니다. 찾으면 true, 아니면 false입니다.
    // 예시)
    // 기존 선형 리스트가 { 1, 2, 3 }이라고 할 때,
    // Find(1);을 호출하면 true,
    // Find(4);를 호출하면 false입니다.
    bool Find(int value);

    // pos에 저장되어 있는 값을 반환합니다.
    // 삽입된 데이터가 없는 경우, -1입니다.
    // 예시)
    // 기존 선형 리스트가 { 1, 2, 3 }이라고 할 때,
    // GetElement(0);이면 1,
    // GetElement(2);이면 3입니다.
    // GetElement(4);이면 -1입니다.
    int GetElement(int pos);
private:
    int*    _container = nullptr;
    size_t  _size = 0;
    size_t  _capacity = 0;
};

// 이중 연결 리스트
class LinkedList
{
    struct Node
    {
        // 노드의 내용은 알아서 구현
    };
public:
    // pos에 저장되어 있는 값을 반환합니다.
    // 찾을 수 없는 경우 -1입니다.
    // 예시)
    // 기존 선형 리스트가 { 1, 2, 3 }이라고 할 때,
    // GetElement(0);이면 1,
    // GetElement(2);이면 3입니다.
    // GetElement(4);이면 -1입니다.
    int GetElement(int pos);

    // 연결 리스트의 시작 지점에 데이터를 삽입합니다.
    // 예시)
    // 기존 연결 리스트가 { 1, 2, 3 }이라고 할 때,
    // Insert(10);이면 { 10, 1, 2, 3 }입니다.
    void Insert(int value);

    // pos에 저장된 데이터를 삭제하고 반환합니다.
    // 데이터가 없는 경우 -1입니다.
    // 예시)
    // 기존 연결 리스트가 { 1, 2, 3 }이라고 할 때,
    // Remove(1);이면 반환값은 2, 리스트는 { 1, 3 }입니다.
    // Remove(4);이면 반환값은 -1입니다.
    int Remove(int pos);

    // value가 있다면 true, 없으면 false입니다.
    bool Find(int value);
};

// 스택
class Stack
{
public:
    // 스택에 value를 삽입합니다.
    // 다 찬 경우 아무것도 하지 않습니다.
    void Push(int value);

    // 스택에서 데이터를 꺼내고, 반환합니다.
    // 스택에 데이터가 없는 경우 -1를 반환합니다.
    int Pop();

    // 스택에 가장 위에 있는 데이터를 반환합니다.
    // 스택에 데이터가 없는 경우 -1를 반환합니다.
    int Top();

    // 스택이 비었다면 true, 아니면 false입니다.
    bool IsEmpty();
};

// 원형 큐
class Queue
{
public:
    // 큐에 value를 삽입합니다.
    // 다 찬 경우 아무것도 하지 않습니다.
    void Enqueue(int value);

    // 큐에서 데이터를 꺼내고, 반환합니다.
    // 큐에 데이터가 없는 경우 -1를 반환합니다.
    int Dequeue();

    // 큐에서 앞에 있는 원소를 반환합니다.
    // 큐에 데이터가 없는 경우 -1를 반환합니다.
    int GetFront();

    // 큐에서 뒤에 있는 원소를 반환합니다.
    // 큐에 데이터가 없는 경우 -1를 반환합니다.
    int GetBack();

    // 큐가 비었다면 true, 아니면 false입니다.
    bool IsEmpty();
};