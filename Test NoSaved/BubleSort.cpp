#include"BubleSort.h"

void BubleSort(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		bool flag = false;
		for (int j = 0; j < size - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp;
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				flag = true;
			}
		}
		if (!flag) {
			break;
		}
	}


}
