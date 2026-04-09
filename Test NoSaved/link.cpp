#include<iostream>
#include"link.h"



Link::Link() {
	head = new node();
}

void Link::inserttail(int val) {
	node* q = head;
	while (q->next != nullptr) {
		q = q->next;
	}
	q->next = new node(val);
}

void Link::show() {
	if (head->next == nullptr) {
		return;
	}
	node* p = head->next;
	while (p != nullptr) {
		std::cout << p->data << " ";
		p = p->next;
	}
	std::cout << std::endl;
}

void Link::inserthead(int val) {
	node* p = new node(val);
	p->next = head->next;
	head->next = p;
}

Link::~Link() {
	node* p = head->next;
	node* q = head;
	while (p != nullptr) {
		delete q;
		q = p;
		p = p->next;
	}
	delete q;
}


bool Link::isexist(int val) {
	node* p = head->next;
	while (p != nullptr) {
		if (p->data == val) {
			return true;
		}
		p = p->next;
     }
	return false;


}








