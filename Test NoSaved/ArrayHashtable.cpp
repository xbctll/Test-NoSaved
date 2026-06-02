#include"ArrayHashtable.h"



void ArrayHashtable::expand() {
	if (primeIndex >= primesize) {
		throw"Hashmap is full!!";
	}
	m_tablesize = m_primes[++primeIndex];
	std::vector<Bucket>oldBucket;
	oldBucket = m_v;
	m_v.assign(m_tablesize, Bucket());
	m_usingBucketNums = 0;
	for (const auto& v : oldBucket) {
		if (v.m_state == Using) {
			push(v.m_data);
		}
	}
}


ArrayHashtable::ArrayHashtable(int tablesize, double loadfactor)
	:m_loadfactor(loadfactor)
{
	if (tablesize != m_primes[0]) {
		int i = 1;
		for (; i < primesize; i++) {
			if (m_primes[i] >= tablesize)break;
		}
		if (i != primesize) {
			tablesize = m_primes[i];
			primeIndex = i;
		}
		else {
			throw"Hashtable is too big!Please Re-enter";
		}
	}
	m_tablesize = tablesize;
	m_v.resize(tablesize);
}

void ArrayHashtable::push(int val) {
	if (static_cast<double>(m_usingBucketNums) / m_tablesize >= m_loadfactor) {
		expand();
	}
	int post = val % m_tablesize;
	do {
		if (m_v[post].m_state != Using) {
			m_v[post].m_data = val;
			m_v[post].m_state = Using;
			m_usingBucketNums++;
			return;
		}
		post = (post + 1) % m_tablesize;
	} while (post != val % m_tablesize);
	throw"Failed Push!";
}
bool ArrayHashtable::find(int  val) {
	int post = val % m_tablesize;
	do {
		if (m_v[post].m_state == Unusing)return false;
		if (m_v[post].m_data == val && m_v[post].m_state != Del)return true;
		post = (post + 1) % m_tablesize;
	} while (post != val % m_tablesize);
	return false;
}
bool ArrayHashtable::erase(int val) {
	if (m_usingBucketNums == 0)return false;
	int pos = val % m_tablesize;
	bool flag = false;
	do {
		if (m_v[pos].m_state == Unusing)break;
		if (m_v[pos].m_data == val && m_v[pos].m_state != Del) {
			m_v[pos].m_state = Del;
			flag = true;
			m_usingBucketNums--;
		}
		pos = (pos + 1) % m_tablesize;

	} while (pos != val % m_tablesize);
	return flag;
}