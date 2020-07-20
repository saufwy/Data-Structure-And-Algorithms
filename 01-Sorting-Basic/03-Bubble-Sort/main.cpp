#include <iostream>
#include <algorithm>
#include "sort_test_helper.h"

void bubble_sort(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (arr[j] > arr[j+1]) {
                std::swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main() {
    int size = 10;
    int* arr = generate_random_array(size, 0, 10000);
    test_sort("bubble sort", bubble_sort, arr, size);
    print_array(arr, size);
    delete [] arr;
    return 0;
}

