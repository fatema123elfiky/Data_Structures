//
// Created by Fatma on 5/6/2025.
//

#include "queue.h"

template<typename T>
queue<T>::queue(int sz) {
    if(sz<=0)
        sz=1;
    this->sz=sz;
    arr = new T [sz];
}

template<typename T>
bool queue<T>::isEmpty() {
    return added_elements==0;
}

template<typename T>
bool queue<T>::isFull() {
    return added_elements==sz;
}

template<typename T>
void queue<T>::clear() {
    front=end=added_elements=0;
}

template<typename T>
T queue<T>::dequeue() {
    assert(!isEmpty());
    T val = arr[front];
    front= next(front);
    added_elements--;
    return val;
}

template<typename T>
void queue<T>::enqueue(T val) {
    assert(!isFull());
    arr[end]=val;
    end= next(end);
    added_elements++;
}

template<typename T>
int queue<T>::next(int idx) {
    return (++idx)%sz;
}

template<typename T>
T queue<T>::Front() {
    return arr[front];
}

template<typename T>
T queue<T>::Back() {
    return arr[end];
}
