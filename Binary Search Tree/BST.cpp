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
        if(!left)
            left=new BST(val);
        else
            left->insert(val);
    }else if(val>data){
       if(!right)
           right=new BST (val);
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
    return  node ;
}