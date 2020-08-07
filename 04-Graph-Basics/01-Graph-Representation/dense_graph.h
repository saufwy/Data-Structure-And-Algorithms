#ifndef _DESEN_GRAPH_H_
#define _DESEN_GRAPH_H_

#include <vector>
#include <cassert>

class DesenGraph {
public:
    DesenGraph(int n, bool directed) {
        _node_nums = n;
        _directed = directed;
        for (int i = 0; i < _node_nums; i++) {
            _matrix.push_back(std::vector<bool>(n, false));
        }
    }
    ~DesenGraph() {}

    void add_edge(int v, int w) {
        assert(v >=0 && v < _node_nums);
        assert(w >=0 && w < _node_nums);
        if (has_edge(v, w)) {
            return;
        }

        _matrix[v][w] = true;
        if (!_directed) {
            _matrix[w][v] = true;
        }
    }

    bool has_edge(int v, int w) const {
        assert(v >=0 && v < _node_nums);
        assert(w >=0 && w < _node_nums);
        return _matrix[v][w];
    }

protected:
    std::vector<std::vector<bool>> _matrix;
    int _node_nums = 0;
    int _edge_nums = 0;
    bool _directed = false;
};

#endif

