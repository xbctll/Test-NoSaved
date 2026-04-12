#pragma once
#include<algorithm>

class ArrayStack {
private:
	int* m_p;
	int m_top;
	int m_capacity;
public:
	ArrayStack(int capacity=10);
	~ArrayStack();
	void push(int val);
	void pop();
	int top();
	bool empty();
	int size();
private:
	void  expand(int newcapacity);
	ArrayStack(const ArrayStack& s) = delete;
	ArrayStack& operator=(const ArrayStack& s) = delete;



};
