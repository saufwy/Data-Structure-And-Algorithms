#include <iostream> 
#include <cassert>
#include <algorithm>
#include "binary_search.h"

void test_binary_search() {
    int size = 1000;
    int arr[size];
    for (int i = 0; i < size; i++) {
        arr[i] = i + 100;
    }
    for (int i = 0; i < size; i++) {
        assert(i == binary_search(arr, size, arr[i]));
    }
}

int main() {
    int size = 5;
    int arr[] = {2, 4, 5, 6, 9};
    std::cout << *std::lower_bound(arr, arr + size, 4) << std::endl;
    std::cout << *std::upper_bound(arr, arr + size, 4) << std::endl;

    std::cout << "index=" << my_lower_bound(arr, size, 4) << std::endl;
    std::cout << "index=" << my_upper_bound(arr, size, 4) << std::endl;
    return 0;
}
