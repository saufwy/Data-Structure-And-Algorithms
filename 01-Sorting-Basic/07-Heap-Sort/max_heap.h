#include <algorithm>

template<typename Item>
class MaxHeap {
public:
    MaxHeap(int capacity) {
        _data = new Item[capacity + 1];
        _count = 0;
        _capacity = capacity;
    }

    MaxHeap(Item arr[], int n) {
        _data = new Item[n + 1];
        _capacity = n;
        _count = n;
        for (int i = 0; i < n; i++) {
            _data[i + 1] = arr[i];
        }
        for (int i = _count / 2; i >= 1; i--) {
            shift_down(i);
        }
    }

    int size() {
        return _count;
    }

    bool is_empty() {
        return _count == 0;
    }

    void insert(Item item) {
        if (_count + 1 > _capacity) {
            return;
        }
       _data[++_count] = item; 
       shift_up(_count);
    }

    bool extract_max(Item& item) {
        if (_count < 1) {
            return false;
        }
        item = _data[1];
        _data[1] = _data[_count--];
        if (_count > 1) {
            shift_down(1);
        }
    }

    void print() const {
        for (int i = 1; i <= _count; i++) {
            std::cout << _data[i] << " ";
        }
        std::cout << std::endl;
    }

private:
    void shift_up(int k) {
        while (k > 1 && _data[k/2] < _data[k]) {
            std::swap(_data[k/2], _data[k]);
            k /= 2;
        }
    }

    void shift_down(int k) {
        do {
            int largest = k;
            int l = 2 * k;
            int r = 2 * k + 1;
            if (l <= _count && _data[l] > _data[largest]) {
                largest = l;
            }

            if (r <= _count && _data[r] > _data[largest]) {
                largest = r;
            }
            if (largest != k) {
                std::swap(_data[largest], _data[k]);
                k = largest;
            } else {
                break;
            }
        } while (true);
    }

private:    
    Item* _data;
    int _count;
    int _capacity = 0;
};

