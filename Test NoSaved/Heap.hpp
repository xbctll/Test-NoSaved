#pragma once
#include<algorithm>
#include<vector>
#include<stdexcept>

template <class T,class Compare =std::less<T>>
class Heap {
private:
	std::vector<T> v;
	Compare com;
	void siftdown(int index) {
		T val = v[index];
		while(index<v.size()/2){
			int child = 2 * index + 1;
			if (child+1<v.size()&&com(v[child], v[child + 1])) {
				child = child + 1;
			}
			if (com(val, v[child])) {
				v[index] = v[child];
			}
			else {
				break;
			}
			index = child;
		}
		v[index] = val;
	}
	void siftup(int index) {
		T val = v[index];
		while (index > 0) {
			int parent = (index - 1) / 2;
			if (com(v[parent], val)) {
				v[index] = v[parent];
				index = parent;
			}
			else {
				break;
			}
		}
		v[index] = val;
	}
public:
	Heap(Compare c=Compare())
		:com(c)
	{}
	bool empty()const {
		return v.size() == 0;
	}
	int size()const {
		return v.size();
	}
	const T& top()const {
		if (v.size() == 0) {
			throw std::runtime_error("Heap is empty!");
		}
		return v[0];
	}
	void pop() {
		if (v.size() == 0) {
			throw std::runtime_error("Heap is empty!");
		}
		if (v.size() == 1) {
			v.pop_back();
			return;
		}
		v[0] = v[v.size() - 1];
		v.pop_back();
		siftdown(0);
	}
	void push(T val) {
		v.push_back(val);
		siftup(v.size() - 1);
	}


};