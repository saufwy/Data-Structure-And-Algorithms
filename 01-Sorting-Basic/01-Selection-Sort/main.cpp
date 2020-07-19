#include <iostream>
#include <algorithm>
#include <chrono>

#include "sort_test_helper.h"

void selection_sort(int arr[], int n){
    for(int i = 0 ; i < n ; i ++){
        // 寻找[i, n)区间里的最小值
        int min_index = i;
        for( int j = i + 1 ; j < n ; j ++ )
            if( arr[j] < arr[min_index] )
                min_index = j;
        std::swap( arr[i] , arr[min_index] );
    }
}
int main() {
    int size = 10000;
    int* arr = generate_random_array(size, 0, 10000);
    test_sort("selection sort", selection_sort, arr, size);
    delete [] arr;
    return 0;
}

