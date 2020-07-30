#ifndef _BINARY_SEARCH_H_
#define _BINARY_SEARCH_H_

int binary_search(int arr[], int n, int target) {
    // [l, r] 
    int l = 0;
    int r = n - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (target < arr[mid]) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return -1;
}

int lower_bound(int arr[], int n, int target) {
    int l = 0;
    int count = n;
    while (count > 0) {
        int step = count / 2;
        int mid = l + step;
        if (arr[mid] < target) {
            l = mid + 1; 
            count -= (step + 1);
        } else {
            count = step;
        }

    }
    return l;
}
#endif

