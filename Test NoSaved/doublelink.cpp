#include"doublelink.h"





doublelink::doublelink()
	:m_size(0)
{
	head = new Node(0);
	head->next = head;
	head->pre = head;
}
doublelink::~doublelink() {
	if (!head)throw"Link is empty";
	Node* p = head->next;
	while (p != head) {
		head->next = p->next;
		delete p;
		p = head->next;
	}
	delete head;
	head = nullptr;
}
void doublelink::Inserthead(int val) {
	Node* node = new Node(val);
	node->next = head->next;
	node->next->pre = node;
	head->next = node;
	node->pre = head;
	m_size++;
}
void doublelink::Inserttail(int val) {
	Node* node = new Node(val);
	node->pre = head->pre;
	head->pre->next = node;
	node->next = head;
	head->pre = node;
	m_size++;
}
void doublelink::show() {
	if (!head)throw"Link is empty";
	Node* p = head->next;
	while (p != head) {
		std::cout << p->data << " ";
		p = p->next;
	}
	std::cout << std::endl;
}
bool doublelink::Find(int val) {
	if (!head)throw"Link is empty";
	Node* p = head->next;
	while (p != head) {
		if (p->data == val) {
			return true;
		}
		p = p->next;
	}
	return false;

}
void doublelink::erase(int val) {
	if (!head)throw"Link is empty";
	Node* p = head->next;
	while (p != head) {
		if (p->data == val) {
			p->pre->next = p->next;
			p->next->pre = p->pre;
			delete p;
			m_size--;
			return;
		}
		p = p->next;
	}
	throw"Not find tthe value";
}
int doublelink::getsize() {
	return m_size;
}