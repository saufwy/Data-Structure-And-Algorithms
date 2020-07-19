#ifndef _SORT_TEST_HELPER_H_
#define _SORT_TEST_HELPER_H_

#include <iostream>
#include <ctime>
#include <cassert>
#include <string>
#include <chrono>
#include <algorithm>

// 生成元素取值范围为[range_l, range_r] 大小为n 的随机数组
int* generate_random_array(int n, int range_l, int range_r) {
    assert(range_r > range_l);

    int* arr = new int[n];
    srand(time(nullptr));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % (range_r - range_l + 1) + range_l;
    }
    return arr;
}

int* generate_nearly_sorted_array(int n, int swap_times) {
    int* arr = new int[n];
    for (int i = 0; i < n ; i++) {
        arr[i] = i;
    }
    srand(time(nullptr));
    for (int i = 0; i < swap_times; i++) {
        int posx = rand() % n;
        int posy = rand() % n;
        std::swap(arr[posx], arr[posy]);
    }
    return arr;
}

template<typename T>
bool is_sorted(T arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

template<typename T>
void test_sort(std::string sort_name, void(*sort)(T arr[], int n), T arr[], int n) {
    clock_t begin = clock();
    sort(arr, n);
    clock_t end = clock();
    assert(is_sorted(arr, n));
    std::cout << sort_name << " cost : " << (1.0 * (end - begin) / CLOCKS_PER_SEC) << " seconds" << std::endl;
}

template<typename T>
void print_array(T arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << std::endl;
    }
}

int *copy_int_array(int a[], int n){
    int *arr = new int[n];
    std::copy(a, a+n, arr);
    return arr;
}
#endif

