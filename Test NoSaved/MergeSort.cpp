#include"MergeSort.h"
#include<algorithm>

static void Merge(int arr[], int begin, int mid, int end, int* p) {
	int i = begin;
	int j = mid + 1;
	int k = begin;
	while (i <= mid && j <= end) {
		if (arr[i] <= arr[j]) {
			p[k++] = arr[i++];
		}
		else {
			p[k++] = arr[j++];
		}
	}
	while (i <= mid) {
		p[k++] = arr[i++];
	}
	while (j <= end) {
		p[k++] = arr[j++];
	}
	std::copy(p+begin, p+end+1 , arr + begin);
}


static void MergeSortRecursive(int arr[], int begin, int end, int* p) {
	if (begin == end) {
		return;
	}
	int mid = begin + (end - begin) / 2;
	MergeSortRecursive(arr, begin, mid, p);
	MergeSortRecursive(arr, mid + 1, end, p);
	Merge(arr, begin, mid, end, p);
}


void MergeSort(int arr[], int begin, int end) {
	if (begin > end) {
		throw"Your Array has a invalid range";
	}
	int* p = new int[end - begin + 1];
	MergeSortRecursive(arr, begin, end, p);
	delete[]p;
}


