#ifndef _SORT_TEST_HELPER_H_
#define _SORT_TEST_HELPER_H_

#include <iostream>
#include <ctime>
#include <cassert>

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
#endif

