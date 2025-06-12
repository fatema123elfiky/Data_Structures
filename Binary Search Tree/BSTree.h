//
// Created by Fatma on 5/15/2025.
//

#ifndef SELF_DATASTRUCTURE_OWN_IMPLEMENTATION_BSTREE_H
#define SELF_DATASTRUCTURE_OWN_IMPLEMENTATION_BSTREE_H


template<typename T>
class BSTree {
private:
    struct BSNode{
        T data{};
        BSNode* left{};
        BSNode* right{};
        BSNode(T data):data(data){}
    };
    BSNode * root{};
    void insert_node(T target , BSNode * node);
    bool Search(T target,BSNode * node);
    void inorder (BSNode * node);
    int countN(BSNode * node);
    int countL(BSNode * node);
    int height(BSNode * node);
public:

    void insert(T target);// log n , n
    BSNode* delete_val(T target,BSNode* node);// log n , n
    bool search (T target);// log n , n

    bool isbst(BSNode * node);
    void print_inorder();//n
    void level_order();

    BSNode* min_node(BSNode* node);// log n , n
    void delete_value (T target);
    int countNodes();// n
    int countLeaves();// n
    int Height();// n

};


#endif //SELF_DATASTRUCTURE_OWN_IMPLEMENTATION_BSTREE_H
