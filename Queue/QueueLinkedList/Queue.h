//
// Created by Fatma on 5/6/2025.
//

#ifndef DATA_STRUCTURES_QUEUE_H
#define DATA_STRUCTURES_QUEUE_H
#include "../../Singly linked List/Singly_Linked_List.h"


//LinkedList-based

template<typename T>
class Queue {
private:
   Singly_Linked_List<T> arr;
public:
    Queue();
    void enqueue(T val);
    T dequeue();
    bool isEmpty();
    void clear();
    T Front();
    T Back();
};


#endif //DATA_STRUCTURES_QUEUE_H
