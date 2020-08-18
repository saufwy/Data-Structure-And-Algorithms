#ifndef _DESEN_GRAPH_H_
#define _DESEN_GRAPH_H_

#include <vector>
#include <cassert>

#include "edge.h"

template<typename Weight>
class DesenGraph {
public:
    DesenGraph(int n, bool directed) {
        _node_nums = n;
        _directed = directed;
        for (int i = 0; i < _node_nums; i++) {
            _matrix.push_back(std::vector<bool>(n, nullptr));
        }
    }
    ~DesenGraph() {}

    void add_edge(int v, int w, Weight weight) {
        assert(v >=0 && v < _node_nums);
        assert(w >=0 && w < _node_nums);
        if (has_edge(v, w)) {
            return;
        }

        _matrix[v][w] = new Edge<Weight>(v, w, weight;
        if (!_directed) {
            _matrix[w][v] = new Edge<Weight>(v, w, weight;
        }
    }

    bool has_edge(int v, int w) const {
        assert(v >=0 && v < _node_nums);
        assert(w >=0 && w < _node_nums);
        return _matrix[v][w] != nullptr;
    }

    void show() const {
        for (int i = 0; i < _node_nums; i++) {
            std::cout << i << " : ";
            for (int j = 0; j < _node_nums; j++) {
                if (_matrix[i][j]) {
                    std::cout << _matrix[i][j]->w() << " ";
                }
            }
            std::cout << std::endl;
        }
    }

public:
    class Iterator {
    public:
        Iterator(DesenGraph& desen_graph, int v)
            : _desen_graph(desen_graph),
              _v(v) {}

        Edge<Weight>* begin() {
            _index = -1;
            return next();
        }

        Edge<Weight>* next() {
            for (_index++; _index < _desen_graph._node_nums; _index++) {
                if (_desen_graph._matrix[_v][_index]) {
                    return _desen_graph[v][_index];
                }
            }
            return nullptr;
        }

        bool end() {
            return _index >= _desen_graph._node_nums;
        }

    protected:
        DesenGraph& _desen_graph;
        int _v;
        int _index = -1;
    };

protected:
    std::vector<std::vector<Edge<Weight>* >> _matrix;
    int _node_nums = 0;
    int _edge_nums = 0;
    bool _directed = false;
};

#endif

