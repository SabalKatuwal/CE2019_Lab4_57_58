#include <iostream>
#include "../include/graph.h"
using namespace std;


int main()
{
    Graph<int> graph;

    //checking empty and directed:
    graph.isEmpty();
    graph.isDirected();

    //Adding vertex: 
    graph.addVertex(0);
    graph.addVertex(1);
    graph.addVertex(2);
    graph.addVertex(3);

    //Adding Edges:
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 0);
    graph.addEdge(2, 1);
    graph.addEdge(3, 2);

    graph.printGraph();

}
