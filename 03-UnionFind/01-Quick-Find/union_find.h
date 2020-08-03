#ifndef _UNION_FIND_H_
#define _UNION_FIND_H_

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
        return _id[p];
    }

    bool is_connected(int p, int q) {
        return find(p) == find(q);
    }

    void union_elems(int p, int q) {
        assert(p >=0 && p < _count); 
        assert(q >=0 && q < _count); 
        int pid = _id[p];
        int qid = _id[q];
        if (pid == qid) {
            return;
        }
        for (int i = 0; i < _count; i++) {
            if (_id[i] == pid) {
                _id[i] = qid;
            }
        }
    }

private:
    int* _id = nullptr;
    int _count;
};

#endif

