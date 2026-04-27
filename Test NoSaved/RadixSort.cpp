#include"RadixSort.h"
#include<vector>

void RadixSort(int arr[], int size) {
	std::vector<std::vector<int>>v(10);
	int max = arr[0];
	for (int i = 1; i < size; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	int length = 0;
	while (max > 0) {
		max /= 10;
		length++;
	}
	int mod = 10;
	int dev = 1;
	for (int i = 0; i < length; i++, mod *= 10, dev *= 10) {
		for (int j = 0; j < size; j++) {
			int index = arr[j] % mod / dev;
			v[index].push_back(arr[j]);
		}
		int k = 0;
		for (int j = 0; j < 10; j++) {
			for (const auto& val : v[j]) {
				arr[k++] = val;
			}
			v[j].clear();
		}


	}
}