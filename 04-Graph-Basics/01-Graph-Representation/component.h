#ifndef _COMPONENT_H_
#define _COMPONENT_H_

#include <vector>

template <typename Graph>
class Component {
public:
    Component(Graph& graph)
        : _graph(graph) {
        _visited.resize(graph.V(), false);
        for (int i = 0; i < graph.V(); i++) {
            if (_visited[i]) {
                _count++;
                dfs(i);
            }
        }
    }

    int count() const {
        return _count;
    }

protected:
    void dfs(int i) {
        _visited[i] = true;
        typename Graph::Iterator it(_graph, i);
        for (int v = it.begin(); !it.end(); v = it.next()) {
            if (!_visited[v]) {
                dfs(v);
            }
        }
    }

protected:
    int _count = 0;
    Graph& _graph;
    std::vector<bool> _visited;
};
#endif

