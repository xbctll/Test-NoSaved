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
	void erase(int val);
	void InsertHead(int val);
	~circlelink();
	void Josephus(int n, int m);
private:
	node* head;
	node* tail;
};