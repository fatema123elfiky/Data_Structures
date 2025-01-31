//
// Created by Fatma on 1/26/2025.
//

#ifndef SELF_DATASTRUCTURE_VECTOR_H
#define SELF_DATASTRUCTURE_VECTOR_H
#include <iostream>
using namespace std;

template <class T>

class Vector {
private:
    T *arr= nullptr;
    int size=0;
    int capacity=10;
    void expand_capacity();
public:
    Vector(int size=0 );
    ~Vector();
    int get_size();

    T& operator[](int x);// for getting and setting value
    T* find (T val);
    T Front();
    T Back();
    void Push_back(T x);

    void Insert(T val);
    void Right_Rotate(int times);
    void Left_Rotate(int times);
    void Delete(int index);
    void Pop();
};












#endif //SELF_DATASTRUCTURE_VECTOR_H
