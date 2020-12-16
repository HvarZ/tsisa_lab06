#include <boost/graph/adjacency_list.hpp>
#include <iostream>

using boost::add_edge;

typedef boost::property<boost::edge_weight_t, int> EdgeWeightProperty;
typedef boost::adjacency_list<boost::listS, boost::vecS, boost::directedS, boost::no_property, EdgeWeightProperty> DirectedGraph;
typedef boost::graph_traits<DirectedGraph>::edge_iterator edge_iterator;

int main() {
    DirectedGraph graph;

    add_edge(1, 2, 3, graph);
    add_edge(1, 3, 3, graph);
    add_edge(1, 4, 2, graph);
    add_edge(2, 5, 5, graph);
    add_edge(3, 4, 1, graph);
    add_edge(4, 6, 4, graph);
    add_edge(4, 7, 3, graph);
    add_edge(5, 6, 2, graph);
    add_edge(6, 8, 4, graph);
    add_edge(7, 8, 5, graph);
}
