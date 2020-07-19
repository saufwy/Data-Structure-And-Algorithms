#ifndef _SORT_TEST_HELPER_H_
#define _SORT_TEST_HELPER_H_

#include <iostream>
#include <ctime>
#include <cassert>
#include <string>

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

bool is_sorted() {
    return true;
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
	auto start = std::chrono::system_clock::now();
    sort(arr, n);
	auto end = std::chrono::system_clock::now();
    assert(is_sorted(arr, n));
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	std::cout << sort_name << " cost : " << duration.count() << " ms" << std::endl;
}


#endif

