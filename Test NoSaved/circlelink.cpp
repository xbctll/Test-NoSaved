#include"circlelink.h"


circlelink::circlelink() {
	head = new node();
	tail = head;
	head->next = head;
}


void circlelink::InsertTail(int val) {
	tail->next = new node(val);
	tail = tail->next;
	tail->next = head;
}


void circlelink::show() {
	node* p = head->next;
	while (p != head) {
		std::cout << p->data << " ";
		p = p->next;
	}
}

void circlelink::InsertHead(int val) {
	if (head->next == head) {
		InsertTail(val);
		return;
	}
	node* p = new node(val);
	p->next = head->next;
	head->next = p;
}


circlelink::~circlelink() {
	node* p = head->next;
	node* q = head->next;
	while (p != head) {
		p = p->next;
		delete q;
		q = p;
	}
	delete head;
}