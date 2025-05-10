//
// Created by Fatma on 5/10/2025.
//

#include "Binarytree.h"
#include <cassert>
#include <queue>
#include <iostream>

template<typename T>
void Binarytree<T>::add (vector<T>val,vector<char>direction){
    assert(val.size()==direction.size());
    Binarytree * curr =this;
    for (int i = 0; i < val.size(); ++i) {
        if(direction[i]=='L'){
            if(!curr->left)
                curr->left =new Binarytree(val[i]);
            else
                assert(curr->left->data==val[i]);
            curr=curr->left;

        }else{
            if(!curr->right)
                curr->right=new Binarytree(val[i]);
            else
                assert(curr->right->data==val[i]);
            curr=curr->right;
        }
    }
}

template<typename T>
T Binarytree<T>:: tree_max(){
    return MAX(this);
}

template<typename T>
T Binarytree<T>:: MAX (Binarytree<T> * node){

    T count=node->data;
    if(node->left)
        count = max(count,MAX(node->left));
    if(node->right)
        count = max(count,MAX(node->right));

    return count;

}

template<typename T>
int Binarytree<T>::height() {
    int res =0;
    if(left)
        res=max(res,left->height()+1);
    if(right)
        res=max(res,right->height()+1);
    return res;
}

template<typename T>
int Binarytree<T>::nodes() {
    int res=1;
    if(left)
        res+=left->nodes();
    if(right)
        res+=right->nodes();
    return res;
}

template<typename T>
int Binarytree<T>::leafNode() {
    int res=0;
    if(left)
        res+=left->leafNode();
    if(right)
        res+=right->leafNode();
    return res+(!left&&!right);

}

template<typename T>
bool Binarytree<T>::isExist(T val) {

    bool res = val==data;
    if(!res &&left)
        res=left->isExist(val);
    if(!res&&right)
        res=right->isExist(val);
    return res;
}

template<typename T>
void Binarytree<T>::levelPrint() {
    queue<Binarytree<T> *> nodes;
    nodes.push(this);
    while (!nodes.empty()){
        Binarytree<T> * node =nodes.front();
        nodes.pop();
        cout<<nodes->data<<' ';
        if(node->left)
            nodes.push(node->left);
        if(nodes->right)
            nodes.push(nodes->right);

    }
    cout<<'\n';
}

