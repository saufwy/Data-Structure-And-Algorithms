#include <iostream>
#include <cstdlib>
#include <ctime>

#include "sort_test_helper.h"
#include "max_heap.h"

#define left(i) (2 * i + 1)
#define right(i) (2 * i + 2)

void max_heapify(int arr[], int size, int i) {
    int l = left(i);
    int r = right(i);
    int largest = i;
    if (l < size && arr[l] > arr[largest]) {
        largest = l;
    }
    if (r < size && arr[r] > arr[largest]) {
        largest = r;
    }
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        max_heapify(arr, size, largest);
    }
}

// shift down
void max_heapify_non_recursion(int arr[], int size, int i) {
    do { 
        int l = left(i);
        int r = right(i);
        int largest = i;
        if (l < size && arr[l] > arr[largest]) {
            largest = l;
        }
        if (r < size && arr[r] > arr[largest]) {
            largest = r;
        }
        if (largest != i) {
            std::swap(arr[i], arr[largest]);
            i = largest;
        } else {
            break;
        }
    } while(true);
}

void build_max_heap(int arr[], int size) {
    for (int i = (size - 1) / 2; i >=0; i--) {
       // max_heapify(arr, size, i);
       max_heapify_non_recursion(arr, size, i);
    }
}

void heap_sort(int arr[], int size) {
    build_max_heap(arr, size);
    for (int i = size - 1 ; i >= 1; i--) {
        std::swap(arr[0], arr[i]);
        max_heapify(arr, i, 0); 
    }
}

int main() {
    int size = 1000000;
    int* arr = generate_random_array(size, 0, 1000000);
    test_sort("heap sort", heap_sort, arr, size);
    delete [] arr;

    size = 20;
    srand(time(nullptr));
    MaxHeap<int> max_heap(100);
    for (int i = 0; i < size; i++) {
        max_heap.insert(rand() % 100);
    }
    max_heap.print();
    std::cout << "extract item form max heap" << std::endl;
    for (int i = 0; i < size; i++) {
        int item;
        max_heap.extract_max(item);
        std::cout << item << std::endl;
    }
    return 0;
}

