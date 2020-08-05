#ifndef _UNION_FIND3_H_
#define _UNION_FIND3_H_

#include <cassert>

class UnionFind3 {
public:
    UnionFind3(int n) {
        _count = n;
        _parent = new int[_count];
        _sz = new int[_count];
        for (int i = 0; i < _count; i++) {
            _parent[i] = i;
            _sz[i] = 1;
        }
    }
    ~UnionFind3() {
        _count = 0;
        delete [] _parent;
    }

    int find(int p) {
        assert(p >=0 && p < _count); 
        while (p != _parent[p]) {
            p = _parent[p];
        }
        return p;
    }

    bool is_connected(int p, int q) {
        return find(p) == find(q);
    }

    void union_elems(int p, int q) {
        assert(p >=0 && p < _count); 
        assert(q >=0 && q < _count); 
        int proot = find(p);
        int qroot = find(q);
        if (proot == qroot) {
            return;
        }
        if (_sz[qroot] < _sz[proot]) {
            _parent[qroot] = proot;
            _sz[proot] += _sz[qroot];
        } else {
            _parent[proot] = qroot;
            _sz[qroot] += _sz[proot];
        }
    }

private:
    int* _parent = nullptr;
    int* _sz = nullptr;
    int _count;
};

#endif

