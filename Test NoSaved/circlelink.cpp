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
void circlelink::erase(int val) {
	if (head->next == head)return;
	node* p = head->next;
	node* q = head;
	while (p != head) {
		if (p->data == val) {
			if (p == tail) {
				tail = q;
			}
			q->next = p->next;
			delete p;
			return;
		}else{
			p = p->next;
			q = q->next;
		}
		
	}
}
void circlelink::Josephus(int n, int m) {
	for (int i = 0; i < n; i++) {
		InsertTail(i + 1);
	}
	node* p = head->next;
	node* q = head;
	while (head->next != head) {
		for (int i = 0; i < m - 1; i++) {
			q = p;
			p = p->next;
			if (p == head) {
				q = p;
				p = p->next;
			}
		}
		std::cout << p->data << " ";
		if (p == tail) {
			tail = q;
		}
		q->next = p->next;
		node* cur = p;
		p = p->next;
		delete cur;
		if (p == head) {
			q = p;
			p = p->next;
		}
	}
}