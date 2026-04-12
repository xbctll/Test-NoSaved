#pragma once
#include<iostream>


class doublelink {
private:
	struct Node {
		Node(int data =0)
			:data(data)
			,next(nullptr)
			,pre(nullptr)
		{}
		int data;
		Node* next;
		Node* pre;
	};
	doublelink(const doublelink& link) = delete;
	doublelink& operator=(const doublelink& link) = delete;
	Node* head;
	int m_size;
public:
	doublelink();
		
	~doublelink();
	void Inserthead(int val);
	void Inserttail(int val);
	void show();
	bool Find(int val);
	void erase(int val);
	int getsize();
};
