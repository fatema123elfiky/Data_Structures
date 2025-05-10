//
// Created by Fatma on 5/10/2025.
//

#ifndef SELF_DATASTRUCTURE_OWN_IMPLEMENTATION_BINARYTREE_H
#define SELF_DATASTRUCTURE_OWN_IMPLEMENTATION_BINARYTREE_H

#include <vector>

using namespace std;

template<typename T>
class Binarytree {
private:
   T data{};
    Binarytree * left{};
    Binarytree * right{};
    T MAX (Binarytree<T> * node);
public:
    Binarytree(T val):data(val){}
    void add (vector<T>val,vector<char>direction);
    T tree_max();
    int height();
    int nodes();
    int leafNode();
    bool isExist(T val);
    void levelPrint();
};


#endif //SELF_DATASTRUCTURE_OWN_IMPLEMENTATION_BINARYTREE_H
