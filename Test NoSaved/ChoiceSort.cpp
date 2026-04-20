#include"ChoiceSort.h"

void ChoiceSort(int arr[], int size) {
	for (int i = 0; i < size - 1; i++) {
		int val = i;
		for (int j = i + 1; j < size; j++) {
			if (arr[val] > arr[j]) {
				val = j;
			}
		}
		int temp = arr[val];
		arr[val] = arr[i];
		arr[i] = temp;
	}


}