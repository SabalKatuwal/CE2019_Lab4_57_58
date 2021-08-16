#include <iostream>
#include <vector>
#include "../include/graph.h"
using namespace std;


template <class T>
bool Graph<T>::addEdge(T v1, T v2){
    Edge<T> tmp_edge;
    tmp_edge.from = v1;
    tmp_edge.to = v2;
    adjacencyList[tmp_edge.from].push_back(tmp_edge.to);
    if(direction==false){
        adjacencyList[tmp_edge.from].push_back(tmp_edge.to);
    }
    return true;
}


template <class T>
bool Graph<T>::addVertex(T v){
    vertex.push_back(v);
    Edge<T> tmp_edge;
    tmp_edge.from = v;
    tmp_edge.to = NULL;
    adjacencyList[tmp_edge.from].push_back(tmp_edge.to);  
    return true;  
}


template <class T>
bool Graph<T>::isEmpty(){
    if (adjacencyList.empty() && vertex.empty()){
        cout << "Graph is empty!!!"<<endl;
        return true;
    }
    return false;
}


template <class T>
bool Graph<T>::isDirected(){
    if (direction == false){
        cout<<"Graph isn't directed!!!"<<endl;
        return true;
    }
    else{
        cout<<"Graph is directed!!!"<<endl;
    }
}


template <class T>
bool Graph<T>::removeVertex(T remove){
    // Removing edges associated to it:
    for(auto &e : adjacencyList){
        if(adjacencyList[e.from] == remove){
            adjacencyList.remove(adjacencyList[e]);
        }
    }
    // Removing vertex:
    for(auto &v : vertex){
        if(v==remove){
            vertex.remove(vertex[v]);
            return true;
        }
    }
}


template <class T>
int Graph<T>::getAdjListSize(){
    return adjacencyList.size();
}


template <class T>
void Graph<T>::printGraph()
{   
    //N = graph.getAdjListSize();
    for (auto i : vertex)
    {
        // print the current vertex number
        cout << i << " ——> ";
 
        // print all neighboring vertices of a vertex `i`
        for (int v: adjacencyList[i]){
            cout << v << " ";
        }
        cout << endl;
    }
}










