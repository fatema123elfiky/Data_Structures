//
// Created by Fatma on 5/10/2025.
//

#ifndef SELF_DATASTRUCTURE_OWN_IMPLEMENTATION_BST_H
#define SELF_DATASTRUCTURE_OWN_IMPLEMENTATION_BST_H


#include <iostream>
#include <vector>


using namespace std;
template<typename T>
struct pairs{
    bool boolean{};
    T data{};
    pairs(bool boolean , T data):boolean(boolean),data(data){}
};
template<typename T>
class BST {
private:
    T data{};
    BST<T> * left{};
    BST<T> * right{};
    BST<T> * parent{};
    BST<T>* min_node();
    void special_delete(BST<T>* child);
public:
    BST(T data);//
    bool search(T val);//
    void insert(T val);//
    bool Isearch(T val);
    bool isBST(T MIN=INT_MIN , T MAX=INT_MAX);
    BST<T>* buildBST(vector<T> inorder , int start=0 , int end=-10);
    T MIN();
    pairs<T> successor(T target);
    void delete_val (T target);//
    BST<T> * delete_node(T target , BST<T>* node);

};


#endif //SELF_DATASTRUCTURE_OWN_IMPLEMENTATION_BST_H
