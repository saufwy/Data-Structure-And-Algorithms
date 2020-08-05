#ifndef _UNION_FIND5_H_
#define _UNION_FIND5_H_

#include <cassert>

class UnionFind5 {
public:
    UnionFind5(int n) {
        _count = n;
        _parent = new int[_count];
        _rank = new int[_count];
        for (int i = 0; i < _count; i++) {
            _parent[i] = i;
            _rank[i] = 1;
        }
    }
    ~UnionFind5() {
        _count = 0;
        delete [] _parent;
        delete [] _rank;
    }

    int find(int p) {
        assert(p >=0 && p < _count); 
        // path compress
        while (p != _parent[p]) {
            _parent[p] = _parent[_parent[p]];
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
        if (_rank[qroot] < _rank[proot]) {
            _parent[qroot] = proot;
        } else if (_rank[qroot] > _rank[proot]) {
            _parent[proot] = qroot;
        } else {
            _parent[proot] = qroot;
            _rank[qroot]++;
        }
    }

private:
    int* _parent = nullptr;
    int* _rank = nullptr;
    int _count = 0;
};

#endif

