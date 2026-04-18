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
	void push(int val) {
		if (m_size == 0) {
			front = rear = new Node(val);
			++m_size;
			return;
		}
		Node*node = new Node(val);
		rear->next = node;
		rear = node;
		++m_size;
	}
	void pop() {
		if (m_size == 0) {
			throw"Queue is empty!";
		}
		Node* temp = front;
		front = front->next;
		delete temp;
		--m_size;
	}
	int size()const {
		return m_size;
	}
	bool empty()const {
		return m_size == 0;
	}
	int peek()const {
		return front->data;
	}
};