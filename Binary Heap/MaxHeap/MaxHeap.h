//
// Created by Fatma on 6/12/2025.
//

#ifndef SELF_DATASTRUCTURE_OWN_IMPLEMENTATION_MAXHEAP_H
#define SELF_DATASTRUCTURE_OWN_IMPLEMENTATION_MAXHEAP_H

template<typename T>

class MaxHeap {
private:
    T* array{};
    int size{};
    int capacity{1000};//later on change in code to be dynamic
    /**
      * @param node "the index"
      * @return index of left child
      */
    int left(int node);

    /**
     * @param node "the index"
     * @return index of right child
     */
    int right(int node);

    /**
     * @param node "the index"
     * @return index of parent
     */
    int parent(int node);
    void heapify_up(int child);
    void heapify_down(int node);
    void heapify();
public:

    bool isEmpty();//
    void pop();//
    void push(T key);//
    T top();//
    ~MaxHeap();//
    MaxHeap();//
    MaxHeap(const T * arr , int sz);
    void HeapSort(T * arr , int sz);
};


#endif //SELF_DATASTRUCTURE_OWN_IMPLEMENTATION_MAXHEAP_H
