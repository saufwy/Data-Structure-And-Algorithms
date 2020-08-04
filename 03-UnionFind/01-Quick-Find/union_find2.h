#ifndef _UNION_FIND2_H_
#define _UNION_FIND2_H_

#include <cassert>

class UnionFind2 {
public:
    UnionFind2(int n) {
        _count = n;
        _parent = new int[_count];
        for (int i = 0; i < _count; i++) {
            _parent[i] = i;
        }
    }
    ~UnionFind2() {
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
        _parent[qroot] = proot;
    }

private:
    int* _parent = nullptr;
    int _count;
};

#endif

