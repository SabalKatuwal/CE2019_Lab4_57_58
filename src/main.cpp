#include <iostream>
#include "../include/graph.h"
using namespace std;


int main()
{
    Graph<int> graph(7);

    //checking empty and directed:
    graph.isEmpty();
    graph.isDirected();

    //Adding vertex: 
    graph.addVertex(0);
    graph.addVertex(1);
    graph.addVertex(2);
    graph.addVertex(3);

    graph.isEmpty();
    graph.printVertex();

    //Adding Edges:
    vector<Edge<int>> edges =
    {
        {1, 2 }, {2, 1 }, {2, 3 }, {3, 2 }, {4, 1}, {1, 4}
    };
    graph.addEdge(edges);

    graph.printEdge();
}
