//
// Created by Fatma on 5/15/2025.
//

#include "BSTree.h"

template<typename T>
void BSTree<T>::insert(T target) {
    if(!root)
        root=new BSNode(target);
    else
        insert_node(target,root);
}

template<typename T>
bool BSTree<T>::Search(T target, BSTree::BSNode *node) {
    if(target==root->data)
        return true;
    else if(target<root->data)
        return Search(target,root->left);
    else if( target>root->data)
        return Search(target,root->right);
    return false;
}
template<typename T>
bool BSTree<T>::search(T target) {
    Search(target,root);
}
template<typename T>
void BSTree<T>::level_order() {}
template<typename T>
void BSTree<T>::print_inorder() {}

template<typename T>
void BSTree<T>::insert_node(T target, BSTree::BSNode *node) {
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
typename BSTree<T>::BSNode *BSTree<T>::min_node(BSNode * node) {

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
                node=node->right;
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

