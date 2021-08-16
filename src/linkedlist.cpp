// Implementation from previous lab: 

#include <iostream>
#include "../include/linkedlist.h"


template <class T>
linkedlist<T>::linkedlist(){
    head = nullptr;
    tail = nullptr;
}


template <class T>
bool linkedlist<T>::isEmpty(){
    if (head == nullptr){
        return true;
    }
    else{
        return false;
    }
}


template<class T>
void linkedlist<T>::addToHead(T data){
    node *newNode = new node();
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    // If added node is the only node in the list
    if (tail == nullptr){
        tail = head;
    }
}


template <class T>
void linkedlist<T>::addToTail(T data){
    node<T> *newNode = new node();
    if(this->isEmpty()){
        newNode->data = data;
        newNode->next = nullptr;
        tail = newNode;
        head = tail;
    }
    else{
        newNode->data = data;
        newNode->next = nullptr;
        tail->next = newNode;
        tail = newNode;
    }
}


template <class T>
void linkedlist<T>::add(T data, node<T> *predecessor){
    node<T> *newNode = new node();
    newNode->data = data;
    newNode->next = predecessor->next;
    predecessor->next = newNode;
}


template <class T>
void linkedlist<T>::traverse(){
    node<T> *p = new node();
    p = head;
    while(p!=nullptr){
        std::cout<<p->data<<std::endl;
        p = p->next;
    }
}


template <class T>
int linkedlist<T>::removeFromHead(){
    if(!this->isEmpty()){
        node<T> *nodeToDelete = new node();
        nodeToDelete = head;
        int pop_value = head->data;
        head = nodeToDelete->next;
        delete nodeToDelete;
        // If list becomes empty after deletion
        if(head==nullptr){
            tail = nullptr;
        }
        return pop_value;
    }
    return 0;
}


template <class T>
void linkedlist<T>::removeFromTail(){
    if(!this->isEmpty()){
        node<T> *nodeToDelete = new node();
        nodeToDelete = tail;
        if(head == tail){
            head = nullptr;
            tail = nullptr;
        }
        else{
            node *predecessor = new node();
            predecessor = head;
            while(predecessor->next !=tail){
                predecessor = predecessor->next;
            }
            tail = predecessor;
            predecessor->next = nullptr;
        }
        delete nodeToDelete;
    }
}


template <class T>
void linkedlist<T>::remove(T data){
    if(!this->isEmpty()){
        if (head->data == data){
            removeFromHead();
        }
        else{
            node<T> *temp = new node();
            temp = head->next;
            node<T> *previous = new node();
            previous = head;

            while(temp!=nullptr){
                if(temp->data==data){
                    break;
                }
                else{
                    previous = previous->next;
                    temp = temp->next;
                }
            }
            if(temp != nullptr){
                previous->next = temp->next;
                delete temp;
                if (previous->next == nullptr){
                    tail = previous;
                }
            }
        }
    }
}


template <class T>
bool linkedlist<T>::retrieve(T data, node<T> *outPtr){
    node<T> *point = head;
    while(point!=nullptr && point->data!=data){
        point = point->next;
    }
    if(point==nullptr){
        return false;
    }
    else{
        outPtr = point;
        return true;
    }
}
















