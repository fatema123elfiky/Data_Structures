//
// Created by Fatma on 5/6/2025.
//

#include "Stack.h"

template<typename T>
Stack<T>::Stack(int size) : data(size){}

template<typename T>
bool Stack<T>::IsFull() {
    return data.isFull();
}

template<typename T>
bool Stack<T>::IsEmpty(){
    return data.isEmpty();
}

template<typename T>
T Stack<T>::peek() {
    return data.Front();
}

template <typename T>
void Stack<T>::push(T val) {
    insert_front(val);
}

template<typename T>
void Stack<T>::insertfront(T val) {
   int sz = added_elements;
   data.enqueue(val);
   while(sz--)
       data.enqueue(data.dequeue());
   added_elements++;

}
template<typename T>
T Stack<T>::pop() {
  data.dequeue();
}