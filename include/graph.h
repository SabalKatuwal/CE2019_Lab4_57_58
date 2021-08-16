#pragma once
#include <iostream>
#include <vector>
//#include "linkedlist.h"

using namespace std;


template <class T>
struct Edge  //for vertices
{
    T from, to;
};


template <class T>
struct Graph
{   
    //if direction specified: 
    Graph(bool isdirected){
        this->direction = isdirected;
    }
    
    //if direction not specified:
    Graph(){
        this->direction = true;
    }
    bool isEmpty();
    bool isDirected();
    bool addVertex(T v);
    bool addEdge(T v1, T v2);
    bool removeVertex(T remove);
    bool removeEdge(T v1, T v2);
    int numEdges();
    int numVertex();
    int indegree(T v1);
    int outdegree(T v);
    int degree(T v);
    vector<T> neighbours(T v);
    bool neighbour(T v1, T v2);
    int getAdjListSize();
    void printGraph();
    
    private:
        bool direction;
        vector<T> vertex;
        vector<vector<T>> adjacencyList;
};








