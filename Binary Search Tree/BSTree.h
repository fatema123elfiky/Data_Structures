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
public:
    void insert(T target);
    BSNode* delete_val(T target,BSNode* node);
    bool search (T target);

    bool isbst(BSNode * node);//
    void print_inorder();//
    void level_order();//

    BSNode* min_node(BSNode * node);
    void delete_value (T target);

};


#endif //SELF_DATASTRUCTURE_OWN_IMPLEMENTATION_BSTREE_H
