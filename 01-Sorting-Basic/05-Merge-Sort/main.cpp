#include <iostream>
#include <string.h>
#include "sort_test_helper.h"
// 合并[l, mid], [mid+1, r]
void __merge(int arr[], int l, int mid, int r) {
    int aux[r - l + 1];
    memcpy(&aux, &arr[l], (r - l + 1) * sizeof(int));
    int i = l, j = mid + 1;
    for (int k = l; k <= r; k++) {
        if (i > mid) {
            arr[k] = aux[j - l];
            j++;
        }
        else if (j > r) {
            arr[k] = aux[i - l];
            i++;
        } else if (aux[i - l] > aux[j - l]) {
            arr[k] = aux[j - l];
            j++;
        }
        else {
            arr[k] = aux[i - l];
            i++;
        }
    }
}

// 归并[l, r] 数组元素
void __merge_sort(int arr[], int l, int r) {
    if (l >= r) {
        return;
    }

    int mid = l + (r - l) / 2;
    __merge_sort(arr, l, mid);
    __merge_sort(arr, mid + 1, r);
    __merge(arr, l, mid, r);
}

void merge_sort(int arr[], int n) {
    __merge_sort(arr, 0, n - 1);
}

void insertion_sort_opt(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int val = arr[i];
        // j 代表当前作比较的元素位置
        int j;
        for (j = i ; j >= 0 && arr[j - 1] > val; j--) {
            arr[j] = arr[j - 1];
        }
        arr[j] = val;
    }
}

int main() {
    int size = 100000;
    int* arr1 = generate_random_array(size, 0, 100000);
    int* arr2 = copy_int_array(arr1, size);
    test_sort("merge sort", merge_sort, arr1, size);
    test_sort("insert sort", insertion_sort_opt, arr2, size);
    delete [] arr1;
    delete [] arr2;
    return 0;
}

