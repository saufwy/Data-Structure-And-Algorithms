#include <iostream>

#include "dense_graph.h"
#include "sparse_graph.h"

int main() {
    DesenGraph desen(10, false);
    desen.add_edge(2, 3);

    SparseGraph sparse(10, false);
    sparse.add_edge(2, 3);
    return 0;
}

