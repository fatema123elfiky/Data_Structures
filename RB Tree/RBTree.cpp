//
// Created by Fatma on 11/4/2025.
//

#include "RBTree.h"


template<typename T>
Node<T>* RBTree<T>::rightRotation(Node<T> *Q) {// o(1)
    Node<T> * p = Q->left;
    Q->left=p->right;
    p->right=Q;

    return p;
}

template<typename T>
Node<T>* RBTree<T>::leftRotation(Node<T> *P) {// o(1)
    Node<T> * Q = P->right;
    P->right=Q->left;
    Q->left=P;

    return Q;
}



template<typename T>
RBTree<T>::RBTree() {
    NIL = new Node<T>();
    this->NIL->color=0;
    root=NIL;
}

template<typename T>
Node<T> *RBTree<T>::search(T data) {
    Node<T> * node = root;
    while (node!=NIL){
        if(node->data > data)
            node=node->left;
        else if(node->data < data)
            node=node->right;
        else
            return node;
    }
    return nullptr;
}

template<typename T>
void RBTree<T>::insert(T data) {

    //new node
    Node<T> * New = new Node<T>(data);
    New->left=New->right=NIL;

    //Case of root
    if(root==NIL) {
        root = New;
        root->color=0;
        return;
    }


    //Iterators
    Node<T> * prev = nullptr;
    Node<T> * node = root;

    while (node!=NIL){
        prev=node;
        if(node->data > data)
            node=node->left;
        else if(node->data < data)
            node=node->right;
    }

    //Parent and children insertion
    New->parent=prev;
    if(prev->data>data)
        prev->left=New;
    else
        prev->right=New;

    //Checking cases
    FixInsertion(New);

}

template<typename T>
void RBTree<T>::FixInsertion(Node<T> *node) {

    //First check for parent
    if(!node->color||node==root)
        return;
    else{
        // Check uncle
        Node<T> * parent = node->parent;
        Node<T> * grand  = parent->parent;
        Node<T> * Uncle ;

        if(grand->left==parent) {
            Uncle = grand->right;

            //Uncle red or black
            if(!Uncle->color){
                if(parent->right ==node)//left right
                    parent=leftRotation(parent);
                grand->color=1,parent->color=0;
                grand=rightRotation(grand);

            }else{
                parent->color=Uncle->color=0;
                grand->color=1;
                FixInsertion(grand);
            }
        }else {
            Uncle = grand->left;
            //Uncle red or black
            if(!Uncle->color){
                if(parent->left == node)
                    parent=rightRotation(parent);
                grand->color=1,parent->color=0;
                grand= leftRotation(grand);

            }else{
                parent->color=Uncle->color=0;
                grand->color=1;
                FixInsertion(grand);
            }
        }


    }
}
