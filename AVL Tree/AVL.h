//
// Created by Fatma on 5/15/2025.
//

#ifndef SELF_DATASTRUCTURE_OWN_IMPLEMENTATION_AVL_H
#define SELF_DATASTRUCTURE_OWN_IMPLEMENTATION_AVL_H

template<typename T>
class AVL {
private:
    struct AVLNode{
        T data{};
        int height{};
        AVLNode *left{};
        AVLNode *right{};

        //O(1)
        int ch_height(AVL *node);
        void update_height();
        int balance_factor();
        AVLNode(T data):data(data){}
    };
    AVLNode root{};

    //O(1)
    AVLNode* rightRotation(AVLNode * Q);
    AVLNode* leftRotation(AVLNode * P);
    AVLNode* balance(AVLNode* node);
    AVLNode* Insert(T target , AVLNode* node);
    AVLNode* Del(T target,AVLNode* node);
    AVLNode* Min(AVLNode*node);
public:
    void insert(T target);//O(LOG(N))
    void Delete(T target);
    T min();
};


#endif //SELF_DATASTRUCTURE_OWN_IMPLEMENTATION_AVL_H
