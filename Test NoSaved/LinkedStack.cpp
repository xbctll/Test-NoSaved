#include"LinkedStack.h"

LinkedStack::LinkedStack()
	:m_size(0)
	, m_top(nullptr)
{
}
LinkedStack::~LinkedStack() {
	while (m_top) {
		Node* temp = m_top;
		m_top = m_top->next;
		delete temp;
	}
}
void LinkedStack::push(int val) {
	Node* node = new Node(val);
	node->next = m_top;
	m_top = node;
	++m_size;
}
void LinkedStack::pop() {
	if (!m_top) {
		throw"Stack is empty";
	}
	Node* temp = m_top;
	m_top = m_top->next;
	delete temp;
	--m_size;
}
int LinkedStack::top()const {
	if (!m_top) {
		throw"Stack is empty";
	}
	return m_top->data;
}
int LinkedStack::size()const {
	return m_size;
}
bool LinkedStack::empty()const {
	return !m_top;
}