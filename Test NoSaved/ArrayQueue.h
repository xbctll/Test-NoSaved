#pragma once
#include<algorithm>



class ArrayQueue {
private:
	int* m_p;
	int m_size;
	int m_capacity;
	int front;
	int rear;
public:
	ArrayQueue(int capacity = 10);
		
	~ArrayQueue();
	void push(int val);
	void pop();
	int peek()const;
	bool empty()const;
	int size()const;
private:
	void expand(int capacity);
	ArrayQueue(const ArrayQueue& q) = delete;
	ArrayQueue& operator=(const ArrayQueue& q) = delete;
};