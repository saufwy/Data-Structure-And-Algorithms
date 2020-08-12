#include <iostream>

#include "dense_graph.h"
#include "sparse_graph.h"
#include "read_graph.h"

int main() {
    DesenGraph desen(10, false);
    desen.add_edge(2, 3);
    int v = 2;
    DesenGraph::Iterator desen_it(desen, v);
    for (int w = desen_it.begin(); !desen_it.end(); desen_it.next()) {
        std::cout << v << "---" << w << std::endl;
    }

    SparseGraph sparse(10, false);
    sparse.add_edge(2, 3);
    v = 2;
    SparseGraph::Iterator sparse_it(sparse, v);
    for (int w = sparse_it.begin(); !sparse_it.end(); w = sparse_it.next()) {
        std::cout << v << "---" << w << std::endl;
    }

    ReadGraph<SparseGraph> read_graph(sparse, "sparse.txt");
    read_graph.read();
    return 0;
}

