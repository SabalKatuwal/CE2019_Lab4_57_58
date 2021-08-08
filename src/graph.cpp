#include <iostream>
#include "graph.h"

graph::graph()
{
    //HEAD = nullptr;
    TOP = nullptr;
}
bool graph::isEmpty()
{
    // vertex* newVertex= new vertex();
    // if(newVertex->info == NULL)
    // {
    //     return true;
    // }
    if(TOP == NULL)
    {return true;}
}

int graph::addVertex(int data)
{

    vertex* newVertex= new vertex();
    newVertex->info = data;
    //newVertex->nextVertex= TOP;
    TOP = newVertex;
}

int graph::addEdge(int data1,int data2)
{
    top->nextVertex = newVertex->nextVertex ;
    top->neighbour = newVertex;
    top= newVertex
}
