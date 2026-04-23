#pragma once



class MaxHeap {
public:
	MaxHeap(int size = 20);
		
	~MaxHeap();
	void pop();
	void push(int val);
    int top()const;
    bool empty()const;
	
private:
	int* p;
	int m_size;
	int m_capacity;
	void siftdown(int index);
	void siftup(int index);
	void expand(int newcapacity);
	MaxHeap(const MaxHeap& h) = delete;
	MaxHeap& operator=(const MaxHeap& h) = delete;
};
