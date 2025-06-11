//
// Created by Fatma on 5/15/2025.
//

#include "AVL.h"
#include <iostream>

using namespace std;

template<typename T>
int AVL<T>::AVLNode::ch_height(AVL<T> *node) {
    if(!node)
        return -1; //if child is null
    return node->height; // 0 for leaf node
}

template<typename T>
void AVL<T>::AVLNode::update_height() {
    height=1+max(ch_height(left), ch_height(right));
}

template<typename T>
int AVL<T>::AVLNode::balance_factor() {
    return ch_height(left)- ch_height(right);
}

template<typename T>
typename AVL<T>::AVLNode *AVL<T>::rightRotation(AVL::AVLNode *Q) {// o(1)
    AVLNode * p = Q->left;
    Q->left=p->right;
    p->right=Q;
    Q->update_height();// take care of the order as that became child
    p->update_height();
    return p;
}

template<typename T>
typename AVL<T>::AVLNode *AVL<T>::leftRotation(AVL::AVLNode *P) {// o(1)
    AVLNode * Q = P->right;
    P->right=Q->left;
    Q->left=P;
    P->update_height();// take care of the order as that became child
    Q->update_height();
    return Q;
}

/** four cases for imbalance and the main reason is that
* the balance factor = +-2 but these are the ways of equal two
* LL ->single right rotation
* LR ->double left right
* RR ->single left rotation
* RL ->double right left
* everyone has a way to handle
**/
template<typename T>
typename AVL<T>::AVLNode *AVL<T>::balance(AVL::AVLNode *node) {
    if(node->balance_factor()==2){//left
        if(node->left->balance_factor()==-1)
            node->left= leftRotation(node->left);
        node= rightRotation(node);
    }else if(node->balance_factor()==-2){//right
       if(node->right->balance_factor()==1)
           node->right= rightRotation(node->right);
       node= leftRotation(node);
    }
    return node;
}

template<typename T>
void AVL<T>::insert(T target) {
    if(!root)
        root = new AVLNode(target);
    else
        root=Insert(target,root);
}


template<typename T>
typename AVL<T>::AVLNode *AVL<T>::Insert(T target, AVL::AVLNode *node) {
    if(target<node->left){
        if(!node->left)
            node->left= new AVLNode(target);
        else
            node->left= Insert(target,node->left);
    }else if(target>node->right){
        if(!node->right)
            node->right=new AVLNode(target);
        else
            node->right= Insert(target,node->right);
    }
    node->update_height();
    return balance(node);
}

template<typename T>
void AVL<T>::Delete(T target) {
    if(root)
        root= Del(target,root);
}

template<typename T>
typename AVL<T>::AVLNode *AVL<T>::Del(T target, AVL::AVLNode *node) {
    if(!node)
        return nullptr;
    if(target<node->data)
        node->left= Del(target,node->left);
    else if (target>node->data)
        node->right= Del(target,node->right);
    else{
        AVLNode* temp =node;
        if(!node->left&&!node->right)
            node= nullptr;
        else if(!node->left)
            node=node->right;
        else if(!node->right)
            node=node->left;
        else{
            AVLNode * mn= Min(node->right) ;
            node->data=mn->data;
            node->right= Del(mn,node->right);
            temp = nullptr;
        }
        if(temp)
            delete temp;
    }
    node->update_height();
    return balance(node);

}

template<typename T>
typename AVL<T>::AVLNode *AVL<T>::Min(AVL::AVLNode *node) {
    AVLNode* avlNode = node;
    while (avlNode&&avlNode->left)
        avlNode=avlNode->left;
    return avlNode;
}
template<typename T>
T AVL<T>::min() {
    return Min()->data;
}