#pragma once
#include <iostream>
using namespace std;

class vertex  //for vertices
{
    public:
    int info;
    vertex* nextVertex;
    vertex* neighbour;

    vertex(): nextVertex(nullptr),info(NULL), neighbour(nullptr){}
    vertex(vertex * nextVertex, int info, vertex* neighbour): nextVertex(nextVertex), info(info), neighbour(neighbour){}

};

// class adjNode //for adjacent neighbours
// {
//     public:
//     int info;
//     adjNode* next;

//     adjNode():next(nullptr){}
//     adjNode(int info, adjNode* next):info(info), next(next) {}

// };

class graph
{
    public:
    graph();
    bool isEmpty();
    int addVertex(int data);
    int addEdge(int data1,int data2);
    //int vertices[50];
    //int edge;

    private:
    //vertex *HEAD;
    vertex * TOP;
};





