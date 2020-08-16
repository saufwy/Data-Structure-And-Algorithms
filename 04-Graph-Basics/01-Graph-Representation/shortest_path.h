#ifndef _SHORTEST_PATH_H_
#define _SHORTEST_PATH_H_

#include <vector>
#include <queue>

template <typename Graph>
class ShortestPath {
public:
    ShortestPath(Graph& graph, int s)
        : _graph(graph),
          _s(s) {
        _visited.resize(graph.V(), false);
        _ord.resize(graph.V(), -1);
        _from.resize(graph.V(), -1);
        bfs(s);
    }
    ~ShortestPath() {}

    bool has_path(int v) const {
        return _visited[v];
    }

protected:
    void bfs(int i) {
        std::queue<int> q;
        q.push(i);
        _ord[i] = 0;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            typename Graph::Iterator it(_graph, v);
            for (int w = it.begin(); !it.end(); w = it.next()) {
                q.push(w);
                _visited[w] = true;
                _ord[w] = _ord[v] + 1;
                _from[w] = v;
            }
        }
    }

protected:
   Graph& _graph; 
   int _s;

   std::vector<bool> _visited;
   std::vector<int> _from;
   std::vector<int> _ord; 
};
#endif

