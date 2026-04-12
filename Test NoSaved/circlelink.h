#pragma once
#include<iostream>
struct node {
	int data;
	node* next;
	node(int val = 0) :data(val), next(nullptr) {}
	
};


class circlelink {
public:
	circlelink();
	void InsertTail(int val);
	void show();
	void InsertHead(int val);
	~circlelink();
private:
	node* head;
	node* tail;
};