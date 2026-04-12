#pragma once



class LinkedStack {
private:
	struct Node {
		int data;
		Node* next;
		Node(int val=0)
			:data(val)
			,next(nullptr){}
	};
	Node* m_top;
	int m_size;
public:
	LinkedStack();
	~LinkedStack();
	void push(int val);
	void pop();
	int top()const;
	int size()const;
	bool empty()const;
private:
	LinkedStack(const LinkedStack& s) = delete;
	LinkedStack& operator=(const LinkedStack& s) = delete;
};
