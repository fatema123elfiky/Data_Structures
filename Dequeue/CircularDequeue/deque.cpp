//
// Created by Fatma on 5/6/2025.
//

#include "deque.h"
#include <iostream>

using namespace std;

template<typename T>
bool deque<T>::isEmpty() {
    return added_elements==0;
}

template<typename T>
bool deque<T>::isFull() {
    return added_elements==sz;
}

template<typename T>
void deque<T>::clear() {
    front=end=added_elements=0;
}

template<typename T>
T deque<T>::Back() {
    return arr[end];
}

template<typename T>
T deque<T>::Front() {
    return arr[front];
}

template<typename T>
T deque<T>::dequeue_back() {
    assert(!isEmpty());
    end= back(end);
    T val = arr[end];
    added_elements--;
    return val;
}

template<typename T>
T deque<T>::dequeue_front() {
    assert(!isEmpty());
    T val = arr[front];
    front= next(front);
    added_elements--;
    return val;
}

template<typename T>
void deque<T>::enqueue_back(T val) {
    assert(!isFull());
    arr[end]=val;
    end= next(end);
    added_elements++;
}

template<typename T>
void deque<T>::enqueue_front(T val) {
    assert(!isFull());
    front= back(front);
    arr[front]=val;
    added_elements++;
}

template<typename T>
deque<T>::deque(int size) {
    if(size<=0)
        this->sz=1;
    this->sz=size;
    arr = new T [sz];
}

template<typename T>
int deque<T>::back(int idx) {
    if(idx==0)
        return sz-1;
    return --idx;
}

template<typename T>
int deque<T>::next(int idx) {
    return (++idx)%sz;
}

template<typename T>
void deque<T>::display() {

    cout<<"the deque looks like : ";
    for (int idx = front , steps =0 ;  steps<added_elements; steps++,idx=next(idx))
        cout<<arr[idx]<<' ';
    cout<<"\n\n";

}

