#pragma once

template <class T>
class node{
    public:
        T data;
        node<T> *next;
};


template <class T>
class linkedlist{
    public:
        linkedlist();
        bool isEmpty();
        void addToHead(T data);
        void addToTail(T data);
        void add(T data, node<T> *predecesor);
        int removeFromHead();
        void removeFromTail();
        void remove(T data);
        bool retrieve(T data, node<T> *dataOutPtr);
        void traverse();
    protected:
        node *head;
        node *tail;
};