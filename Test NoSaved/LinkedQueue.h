#pragma once

class LinkedQueue {
private:
	struct Node{
		Node(int val = 0)
			:data(val)
			,next(nullptr)
		{}
		int data;
		Node* next;
	};
	Node* front;
	Node* rear;
	int m_size;
public:
	LinkedQueue()
		:front(nullptr)
		,rear(nullptr)
		,m_size(0) 
	{}
	void push(int val);
	void pop();
	int size()const;
	bool empty()const;
	int peek()const;
};