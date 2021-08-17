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

    graph.isEmpty();

    //Adding Edges:
    vector<Edge<int>> edges =
    {
        {1, 2 }, {2, 1 }, {2, 3 }, {3, 2 },{10, 1}, 
        {7, 10}, {10, 7}, {10, 2}, {10, 3}, {7, 1}
    };
    graph.addEdge(edges);

    cout<<"Graph: "<<endl;
    graph.printGraph();

    cout<<"The total number of edges: "<<graph.numEdges()<<endl;

    //Removing vertex and printing graph:
    graph.removeVertex(10);
    cout<<"Graph:"<<endl;
    graph.printGraph();

    //removing edge and printing graph:
    graph.removeEdge(2,3);
    cout<<"Graph:"<<endl;
    graph.printGraph();

    //counting the number of edges:
    cout<<"The total number of edges: "<<graph.numEdges()<<endl;
}
