#include<algorithm>
#include<iostream>
#include"MaxHeap.h"



MaxHeap::MaxHeap(int size )
	:m_size(0)
	, m_capacity(size)
{
	p = new int[m_capacity];
}
MaxHeap::~MaxHeap() {
	delete[]p;
	p = nullptr;
}
void MaxHeap::pop() {
	if (m_size == 0) {
		throw"Heap is empty!";
	}
	p[0] = p[m_size - 1];
	m_size--;
	siftdown(0);
}
void MaxHeap::push(int val) {
	if (m_size == m_capacity) {
		expand(2 * m_capacity);
	}
	p[m_size] = val;
	siftup(m_size++);
}
int MaxHeap::top()const {
	if (m_size == 0) {
		throw"Heap is empty!";
	}
	return p[0];
}
bool MaxHeap::empty()const {
	return m_size == 0;
}

void  MaxHeap::siftdown(int index) {
	int val = p[index];
	while (index < m_size / 2) {
		int child = 2 * index + 1;
		if (child + 1 < m_size && p[child + 1] > p[child]) {
			child = child + 1;
		}
		if (p[child] > val) {
			p[index] = p[child];
			index = child;
		}
		else {
			break;
		}
	}
	p[index] = val;
}
void  MaxHeap::siftup(int index) {
	int val = p[index];
	while (index > 0) {
		int father = (index - 1) / 2;
		if (p[father] < val) {
			p[index] = p[father];
			index = father;
		}
		else {
			break;
		}
	}
	p[index] = val;
}
 void  MaxHeap::expand(int newcapacity) {
	int* q = new int[newcapacity];
	std::copy(p, p + m_size, q);
	delete[]p;
	p = q;
	m_capacity = newcapacity;
}