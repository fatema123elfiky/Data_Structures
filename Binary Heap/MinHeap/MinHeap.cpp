//
// Created by Fatma on 6/12/2025.
//

#include "MinHeap.h"
#include <cassert>
#include <algorithm>
using namespace std;

template<typename T>
int MinHeap<T>::left(int node) {
    int child =2*node+1;
    return child>=size ? -1 : child;
}

template<typename T>
int MinHeap<T>::right(int node) {
    int child =2*node+2;
    return child>=size ? -1 : child;
}
template<typename T>
int MinHeap<T>::parent(int node) {
    return node==0 ? -1:(node-1)/2;
}

template<typename T>
MinHeap<T>::MinHeap() {
    array=new T[capacity]{ };
    size=0;
}

template<typename T>
MinHeap<T>::~MinHeap() {
    delete[] array;
    array= nullptr;
}

template<typename T>
void MinHeap<T>::push(T key) {
    assert(size+1>=capacity);
    array[size++]=key;
    heapify_up(size-1);
}

template<typename T>
void MinHeap<T>::heapify_up(int child_pos) {//O(log n)

    // bottom up
    int par_pos= parent(child_pos);
    if(child_pos==0||array[par_pos]<= array[child_pos])
        return;
    swap(array[par_pos],array[child_pos]);
    heapify_up(par_pos);
}

template<typename T>
T MinHeap<T>::top() {
    assert(!isEmpty());
    return array[0];
}

template<typename T>
void MinHeap<T>::pop() {
    assert(!isEmpty());
    array[0]=array[--size];
    heapify_down(0);
}

template<typename T>
void MinHeap<T>::heapify_down(int parent_pos) {
    int child = left(parent_pos);
    int right_child = right(parent_pos);
    if(child==-1)
        return;
    if(right_child!=-1&&array[right_child]<array[child])
        child=right_child;
    if(array[parent_pos]>array[child]) {
        swap(array[parent_pos], array[child]);
        heapify_down(child);
    }
}

template<typename T>
bool MinHeap<T>::isEmpty() {
    return size==0;
}

template<typename T>
MinHeap<T>::MinHeap(const T *arr, int sz) {
    assert(sz<=capacity);
    array=new T [capacity]{};
    size=sz;
    for (int index = 0; index < sz; ++index)
        array[index]=arr[index];
    heapify();
}

template<typename T>
void MinHeap<T>::heapify() {
    for (int index = size/2 - 1; index >=0 ; ++index)
        heapify_down(index);

}

template<typename T>
void MinHeap<T>::HeapSort(T* arr , int sz) {

    T* oldarr =array;
    int oldsize=size;

    array=arr;
    size=sz;

    heapify();
    while (size--){
        swap(array[0],array[size]);
        heapify_down(0);
    }
    for (int i = 0; i < sz/2; ++i)
        swap(array[i],array[sz-i-1]);
    array=oldarr;
    size=oldsize;


}