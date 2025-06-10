//
// Created by Fatma on 5/15/2025.
//

#include "AVL.h"
#include <iostream>

using namespace std;

template<typename T>
int AVL<T>::ch_height(AVL<T> *node) {
    if(!node)
        return -1;
    return node->height;
}

template<typename T>
void AVL<T>::update_height() {
    height=1+max(ch_height(left), ch_height(right));
}

template<typename T>
int AVL<T>::balance_factor() {
    return ch_height(left)- ch_height(right);
}