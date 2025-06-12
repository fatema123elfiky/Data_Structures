//
// Created by Fatma on 6/12/2025.
//

#ifndef SELF_DATASTRUCTURE_OWN_IMPLEMENTATION_MINHEAP_H
#define SELF_DATASTRUCTURE_OWN_IMPLEMENTATION_MINHEAP_H

template<typename T>
class MinHeap {
private:
    T *array{};
    int size{};
    int capacity{1000};// as in the vector

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

    void heapify_up(int child_pos);
    void heapify_down(int parent_pos);
    void heapify();
public:

     MinHeap();
    ~MinHeap();
    void push (T key);
    bool isEmpty();
    MinHeap(const T * arr , int sz);


    /** min value*/
    T top();

    /** remove smallest value*/
    void pop();
    void HeapSort(T * arr , int sz);
};


#endif //SELF_DATASTRUCTURE_OWN_IMPLEMENTATION_MINHEAP_H
