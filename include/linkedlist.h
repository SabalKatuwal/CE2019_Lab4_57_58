#pragma once
#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
    node() : next(nullptr){}
    node(int data, node *next) : next(next), data(data) {}
};


struct linkedList{
    node *head;
    node *tail;
    linkedList(){
        head = nullptr;
        tail = nullptr;
    }
    void addToHead(int data);
    bool isEmpty();
    void insert(int data, node *d);
    int removeFromHead();
    int remove(int data);
    bool search(int data);
    void traverse();
};