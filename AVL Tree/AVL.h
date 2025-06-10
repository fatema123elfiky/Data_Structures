//
// Created by Fatma on 5/15/2025.
//

#ifndef SELF_DATASTRUCTURE_OWN_IMPLEMENTATION_AVL_H
#define SELF_DATASTRUCTURE_OWN_IMPLEMENTATION_AVL_H

template<typename T>
class AVL {
private:
    T data{};
    int height{};
    AVL *left{};
    AVL *right{};

    int ch_height(AVL * node);
    void update_height();
    int balance_factor();
};


#endif //SELF_DATASTRUCTURE_OWN_IMPLEMENTATION_AVL_H
