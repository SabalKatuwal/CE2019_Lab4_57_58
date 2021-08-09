#pragma once
#include <iostream>
#include <vector>

using namespace std;

struct vertex  //for vertices
{
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

struct graph
{
    graph(bool isdirected);
    
    // Default is undirected:
    graph(){
        this->direction = false;
    }

    bool isEmpty();
    bool isDirected();
    bool addVertex(vertex *vertex);
    bool addEdge(vertex *vertex1, vertex *vertex2);
    bool removeVertex(vertex remove);
    bool removeEdge(vertex *vertex1, vertex *vertex2);
    int numEdges();
    int numVertex();
    int indegree(vertex vertex);
    int outdegree(vertex vertex);
    int degree(vertex vertex);
    vector<vertex> neighbours(vertex vertex);

    private:
        bool direction;
        // make a adjacencyList here!
};





