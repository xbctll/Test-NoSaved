#include"ArrayStack.h"




ArrayStack::ArrayStack(int capacity)
	:m_top(0)
	, m_capacity(capacity)
{
	m_p = new int[capacity];
}
ArrayStack::~ArrayStack() {
	delete[]m_p;
	m_p = nullptr;
}
void ArrayStack::push(int val) {
	if (m_top == m_capacity) {
		expand(2 * m_capacity);
	}
	m_p[m_top++] = val;
}
void ArrayStack::pop() {
	if (m_top == 0) {
		throw"Stack is empty!";
	}
	m_top--;
}
int ArrayStack::top() {
	if (m_top == 0) {
		throw"Stack is empty!";
	}
	return m_p[m_top - 1];
}
bool ArrayStack::empty() {
	return m_top == 0;
}
int ArrayStack::size() {
	return m_top;
}


void ArrayStack::expand(int newcapacity) {
	int* temp = new int[newcapacity];
	std::copy(m_p, m_p + m_top, temp);
	delete[]m_p;
	m_p = temp;
	m_capacity = newcapacity;
}