#ifndef _SPARSE_GRAPH_H_
#define _SPARSE_GRAPH_H_

#include <vector>
#include <cassert>

class SparseGraph {
public:
    SparseGraph(int n, bool directed) {
        _node_nums = n;
        _directed = directed;

        for (int i = 0; i < _node_nums; i++) {
            _edges.push_back(std::vector<int>());
        }
    }
    ~SparseGraph() {}

    void add_edge(int v, int w) {
        assert(v >= 0 && v < _node_nums);
        assert(w >= 0 && w < _node_nums);
        if (v == w) {
            return;
        }
        _edge_nums++;
        _edges[v].push_back(w);
        if (!_directed) {
            _edges[w].push_back(v);
        }
    }

    void show() const {
        for (int i = 0; i < _node_nums; i++) {
            std::cout << i << " : ";
            for (auto v : _edges[i]) {
                std::cout << v << " ";
            }
            std::cout << std::endl;
        }
    }

    int V() const {
        return _node_nums;
    }
public:
    class Iterator {
    public:
        Iterator(SparseGraph& sparse_graph, int v)
            : _sparse_graph(sparse_graph),
              _v(v) {}

        int begin() {
            _index = -1;
            return next();
        }

        int next() {
            _index++;
            if (_index >= _sparse_graph._edges[_v].size()) {
                return -1;
            }
            return _sparse_graph._edges[_v][_index];
        }

        bool end() {
            return _index >= _sparse_graph._edges[_v].size();
        }

    protected:
        SparseGraph& _sparse_graph;
        int _v;
        int _index = -1;
    };

protected:
    std::vector<std::vector<int>> _edges;
    int _node_nums = 0;
    int _edge_nums = 0;
    bool _directed = false;
};
#endif

