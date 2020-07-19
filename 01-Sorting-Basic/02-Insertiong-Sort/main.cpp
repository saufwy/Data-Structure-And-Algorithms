#include <iostream>
#include <algorithm>

#include "sort_test_helper.h"

template<typename T>
void insertionSort(T arr[], int n){
	for( int i = 1 ; i < n ; i ++ ) {
        for( int j = i ; j > 0 && arr[j] < arr[j-1] ; j -- )
            std::swap( arr[j] , arr[j-1] );

    }

    return;
}

void insertion_sort(int arr[], int n) {
    int tmp;
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--) {
            tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;
        }
    }
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

void selection_sort(int arr[], int n){
    int tmp;
    for(int i = 0 ; i < n ; i ++){
        // 寻找[i, n)区间里的最小值
        int min_index = i;
        for( int j = i + 1 ; j < n ; j ++ )
            if( arr[j] < arr[min_index] )
                min_index = j;
        // std::swap( arr[i] , arr[min_index] );
        tmp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = tmp;
    }
}

void test_insertion_sort() {
    int size = 100000;
    int* arr1 = generate_random_array(size, 0, 1000000);
    int* arr2 = copy_int_array(arr1, size);
    int* arr3 = copy_int_array(arr1, size);
    test_sort("insertion sort", insertionSort, arr2, size);
    test_sort("insertion sort", insertion_sort, arr1, size);
    test_sort("insertion sort", insertion_sort_opt, arr3, size);
    delete [] arr1;
    delete [] arr2;
    delete [] arr3;
}

void test_compare_insertion_and_selection() {
    int size = 100000;
    int* arr1 = generate_random_array(size, 0, 10);
    int* arr2 = copy_int_array(arr1, size);
    test_sort("selection sort", selection_sort, arr1, size);
    test_sort("insertion sort", insertion_sort, arr2, size);
    delete [] arr1;
    delete [] arr2;
}

void test_compare_insertion_and_selection_nearly_sorted() {
    int size = 100000;
    int* arr1 = generate_nearly_sorted_array(size, 10);
    int* arr2 = copy_int_array(arr1, size);
    test_sort("selection sort", selection_sort, arr1, size);
    test_sort("insertion sort", insertion_sort, arr2, size);
    delete [] arr1;
    delete [] arr2;
}

int main() {
    // test_insertion_sort();
    // test_compare_insertion_and_selection();
    test_compare_insertion_and_selection_nearly_sorted();
    return 0;
}

