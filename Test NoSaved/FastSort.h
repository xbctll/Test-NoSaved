#pragma once



int Mid(int L, int R, int M) {
	if (R <= M) {
		if (L <= R) {
			return R;
		}
		else if (L > R && L <= M) {
			return L;
		}
		else {
			return M;
		}
	}
	else {
		if (L <= M) {
			return M;
		}
		else if (L > M && L <= R) {
			return L;
		}
		else {
			return R;
		}
	}
}

void FastSort(int arr[], int left, int right) {
	if (left >= right) {
		return;
	}
	int L = left;
	int R = right;
	int mid = (left + right) / 2;
	int val = Mid(arr[left], arr[right], arr[mid]);
	if (arr[right] == val) {
		int temp = arr[left];
		arr[left] = arr[right];
		arr[right] = temp;
	}
	else if (arr[mid] == val) {
		int temp = arr[left];
		arr[left] = arr[mid];
		arr[mid] = temp;
	}
	while (left < right) {
		while (left < right && arr[right] >= val) {
			right--;
		}
		if(left<right){
			arr[left] = arr[right];
			left++;
		}
		
		while (left < right && arr[left] <=val) {
			left++;
		}
		if (left < right) {
			arr[right] = arr[left];
			right--;
		}
	}
	arr[left] = val;
	FastSort(arr, L, left - 1);
	FastSort(arr, left + 1, R);
}