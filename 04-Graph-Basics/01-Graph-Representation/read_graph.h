#ifndef _READ_GRAPH_H_
#define _READ_GRAPH_H_

#include <string>
#include <cassert>
#include <fstream>
#include <sstream>

template <typename Graph>
class ReadGraph {
public:
    ReadGraph(Graph& graph, const std::string& filename) 
        : _graph(graph),
          _filename(filename) {}
    bool read() {
        std::ifstream file(_filename);
        assert(file.is_open());

        std::string line;
        assert(getline(file, line));
        std::stringstream ss(line);
        int V, E;
        ss >> E >> E;
        for (int i = 0; i < E; i++) {
            assert(getline(file, line));
            std::stringstream ss(line);
            int a, b;
            ss >> a >> b;
            _graph.add_edge(a, b);
        }
        return true;
    }

protected:
    Graph& _graph;
    std::string _filename;
};

#endif

