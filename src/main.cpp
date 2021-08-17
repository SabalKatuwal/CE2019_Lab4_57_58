#include <iostream>
#include "../include/graph.h"
using namespace std;


int main()
{
    Graph<int> graph(20);

    //checking empty and directed:
    graph.isEmpty();
    graph.isDirected();

    //Adding vertex: 
    graph.addVertex(0);
    graph.addVertex(1);
    graph.addVertex(2);
    graph.addVertex(3);
    graph.addVertex(10);
    graph.addVertex(7);


    //checking vertex remove operation:
    cout<<"Vertex:"<<endl;
    graph.printVertex();

    graph.removeVertex(0);

    cout<<"Vertex:"<<endl;
    graph.printVertex();

    graph.isEmpty();
    graph.printVertex();


    //Adding Edges:
    vector<Edge<int>> edges =
    {
        {1, 2 }, {2, 1 }, {2, 3 }, {3, 2 }, {4, 1}, {1, 4},
        {10, 1}, {7, 10}, {10, 7}, {10, 2}, {10, 3}, {7, 1}
    };
    graph.addEdge(edges);

    //printing graph:
    cout<<"Graph: "<<endl;
    graph.printGraph();
}
