#ifndef _EDGE_H_
#define _EDGE_H_

template<typename Weight>
class Edge {
public:
    Edge(int v, int w, Weight weight)
        : _v(v),
          _w(w),
          _weight(weight) {}

    ~Edge() {}

    int V() const {
        return _v;
    }

    int W() const {
        return _w;
    }

    bool operator<(const Edge<Weight>& edge) const {
        return _weight < edge._weight;
    }

    bool operator<=(const Edge<Weight>& edge) const {
        return _weight <= edge._weight;
    }

    bool operator>(const Edge<Weight>& edge) const {
        return _weight > edge._weight;
    }

    bool operator>=(const Edge<Weight>& edge) const {
        return _weight >= edge._weight;
    }

    bool operator==(const Edge<Weight>& edge) const {
        return _weight == edge._weight;
    }

protected:
    int _v;
    int _w;
    Weight _weight;
};
#endif

