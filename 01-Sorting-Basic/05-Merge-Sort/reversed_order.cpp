#include <iostream>
#include <cstring>
#include "sort_test_helper.h"

// 合并[l, mid], [mid+1, r]
int g_num = 0;
void __merge(int arr[], int l, int mid, int r) {
    int aux[r - l + 1];
    int li = l;
    int ri = mid + 1;
    int k = 0;
    for (k = 0; li <= mid && ri <= r; k++) {
        if (arr[li] <= arr[ri]) {
            aux[k] = arr[li++];
        } else {
            aux[k] = arr[ri++];
            g_num += (mid - li + 1);
        }
    }
    if (li <= mid) {
        while (li <= mid) {
            aux[k++] = arr[li++];
        }
    }
    if (ri <= r) {
        while (ri <= r) {
            aux[k++] = arr[ri++];
        }
    }
    for (int i = l; i <= r; i++) {
        arr[i] = aux[i - l];
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

int get_degree(int arr[], int size) {
    int num = 0;
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                num++;
            }
        }
    }
    return num;
}

int main() {
    int size = 10;
    int* arr = generate_random_array(size, 0, 100000);
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << std::endl;
    }
    int num = get_degree(arr, size);
    // test_sort("merge sort", merge_sort, arr, size);
    merge_sort(arr, size);
    std::cout << "affert sort" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << std::endl;
    }
    delete [] arr;
    std::cout << "merge degree " << g_num << "   " << num << std::endl;
    return 0;
}

