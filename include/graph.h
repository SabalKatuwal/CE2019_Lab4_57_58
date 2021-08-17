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
    Graph(int initial_size, bool isdirected){
        this->direction = isdirected;
        this->initialSize = initial_size;
        adjacencyList.resize(initialSize);
    }
    

    //if direction not specified:
    Graph(int initial_size){
        this->direction = true;
        this->initialSize = initial_size;
        adjacencyList.resize(initialSize);
    }


    bool isEmpty();
    bool isDirected();
    void addVertex(T v);
    void addEdge(vector<Edge<T>> const &edges);
    void removeVertex(T remove);
    void removeEdge(T v1, T v2);
    int numEdges();
    int numVertex();
    int indegree(T v1);
    int outdegree(T v);
    int degree(T v);
    vector<T> neighbours(T v);
    bool neighbour(T v1, T v2);
    int getAdjListSize();
    void printEdge();
    void printVertex();
    
    private:
        bool direction;
        vector<T> vertex;
        vector<vector<T>> adjacencyList;
        int initialSize;
};


template <class T>
void Graph<T>::addEdge(vector<Edge<T>> const &edges){
    for (auto &edge: edges)
        {
            // insert at the end
            adjacencyList[edge.from].push_back(edge.to);
            cout<<"Edge added!"<<endl;
            if(direction==false){
                adjacencyList[edge.to].push_back(edge.from);
            }
        }
}


template <class T>
void Graph<T>::addVertex(T v){
    vertex.push_back(v);    
}


template <class T>
bool Graph<T>::isEmpty(){
    //adjacencyList.empty() &&
    if (vertex.empty()){
        cout << "Graph is empty!!!"<<endl;
        return true;
    }
    cout<<"Graph is not empty!!!"<<endl;
    return false;
}


template <class T>
bool Graph<T>::isDirected(){
    if (direction == false){
        cout<<"Graph isn't directed!!!"<<endl;
        return false;
    }
    else{
        cout<<"Graph is directed!!!"<<endl;
        return true;
    }
}


template <class T>
void Graph<T>::removeVertex(T remove){
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
        }
    }
}


template <class T>
int Graph<T>::getAdjListSize(){
    return adjacencyList.size();
}


template <class T>
void Graph<T>::printEdge()
{   
    int N = getAdjListSize();
    for (int i=0; i<N; i++)
    {
        //print the current vertex number
        cout <<i<<"-->";

        for (auto v: adjacencyList[i]){
            cout << v << " ";
        }
    cout << endl;
    }
}


template <class T>
void Graph<T>::printVertex(){
    for(auto v : this->vertex){
        cout<<v<< " ";
    }
    cout <<endl;
}








