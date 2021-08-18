#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
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

    void visualize();
    void removeEdge(T v1, T v2);
    int numEdges();
    int numVertex();
    int indegree(T v1);
    int outdegree(T v);
    int degree(T v);
    vector<T> neighbours(T v);
    //void neighbours(T v);

    bool neighbour(T v1, T v2);
    int getAdjListSize();
    void printVertex();
    void printGraph();
    
    private:
        bool direction;
        vector<T> vertex;
        vector<vector<T> > adjacencyList;
        int initialSize;
};


template <class T>
void Graph<T>::addEdge(vector<Edge<T> > const &edges){
    for (auto &edge: edges)
        {
            // insert at the end
            adjacencyList[edge.from].push_back(edge.to);
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
void Graph<T>::removeVertex(T element){
    // Removing vertex and respective edges alongside with it:
    for(auto &v : vertex){
        if(v==element){
            vertex.erase(std::remove(vertex.begin(), vertex.end(), v), vertex.end());
            adjacencyList[element].clear();
        }
        else{
            std::vector<T> elements;
            for(auto &c : adjacencyList[v]){
                if(c != element){
                    elements.push_back(c);
                }
            }
            adjacencyList[v].clear();
            for(auto &elem: elements){
                adjacencyList[v].push_back(elem);
            }
        }

    }

}


template <class T>
int Graph<T>::getAdjListSize(){
    return adjacencyList.size();
}


template <class T>
void Graph<T>::printVertex(){
    for(auto v : this->vertex){
        cout<<v<< " ";
    }
    cout <<endl;
}


template <class T>
void Graph<T>::printGraph(){
    int N = getAdjListSize();
    for (auto &v : vertex)
    {
        //print the current vertex number
        cout <<v<<"-->";

        for (auto &e: adjacencyList[v]){
            cout << e << " ";
        }
    cout << endl;   
    }
}


template<class T>
void Graph<T>::visualize() {
    for (int i = 0; i < adjacencyList.size(); ++i) {
        std::cout << i << std::endl;
        for (auto& ver: adjacencyList[i]) {
           std::cout << ver  << " ";
        }
        std::cout << std::endl;
        std::cout << "----------" << std::endl;
       }

}


template<class T>
void Graph<T>::removeEdge(T v1, T v2) {
    std::vector<T> elements;
    for(auto& c: adjacencyList[v1]){
       if(c != v2) {
           elements.push_back(c);
       }
    }
    adjacencyList[v1].clear();
    for(auto& elem: elements){
        adjacencyList[v1].push_back(elem);
    }
}


template<class T>
int Graph<T>::numEdges(){
    int count = 0;
    for(auto &edges : adjacencyList){
        count += edges.size();
    }
    return count;
}

template <class T>
int Graph<T>::numVertex(){
    return vertex.size();
}

template <class T>
int Graph<T>::outdegree(T v){
    int count=0;
    for (auto &e: adjacencyList[v]){
            count++;
        }
    return count;
}

template <class T>
int Graph<T>::indegree(T v1){
    int count=0;
    int N = getAdjListSize();
    for (auto &v : vertex)
    {
        for (auto &e: adjacencyList[v]){
            if(e==v1)
            {
                count++;
            }
        }  
    }
    return count;
}


template <class T>
int Graph<T>::degree(T v){
    return (indgree(T v)+outdegree(T v))
}


// template <class T>
// vector<T> Graph<T>::neighbours(T v){
//     for (auto &e: adjacencyList[v]){
//             cout << e << " ";
//         }
    
// }

template <class T>
bool Graph<T>::neighbour(T v1, T v2){
    int a=0;
    for (auto &e: adjacencyList[v1]){
            if(e==v2)
            {
                a=1;
            }
            else
            {a=0;}
    }       
    for (auto &e: adjacencyList[v2]){
            if(e==v1)
            {
                a=a+1;
            }   
            else{a=a+0;} 
    }
    if(a==0)
    {
        cout<<"Not neighbour"<<endl;
        return false;
    }
    else
    {
        cout<<"They are neighbours to each other"<<endl;
        return true;
    }
}
