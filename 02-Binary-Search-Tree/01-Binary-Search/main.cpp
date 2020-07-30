#include <iostream> 
#include <cassert>
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
    int arr[] = {0, 0, 0, 0, 0};
    std::cout << lower_bound(arr, 5, 3) << std::endl;
    return 0;
}
