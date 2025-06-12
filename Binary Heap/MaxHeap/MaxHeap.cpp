//
// Created by Fatma on 6/12/2025.
//

#include "MaxHeap.h"
#include <cassert>
#include <algorithm>

using namespace std;


template<typename T>
int MaxHeap<T>::left(int node) {
    int child =2*node+1;
    return child>=size ? -1 : child;
}

template<typename T>
int MaxHeap<T>::right(int node) {
    int child =2*node+2;
    return child>=size ? -1 : child;
}
template<typename T>
int MaxHeap<T>::parent(int node) {
    return node==0 ? -1:(node-1)/2;
}

template<typename T>
MaxHeap<T>::MaxHeap() {
    array=new T[capacity]{ };
    size=0;
}

template<typename T>
MaxHeap<T>::~MaxHeap() {
    delete[] array;
    array= nullptr;
}

template<typename T>
bool MaxHeap<T>::isEmpty() {
    return size==0;
}

template<typename T>
T MaxHeap<T>::top() {
    assert(!isEmpty());
    return array[0];
}

template<typename T>
void MaxHeap<T>::push(T key) {
    assert(size+1<=capacity);
    array[size++]=key;
    heapify_up(size-1);
}

template<typename T>
void MaxHeap<T>::heapify_up(int child) {
    int par = parent(child);
    if(child==0||array[par]>=array[child])
        return;
    swap(array[par],array[child]);
    heapify_up(par);

}

template<typename T>
void MaxHeap<T>::pop() {
    assert(!isEmpty());
    array[0]=array[--size];
    heapify_down(0);
}

template<typename T>
void MaxHeap<T>::heapify_down(int node) {
    int child = left(node);
    int right_child = right(node);
    if(child==-1)
        return;
    if(right_child!=-1&&array[right_child]>array[child])
        child=right_child;
    if(array[node]>array[child]) {
        swap(array[node], array[child]);
        heapify_down(child);
    }
}

template<typename T>
MaxHeap<T>::MaxHeap(const T *arr, int sz) {
    assert(sz<=capacity);
    array=new T [capacity]{};
    for (int index = 0; index < sz; ++index)
        array[index]=arr[index];
    heapify();
}

template<typename T>
void MaxHeap<T>::heapify() {
    for (int index = size/2 - 1; index >=0 ; ++index)
        heapify_down(index);

}

template<typename T>
void MaxHeap<T>::HeapSort(T* arr , int sz) {

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