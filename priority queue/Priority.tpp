//
// Created by Fatma on 6/12/2025.
//
#include "Priority.h"
/*template<typename T>
Priority<T>::Priority() {
    heap = MaxHeap<Pair>();
}*/
template<typename T>
void Priority<T>::insert(int key , T value) {

    heap.push({key,value});
    size++;
}
template<typename T>
T Priority<T>::pop() {
    Pair ret =heap.pop();
    size--;
    return ret.value;
}

template<typename T>
bool Priority<T>::isEmpty() {
    return size==0;
}