#include <iostream> 
#include <algorithm>
#include "sort_test_helper.h"

// 返回p 使得 arr[l, p - 1] < arr[p] < arr[p + 1, r]
int  __partition(int arr[], int l, int r) {
    int v = arr[l];
    // i 当前要访问的元素
    // arr[l+1, j] < v < arr[j+1, i)
    int j = l;
    for (int i = l + 1; i <= r; i++) {
        if (arr[i] < v) {
            std::swap(arr[j+1], arr[i]);
            j++;
        }
    }
    std::swap(arr[j], arr[l]);
    return j;
}

// 排序 [l, r] 
void __quick_sort(int arr[], int l ,int r) {
    if (l >= r)
        return;

    int p = __partition(arr, l, r);
    __quick_sort(arr, l, p - 1);
    __quick_sort(arr, p + 1, r);
}

void quick_sort(int arr[], int n) {
    __quick_sort(arr, 0, n - 1);
}

int main() {
    int size = 100000;
    int* arr1 = generate_random_array(size, 0, 100);
    // 第一次很快排好序
    test_sort("quick sort", quick_sort, arr1, size);
    // 第二次快排将为O(n^2)
    test_sort("quick sort", quick_sort, arr1, size);
    delete [] arr1;
    return 0;
}

