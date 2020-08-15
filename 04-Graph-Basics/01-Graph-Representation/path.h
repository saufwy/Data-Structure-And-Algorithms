#ifndef _PATH_H_
#define _PATH_H_

#include <vector>
#include <stack>

template <typename Graph>
class Path {
public:
    Path(Graph& graph, int s)
        : _graph(graph),
          _s(s) {
        _visited.resize(graph.V(), false);
        _from.resize(graph.V(), -1);
        dfs(s);
    }


    bool has_path(int w) const {
        return _visited[w];
    }

    void get_path(int w, std::vector<int>& vec) {
        std::stack<int> sk; 
        while (_from[w] != -1) {
            sk.push(w);
        }
        while (!sk.empty()) {
            vec.push_back(sk.top());
            sk.pop();
        }
    }

protected:
    void dfs(int i) {
        _visited[i] = true;
        typename Graph::Iterator it(_graph, i);
        for (int v = it.begin(); !it.end(); v = it.next()) {
            if (!_visited[v]) {
                _from[v] = i;
                dfs(v);
            }
        }
    }

protected:
    Graph& _graph;
    int _s = 0;
    std::vector<bool> _visited;
    std::vector<int> _from;

};
#endif

