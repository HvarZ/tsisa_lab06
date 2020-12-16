#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <boost/property_map/property_map.hpp>
#include <boost/graph/graph_traits.hpp>
#include <iostream>
#include <algorithm>

using boost::add_edge;

typedef boost::property<boost::edge_weight_t, int> EdgeWeightProperty;
typedef boost::adjacency_list<boost::listS, boost::vecS, boost::directedS, boost::no_property, EdgeWeightProperty> DirectedGraph;
typedef boost::graph_traits<DirectedGraph>::edge_iterator edge_iterator;
typedef boost::graph_traits<DirectedGraph>::vertex_descriptor vertex_descriptor;

int main() {
    DirectedGraph graph;

    int weights[] = {3, 3, 2, 5, 1, 4, 3, 2, 3, 4, 5};

    add_edge(1, 2, weights[0], graph);
    add_edge(1, 3, weights[1], graph);
    add_edge(1, 4, weights[2], graph);
    add_edge(2, 5, weights[3], graph);
    add_edge(3, 4, weights[4], graph);
    add_edge(4, 6, weights[5], graph);
    add_edge(4, 7, weights[6], graph);
    add_edge(5, 6, weights[7], graph);
    add_edge(5, 7, weights[8], graph);
    add_edge(6, 8, weights[9], graph);
    add_edge(7, 8, weights[10], graph);

    std::pair<edge_iterator, edge_iterator> ei = edges(graph);

    std::cout << "Number of edges " << num_edges(graph) << std::endl;

    std::copy(ei.first, ei.second,
              std::ostream_iterator<boost::adjacency_list<>::edge_descriptor>{std::cout, "\n"});

    std::cout << std::endl;


    std::vector<vertex_descriptor> p(num_vertices(graph));
    std::vector<int> d(num_vertices(graph));

    vertex_descriptor start = vertex(1, graph);
    vertex_descriptor final = vertex(8, graph);

    boost::dijkstra_shortest_paths(graph, start, boost::predecessor_map(&p[0]).distance_map(&d[0]));

    std::vector<boost::graph_traits<DirectedGraph>::vertex_descriptor> path;
    boost::graph_traits<DirectedGraph>::vertex_descriptor current = final;

    while(current != start) {
        path.push_back(current);
        current = p[current];
    }

    path.push_back(start);

    std::cout << "Path from " << 1 << " to " << 8 << std::endl;
    std::vector<boost::graph_traits<DirectedGraph>::vertex_descriptor>::reverse_iterator it;

    int sum = 0;

    for (it = path.rbegin(); it != path.rend(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << sum;

    return 0;
}
