#include"HeapSort.h"
#include<algorithm>


void siftdown(int arr[], int index, int size) {
	int val = arr[index];
	while (index < size / 2) {
		int child = 2 * index + 1;
		if (child + 1 < size && arr[child] < arr[child + 1]) {
			child++;
		}
		if (val < arr[child]) {
			arr[index] = arr[child];
			index = child;
		}
		else {
			break;
		}
	}
	arr[index] = val;
}

void HeapSort(int arr[], int size) {
	int index = size / 2 - 1;
	while (index >= 0) {
		siftdown(arr, index, size);
		index--;
	}
	while (size > 1) {
		std::swap(arr[0], arr[size - 1]);
		size--;
		siftdown(arr, 0, size);
	}


}