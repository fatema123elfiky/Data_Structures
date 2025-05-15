//
// Created by Fatma on 5/10/2025.
//

#include "BST.h"
#include <queue>
#include <iostream>
using namespace std;

template<typename T>
BST<T>::BST(T data) :data(data){}

template<typename T>
bool BST<T>::search(T val) {//O(H)--> memo ,time
    if(val==data)
        return true;
    if(val<data)
        return left && left->search(val);
    return right && right->search(val);
}

template<typename T>
void BST<T>::insert(T val) {//O(H)--> memo ,time

    if(val<data){
        if(!left) {
            left = new BST(val);
            left->parent= this;
        }
        else
            left->insert(val);
    }else if(val>data){
       if(!right) {
           right = new BST(val);
           right->parent=this;
       }
       else
           right->insert(val);
    }
}

template<typename T>
bool BST<T>::Isearch(T val) {
   BST<T>* nodes=this ;
   while(nodes){

       if(nodes->data>val)
           nodes=nodes->left;
       else if(nodes->data<val)
           nodes=nodes->right;
       else
           return true;
   }
    return false;
}

template <typename T>
bool BST<T>::isBST(T MIN , T MAX) {
    bool status = data >MIN &&data <MAX;
    if(!status)
        return false;
    bool left_bst= !left || left->isBST(MIN,data);
    if(!left_bst)
        return false;
    bool right_bst = !right || right->isBST(data ,MAX);
    return right_bst;



}

template <typename T>
BST<T> *BST<T>::buildBST(vector<T> inorder, int start, int end) {
  if(end==-10)
      end=inorder.size()-1;
  if(start>end)
      return nullptr;
  int mid=(end+start)/2;
  T val = inorder[mid];
  BST<T> * node =new BST(val);
  node->left= buildBST(inorder,start ,mid-1);
  node->right= buildBST(inorder,mid+1 , end);
  if(end!=-10)// for modification in the structure modification
      node->left->parent=node , node->right->parent=node;
  return  node ;
}

template<typename T>
T BST<T>::MIN() { //O(H)
    BST<T>* node =this;
    while (node&&node->left)
        node=node->left;
    return node->data;
}

template<typename T>
pairs<T> BST<T>::successor(T target) {//o(h)
    BST<T> * child = search(target);
    if(!child)
        return pairs(false,-1);
    if(child->right)
        return pairs(true, child->right->MIN());
    BST<T> * Parent =child->parent;
    while (Parent&& Parent->right==child)
        child=Parent , Parent=child->parent;
    if(Parent)
        return pairs(true,Parent->data);
    return pairs(false,-1);
}

template<typename T>
BST<T> *BST<T>::min_node() {
    BST<T>* node = this;
    while (node&&node->left)
        node=node->left;
    return node;
}

template<typename T>
void BST<T>::delete_val(T target) {
    if(target==data&&!left&&!right)
        return; // as the only root as it will be self-destruction
    delete_node(target,this);
}

template<typename T>
BST<T> *BST<T>::delete_node(T target, BST<T> *node) {
    if(target<data)
        node->left= delete_node(target, node->left);
    else if(target>data)
        node->right= delete_node(target , node->right);
    else{
        BST<T>* temp = node;
        if(!node->left&&node->right)
            node= nullptr;
        else if( !node->left)
            node->special_delete(node->right),temp= nullptr;
        else if(!node->right)
            node->special_delete(node->left),temp= nullptr;
        else{
            BST<T>* mn =node->right->min_node();
            node->data=mn;
            node->right= delete_node(mn,node->right);
            temp=nullptr;
        }
        if(temp)
            delete temp;
    }
    return node;


}

template<typename T>
void BST<T>::special_delete(BST<T> *child) {
    data=child->data;
    left=child->left;
    right=child->right;
    delete child;

}