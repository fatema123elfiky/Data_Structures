//
// Created by Fatma on 11/4/2025.
//

#ifndef SELF_DATASTRUCTURE_OWN_IMPLEMENTATION_RBTREE_H
#define SELF_DATASTRUCTURE_OWN_IMPLEMENTATION_RBTREE_H



template<typename T>
struct Node{
    T data{};
    Node * left {};
    Node *right{};
    Node *parent{};
    char  color;// 0 --> black , 1 -->red
    Node(T data):data(data),color(1){}
};

template<typename T>
class RBTree {
private:
    Node<T> * root{};
    Node<T> *NIL{};
    void FixInsertion(Node<T>*node);//
    Node<T> * leftRotation(Node<T> *P);//
    Node<T> * rightRotation(Node<T> *Q);//

public :
    RBTree();//
    Node<T>* search(T data);//
    void insert(T data);//
    void Delete(T data);
    ~RBTree();
};


#endif //SELF_DATASTRUCTURE_OWN_IMPLEMENTATION_RBTREE_H
