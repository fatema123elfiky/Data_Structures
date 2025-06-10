//
// Created by Fatma on 5/15/2025.
//

#include "BSTree.h"
#include <iostream>
#include <queue>
using namespace std;

template<typename T>
void BSTree<T>::insert(T target) {
    if(!root)
        root=new BSNode(target);
    else
        insert_node(target,root);
}

template<typename T>
bool BSTree<T>::Search(T target, BSTree::BSNode *node) {

    if(!node)
        return false;
    if(target==node->data)
        return true;
    else if(target<node->data)
        return Search(target,node->left);
    else if( target>node->data)
        return Search(target,node->right);

}
template<typename T>
bool BSTree<T>::search(T target) {
    Search(target,root);
}
template<typename T>
void BSTree<T>::inorder(BSTree::BSNode *node) {
    if(!node)
        return;
    inorder(node->left);
    cout<<node->data<<' ';
    inorder(node->right);
}
template<typename T>
void BSTree<T>::level_order() {
    queue<BSNode*> nodes;
    nodes.push(root);
    while (!nodes.empty()){
        BSNode * node = nodes.front();
        nodes.pop();
        cout<<node->data<<' ';
        if(node->left)
            nodes.push(node->left);
        if(node->right)
            nodes.push(node->right);
    }
}
template<typename T>
void BSTree<T>::print_inorder() {
    inorder(root);
}

template<typename T>
void BSTree<T>::insert_node(T target, BSTree::BSNode *node) {
    if(!root)
       return void( root =new BSNode(target));

    if(target<node->data){
        if(!node->left)
            node->left=new BSNode(target);
        else
            insert_node(target,node->left);

    }else if(target>node->data){
        if(!node->right)
            node->right= new BSNode (target);
        else
            insert_node(target,node->right);
    }
}
template<typename T>
typename BSTree<T>::BSNode *BSTree<T>::min_node(BSTree::BSNode * node) {

    while (node&&node->left)
        node=node->left;
    return node;
}

template<typename T>
typename BSTree<T>::BSNode * BSTree<T>::delete_val(T target, BSTree::BSNode *node) {
        if(!node)
            return nullptr;
        if(target<node->data)
            node->left= delete_val(target,node->left);
        else if(target>node->right)
            node->right= delete_val(target,node->right);
        else{
            BSNode * temp = node;
            if(!node->left&&!node->right)
                node= nullptr;
            else if( !node->left)
                node=node->right;
            else if(!node->right)
                node=node->left;
            else{
                BSNode * mn = min_node(node->right);
                node->data=mn->data;
                node->right= delete_val(mn->data,node->right);
                temp= nullptr;
            }
            if(temp)
                delete temp;

        }
    return node;

}

template<typename T>
void BSTree<T>::delete_value(T target) {
    if(root)
        root= delete_val(target,root);

}
template<typename T>
bool BSTree<T>::isbst(BSTree::BSNode *node) {
    bool leftbst = !node->left || (node->data>node->left->data && isbst(node->left));

    if(!leftbst)
        return leftbst;

    bool rightbst =!node->right || (node->data < node->right->data && isbst(node->right));
    return rightbst;
}

template<typename T>
int BSTree<T>::height(BSTree::BSNode *node) {
    if(!node)
        return 0;
    return 1 + max (height(node->left), height(node->right));
}

template<typename T>
int BSTree<T>::countN(BSTree::BSNode *node) {
    if(!node)
        return 0;
    int res =0;
    res+= countN(node->left);
    res+= countN(node->right);
    return res;
}

template<typename T>
int BSTree<T>::countNodes() {
    return countN(root);
}

template<typename T>
int BSTree<T>::Height() {
    return height(root);
}

template <typename T>
int BSTree<T>::countLeaves() {
   return countL(root);
}

template<typename T>
int BSTree<T>::countL(BSTree::BSNode *node) {
    if(!node->left&&!node->right)
        return 1;
    int res =0;
    res+= countL(node->left);
    res+= countL(node->right);
    return res;
}
