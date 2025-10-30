//
// Created by Fatma on 6/12/2025.
//

#ifndef SELF_DATASTRUCTURE_OWN_IMPLEMENTATION_PRIORITYHEAP_H
#define SELF_DATASTRUCTURE_OWN_IMPLEMENTATION_PRIORITYHEAP_H


template<typename T>
class priorityMaxheap {
public:
    struct pairs{
        int key{};
        T value{};
    };
    priorityMaxheap();
    void insert (int key , T value);
    T pop();
    bool isEmpty();
private :
    pairs* array{};
    int size{};
    int capacity{1000};

    // it is about index
    int left(int node);
    int right(int node);
    int parent(int node);

    void heapify_up(int child);
    void heapify_down(int node);

};

#include "priorityMaxheap.tpp"

#endif //SELF_DATASTRUCTURE_OWN_IMPLEMENTATION_PRIORITYHEAP_H
