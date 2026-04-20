#include"LinkedQueue.h"



void LinkedQueue::push(int val) {
	if (m_size == 0) {
		front = rear = new Node(val);
		++m_size;
		return;
	}
	Node* node = new Node(val);
	rear->next = node;
	rear = node;
	++m_size;
}
void LinkedQueue::pop() {
	if (m_size == 0) {
		throw"Queue is empty!";
	}
	Node* temp = front;
	front = front->next;
	delete temp;
	--m_size;
}
int LinkedQueue::size()const {
	return m_size;
}
bool LinkedQueue::empty()const {
	return m_size == 0;
}
int LinkedQueue::peek()const {
	return front->data;
}