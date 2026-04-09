#pragma once
#include<iostream>


struct node {
	int data;
	node* next;
	node(int val = 0) :data(val), next(nullptr) {
	}
};

class Link {
public:
	Link();
	void inserttail(int val);
	void show();
	void inserthead(int val);
	~Link();
	bool isexist(int val);

private:
	node* head;
	friend void Reserve(Link& link);
	friend void MergeLink(Link& link1, Link& link2);
	friend void DeleteK(Link& link1, int k);
	friend void isexsitcircle(Link& link1);
};
