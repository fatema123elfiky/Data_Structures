//
// Created by Fatma on 3/27/2025.
//

#include "Stack.h"
#include <cassert>

template<typename T>
void Stack<T>::push(T val) {
        assert(!IsFull());
        array[++top]=val;
}

template<typename T>
bool Stack<T>::IsFull() {
    return top==size-1;
}

template<typename T>
bool Stack<T>::IsEmpty() {
    return top==-1;
}

template<typename T>
Stack<T>::Stack(int size):size(size),top(-1){
    if(size<1)
        size=1;
    array=new T (size);
}

template<typename T>
Stack<T>::~Stack() {
    delete array;
}

template<typename T>
T Stack<T>::pop() {
    assert(!IsEmpty());
    return array[top--];
}

template<typename T>
T Stack<T>::peek() {
    return array[top];
}

template<typename T>
Two_Stack<T>::Two_Stack(int size):size(size),top_1(-1),top_2(size) {
    if(size<2)
        size=2,top_2=size;
    array=new T (size);
}

template<typename T>
T Two_Stack<T>::peek(int id) {

    if(id==1) {
        assert(top_1!=-1);
        return array[top_1];
    }
    else {
        assert(top_2!=size);
        return array[top_2];
    }
}

template<typename T>
void Two_Stack<T>::push(int id, T val) {
    assert(!isFull());
    if(id==1)
        array[++top_1]=val;
    else
        array[--top_2]=val;
}

template<typename T>
bool Two_Stack<T>::isFull() {
    return top_2-top_1==1;
}
template<typename T>
T Two_Stack<T>::pop(int id) {

    if(id==1) {
        assert(top_1 != -1);
        return array[top_1--];
    }else{
        assert(top_2!=size);
        return array[top_2++];
    }
}

template<typename T>
Two_Stack<T>::~Two_Stack() {
    delete array;
}