#pragma once
#include<algorithm>

class SeqStack {
private:
	int* m_p;
	int m_top;
	int m_capacity;
public:
	SeqStack(int capacity=10);
	~SeqStack();
	void push(int val);
	void pop();
	int top();
	bool empty();
	int size();
private:
	void  expand(int newcapacity);
	SeqStack(const SeqStack& s) = delete;
	SeqStack& operator=(const SeqStack& s) = delete;



};
