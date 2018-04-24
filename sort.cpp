#include <iostream>
#include<cstdlib>
#include<ctime>
#include <cmath>

using namespace std;

int arr[1000];

// 插入排序
void insertionSort(int *arr, int n) {
    for (int i = 0; i < n; ++i) {
    	for (int j = i; j > 0; --j) {
    		if (arr[j] < arr[j - 1]) {
    			swap(arr[j], arr[j - 1]);
    		}
    	}
    }
}

// 归并排序
void _merge(int *arr, int left, int mid, int right) {
	int temp[right - left + 1];

	for (int i = left; i <= right; ++i) { // 复制一遍子数组
        temp[i - left] = arr[i];
	}
    
    int l_current = left;
    int r_current = mid + 1;

    for (int i = left; i <= right; ++i) {
    	if (l_current > mid) {
    		arr[i] = temp[r_current - left];
    		++r_current;
    	}
    	else if (r_current > right) {
    		arr[i] = temp[l_current - left];
    		++l_current;
    	}
    	else if (temp[l_current - left] < temp[r_current - left]) {
    		arr[i] = temp[l_current - left];
    		++l_current;
    	}
    	else {
    		arr[i] = temp[r_current - left];
    		++r_current;
    	}
    }
}

void _mergeSort(int *arr, int left, int right) {
    int mid = left + (right - left) / 2;

	if (right == left) {
		return ;
	}

	_mergeSort(arr, left, mid);
	_mergeSort(arr, mid + 1, right);

	_merge(arr, left, mid, right);

}

void mergeSort(int *arr, int n) {
    _mergeSort(arr, 0, n - 1);
}

// 快速排序
int _partition(int *arr, int left, int right) {
    int e = arr[left];
    int div = left;

    for (int i = left + 1; i <= right; ++i) {
    	if (arr[i] < e) {
    		swap(arr[div + 1], arr[i]);
    		++div;
    	}
    }

    swap(arr[left], arr[div]);

    return div;
}
void _quickSort(int *arr, int left, int right) {
	if (left >= right) {
		return ;
	}

	int div = _partition(arr, left, right); // div是已经归位的那个元素的位置
	_quickSort(arr, left, div - 1);
	_quickSort(arr, div + 1, right);
}

void quickSort(int *arr, int n) {
	_quickSort(arr, 0, n - 1);
}



int main(int argc, char const *argv[]) {
    srand((unsigned) time(NULL));

	for (int i = 0; i < 1000; ++i) {
	    arr[i] = rand() % 1000;
	}

	// insertionSort(arr, 1000);
    
	// mergeSort(arr, 1000);

	quickSort(arr, 1000);

	for (int i = 0; i < 1000; ++i) {
		cout << arr[i] << " ";
	}
    
	cout << endl;

	return 0;
}

