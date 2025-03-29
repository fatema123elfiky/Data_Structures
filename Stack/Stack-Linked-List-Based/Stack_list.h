//
// Created by Fatma on 3/29/2025.
//

#ifndef SELF_DATASTRUCTURE_OWN_IMPLEMENTATION_STACK_LIST_H
#define SELF_DATASTRUCTURE_OWN_IMPLEMENTATION_STACK_LIST_H


/// It is dynamic stack
template<typename T>
class Stack_list {

private:
    struct Node{
        T data{};
        Node * next{};
        Node (int data):data(data){}
    };
    Node * head{};
    void copyStructures(const Stack_list<T>& stack);
public:
    Stack_list();
    void push(T val);
    T pop();
    T peek();
    bool isEmpty();
    Stack_list(const Stack_list<T>& stack);
    Stack_list<T>& operator=(const Stack_list<T>&stack);

};


#endif //SELF_DATASTRUCTURE_OWN_IMPLEMENTATION_STACK_LIST_H
