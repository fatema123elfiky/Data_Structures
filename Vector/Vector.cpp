//
// Created by Fatma on 1/26/2025.
//

#include "Vector.h"
#include "cassert"

// ========================= Implementation========================//


template<class T>
Vector<T>::Vector(int size ){
    if(size<0)
        size=0;
    this->size=size;
    capacity=10+size;
    arr=new int [capacity];
}

template<class T>
Vector<T>::~Vector() {

    delete [] arr;
    arr= nullptr;
}

template<class T>
int Vector<T>::get_size() {
    return size;
}

// trial
// return by reference to change if are gonna change by setting or just getting having the referenced value
template<class T>
T& Vector<T>::operator[](int x) {
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


template <class T>
ostream& operator<<(ostream& output ,const Vector<T>& vec){
    for (int i = 0; i < vec.size; ++i)
        output<<vec[i]<<' ';
    return  output;

}

template<class T>
void Vector<T>::Insert(T val, int idx) {

    assert(idx>=0&&idx<size);

    if(size==capacity)
        expand_capacity();

    size++;
    for (int i = size-1; i >idx ; --i)
        arr[i]=arr[i-1];

    arr[idx]=val;
}

template <class T>
void Vector<T>::Pop() {
    size--;
}

template <class T>
void Vector<T>::Pop(int idx) {
    assert(idx>=0&&idx<size);

    if(idx==size-1)
        Pop();
    else{
        for (int i = idx; i <size-1 ; ++i)
            arr[i]=arr[i+1];
        size--;
    }
}

template<class T>
void Vector<T>::Right_Rotate(int times) {
    times%=size;

    while (times--){
        T value=arr[size-1];
        Pop();
        Insert(value,0);
    }

}

template<class T>
void Vector<T>::Left_Rotate(int times) {

    times%=size;
    while (times--){
        T first_element=arr[0];
        for (int i = 1; i < size; ++i)
            arr[i-1]=arr[i];
        arr[size-1]=arr[0];
    }
}