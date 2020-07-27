#include <algorithm>

template<typename Item>
class MaxHeap {
public:
    MaxHeap(int capacity) {
        _data = new Item[capacity + 1];
        _count = 0;
        _capacity = capacity;
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

private:    
    Item* _data;
    int _count;
    int _capacity = 0;
};

