//
// Created by Fatma on 5/10/2025.
//

#ifndef SELF_DATASTRUCTURE_OWN_IMPLEMENTATION_BST_H
#define SELF_DATASTRUCTURE_OWN_IMPLEMENTATION_BST_H


#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class BST {
private:
    T data{};
    BST * left{};
    BST * right{};
public:
    BST(T data);
    bool search(T val);
    void insert(T val);
    bool Isearch(T val);
    bool isBST(T MIN=INT_MIN , T MAX=INT_MAX);
    BST<T>* buildBST(vector<T> inorder , int start=0 , int end=-10);
};


#endif //SELF_DATASTRUCTURE_OWN_IMPLEMENTATION_BST_H
