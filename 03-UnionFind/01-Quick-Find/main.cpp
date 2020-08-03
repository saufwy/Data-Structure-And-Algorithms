#include <iostream>
#include <cassert>

class UnionFind {
public:
    UnionFind(int n) {
        _count = n;
        _id = new int[_count];
        for (int i = 0; i < _count; i++) {
            _id[i] = i;
        }
    }
    ~UnionFind() {
        _count = 0;
        delete [] _id;
    }

    int find(int p) {
        assert(p >=0 && p < _count); 
    }

private:
    int* _id = nullptr;
    int _count;
};
int main() {
    return 0;
}
