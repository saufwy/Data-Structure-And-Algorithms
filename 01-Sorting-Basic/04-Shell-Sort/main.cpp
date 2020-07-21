#include <iostream>
#include "sort_test_helper.h"

void insert(int arr[], int i, int gap) {
    int val = arr[i];
    int j;
    for (j = i - gap; j >= 0 && arr[j] > val; j -= gap) {
        arr[j + gap] = arr[j];
    }
    arr[j + gap] = val;
}

void shell_sort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            insert(arr, i, gap);
        }
    }
}

int main() {
    int size = 100000;
    int* arr = generate_random_array(size, 0, 100000);
    print_array(arr, size);
    test_sort("shell sort", shell_sort, arr, size);
    print_array(arr, size);
    return 0;
}

