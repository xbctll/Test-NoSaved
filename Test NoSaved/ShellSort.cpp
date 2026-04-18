#include"ShellSort.h"


void ShellSort(int arr[], int size) {
	int gap = size / 2;
	while (gap > 0) {
		for (int i = gap; i < size; i++) {
			int val = arr[i];
			int j = i - gap;
			for (; j >= 0; j -= gap) {
				if (arr[j] > val) {
					arr[j + gap] = arr[j];
				}
				else {
					break;
				}
			}
			arr[j + gap] = val;
		}
		gap /= 2;
	}

}