#include<iostream>
#include"link.h"
#include"FastSort.h"



int main() {
	int arr[] = { 1,3,88,6,81111,10,99,44,333,456,112,999 };
	FastSort(arr,0,11);
	for (const auto& v : arr) {
		std::cout << v << " ";
	}
	std::cout << std::endl;
	return 0;

}










void Reserve(Link& link) {
	if (link.head->next == nullptr) {
		return;
	}
	node* q = link.head->next;
	node* p = q->next;
	link.head->next = nullptr;
	while (p != nullptr) {
		q->next = link.head->next;
		link.head->next = q;
		q = p;
		p = p->next;
	}
	q->next = link.head->next;
	link.head->next = q;
}

//void DeleteK(Link& link1, int k) {
//	if (link1.head->next == nullptr) {
//		throw"Link is empty";
//	}
//	node* p = link1.head;
//	node* q = link1.head;
//	for (int i = 0; i < k+1; i++) {
//		p = p->next;
//	}
//	while(p != nullptr){
//		p = p->next;
//		q = q->next;
//	}
//	node* temp = q->next;
//	if (temp != nullptr) {
//		q->next = temp->next;
//		delete temp;
//	}
//}

void isexsitcircle(Link& link1) {
	node* fast = link1.head;
	node* slow = link1.head;
	while (fast != nullptr&&fast->next!=nullptr) {
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow) {
			std::cout << "Exist circle" << std::endl;
			slow = link1.head;
			while (slow != fast) {
				fast = fast->next;
				slow = slow->next;
			}
			std::cout << "Circle entry is " << slow->data << std::endl;
			return;
		}
	}
	std::cout << "No circle" << std::endl;
}

void MergeLink(Link& link1, Link& link2) {
	if (link1.head->next == nullptr || link2.head->next == nullptr) {
		return;
	}
	node* p = link1.head->next;
	node* last = link1.head;
	node* q = link2.head->next;
	link2.head->next = nullptr;
	while (p != nullptr && q != nullptr) {
		if (p->data < q->data) {
			last->next = p;
			p = p->next;
			last = last->next;
		}
		else {
			last->next = q;
			q = q->next;
			last = last->next;
		}
	}
	if (p == nullptr) {
		last->next = q;
	}
	else {
		last->next = p;
	}

}










