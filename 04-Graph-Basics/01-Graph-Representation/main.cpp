#include <iostream>

#include "dense_graph.h"
#include "sparse_graph.h"
#include "read_graph.h"
#include "component.h"


int test_build_graph() {
    DesenGraph desen(10, false);
    desen.add_edge(2, 3);
    int v = 2;
    DesenGraph::Iterator desen_it(desen, v);
    for (int w = desen_it.begin(); !desen_it.end(); desen_it.next()) {
        std::cout << v << "---" << w << std::endl;
    }
    desen.show();

    SparseGraph sparse(10, false);
    sparse.add_edge(2, 3);
    v = 2;
    SparseGraph::Iterator sparse_it(sparse, v);
    for (int w = sparse_it.begin(); !sparse_it.end(); w = sparse_it.next()) {
        std::cout << v << "---" << w << std::endl;
    }
    sparse.show();

    ReadGraph<SparseGraph> read_graph(sparse, "test.txt");
    read_graph.read();
    return 0;
}

int test_component() {
    SparseGraph sparse(10, false);
    ReadGraph<SparseGraph> read_graph(sparse, "test.txt");
    read_graph.read();
    Component<SparseGraph> component(sparse);
    std::cout << component.count() << std::endl;
    return 0;
}

int main() {
    return 0;
}

