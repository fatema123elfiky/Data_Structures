//
// Created by Fatma on 1/26/2025.
//

#include "Vector.h"


// ========================= Implementation========================//


template<class T>
Vector<T>::Vector(int size ){
    if(size<0)
        size=0;
    this->size=size;
    arr=new int [capacity];
}

template<class T>
Vector<T>::~Vector() {
    delete [] arr;
}

template<class T>
int Vector<T>::get_size() {
    return size;
}

// trial
// return by reference to change if are gonna change by setting or just getting having the referenced value
template<class T>
T &Vector<T>::operator[](int x) {
    return arr[x];
}

template<class T>
T Vector<T>::Front() {
    return arr[0];
}

template<class T>
T Vector<T>::Back() {
    return arr[size-1];
}

template<class T>
void Vector<T>::Push_back(T x) {

    if(size==capacity){
        expand_capacity();
    }
    arr[size++]=x;
}

// that find function is linear
// we could make it better or change it to better algo soon
template <class T>
T *Vector<T>::find(T val) {
    for (int i = 0; i < size; ++i) {
        if(arr[i]==val)
            return arr+i;
    }
    return arr+size;
}



template<class T>
void Vector<T>::expand_capacity() {
    capacity*=2;
    int *arr2 = new int[capacity];
    for (int i = 0; i < size; ++i) {
        arr2[i]=arr;
    }
    swap(arr,arr2);
    delete [] arr2;
}


