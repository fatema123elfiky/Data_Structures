//
// Created by Fatma on 5/6/2025.
//

#include "Queue.h"

template<typename T>
Queue<T>::Queue():arr() {}
template<typename T>
void Queue<T>:: enqueue(T val){
    arr.insert_back(val);
}

template<typename T>
T Queue<T>:: dequeue(){
    arr.delete_last();
}

template<typename T>
bool Queue<T>:: isEmpty(){
    return arr.size()==0;
}

template<typename T>
void Queue<T>:: clear(){
    arr.clear();
}

template<typename T>
T Queue<T>::Front() {
    return arr.getHead();
}

template<typename T>
T Queue<T>::Back() {
    return arr.getTail();
}