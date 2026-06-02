#pragma once
#include<vector>

enum State {
	Unusing,
	Using,
	Del
};


struct Bucket {
	Bucket(int data = 0,State state=Unusing) {
		m_data = data;
		m_state = state;
	}
	int m_data;
	State m_state;
};

class ArrayHashtable {
private:
	std::vector<Bucket>m_v;
	int m_tablesize;
	int m_usingBucketNums = 0;
	static const int primesize = 10;
	inline static int m_primes[primesize]= { 3,7,23,47,97,251,443,911,1471,42773 };
	int primeIndex = 0;
	double m_loadfactor;
	void expand();
public:
	ArrayHashtable(int tablesize = m_primes[0], double loadfactor = 0.75);
	~ArrayHashtable(){}
	void push(int val);
	bool find(int  val);
	bool erase(int val);
};

