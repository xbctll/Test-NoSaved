#include"ArrayQueue.h"

ArrayQueue::ArrayQueue(int capacity)
	:m_size(0)
	, m_capacity(capacity)
	, front(0)
	, rear(0)
{
	m_p = new int[capacity];
}
ArrayQueue::~ArrayQueue() {
	delete[]m_p;
	m_p = nullptr;
}
void ArrayQueue::push(int val) {
	if (m_size == m_capacity) {
		expand(2 * m_capacity);
	}
	m_p[rear] = val;
	rear = (rear + 1) % m_capacity;
	++m_size;
}
void ArrayQueue::pop() {
	if (m_size == 0) {
		throw"Queue is empty!";
	}
	front = (front + 1) % m_capacity;
	--m_size;
}
int ArrayQueue::peek()const {
	if (m_size == 0) {
		throw"Queue is empty!";
	}
	return m_p[front];
}
bool ArrayQueue::empty()const {
	if (m_size == 0) {
		return true;
	}
	return false;
}
int ArrayQueue::size()const {
	return m_size;
}


void ArrayQueue::expand(int capacity) {
	int* p = new int[capacity];
	if (front < rear) {
		std::move(m_p + front, m_p + rear, p);
	}
	else {
		std::move(m_p + front, m_p + m_capacity, p);
		std::move(m_p, m_p + rear, p + m_capacity - front);
	}
	delete[]m_p;
	m_p = p;
	m_capacity = capacity;
	front = 0;
	rear = m_size;
}