#include <iostream> 
#include <cassert>
#include "binary_search.h"

int main() {
    int size = 1000;
    int arr[size];
    for (int i = 0; i < size; i++) {
        arr[i] = i + 100;
    }
    for (int i = 0; i < size; i++) {
        assert(i == binary_search(arr, size, arr[i]));
    }
    return 0;
}
