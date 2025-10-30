//
// Created by Fatma on 10/30/2025.
//

#include "priorityMaxheap.h"
#include <cassert>
#include <algorithm>

using namespace std;

template<typename T>
priorityMaxheap<T>::priorityMaxheap() {
    array=new pairs[capacity];
}
template<typename T>
int priorityMaxheap<T>::left(int node) {
    int child =2*node+1;
    return child>=size ? -1 : child;
}

template<typename T>
int priorityMaxheap<T>::right(int node) {
    int child =2*node+2;
    return child>=size ? -1 : child;
}
template<typename T>
int priorityMaxheap<T>::parent(int node) {
    return node==0 ? -1:(node-1)/2;
}

template<typename T>
bool priorityMaxheap<T>::isEmpty() {
    return size==0;
}

template<typename T>
void priorityMaxheap<T>::insert(int key, T value) {
    assert(size<capacity);
    array[size].value=value;
    array[size++].key=key;
    heapify_up(size-1);
}

template<typename T>
void priorityMaxheap<T>::heapify_up(int child) {
    int par = parent(child);
    if(child==0 || array[par].key >= array[child].key)
        return;
    swap(array[child], array[par]);
    heapify_up(par);

}

template<typename T>
T priorityMaxheap<T>::pop() {
    assert(size>0);
    T ret = array[0].value;
    array[0].value=array[size-1].value;
    array[0].key=array[--size].key;
    heapify_down(0);
    return ret;
}

template<typename T>
void priorityMaxheap<T>::heapify_down(int node) {
    int child = left(node);
    int rightChild = right(node);

    if(child==-1)
        return;
    if(rightChild!=-1 && array[rightChild].key>array[child].key)
        child=rightChild;
    if(array[node].key < array[child].key) {
        swap(array[node], array[child]);
        heapify_down(child);
    }


}


