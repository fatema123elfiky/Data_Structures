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
//
// Created by Fatma on 3/29/2025.
//

#include "Stack_list.h"

template<typename T>
Stack_list<T>::Stack_list():head(nullptr) {}

template<typename T>
T Stack_list<T>::peek() {
    assert(!isEmpty());
    return head->data;
}

template<typename T>
bool Stack_list<T>::isEmpty() {
    return !head;
}

template<typename T>
void Stack_list<T>::push(T val) {
    Node * item =new Node(val);
    item->next=head;
    head=item;
}

template<typename T>
T Stack_list<T>::pop() {
    assert(!isEmpty());
    T value = head->data;
    Node * temp = head;
    head=head->next;
    delete temp;
    return value;
}

template<typename T>
Stack_list<T>::Stack_list(const Stack_list<T> &stack) {
    head= nullptr;
    copyStructures(stack);
}

template<typename T>
Stack_list<T>& Stack_list<T>::operator=(const Stack_list<T>&stack) {
    if(this==&stack)
        return *this;

    while (!isEmpty())
        pop();

    head= nullptr;

    copyStructures(stack);
    return this;
}


template<typename T>
void Stack_list<T>::copyStructures(const Stack_list<T> &stack) {

    if(stack.head) {
        Node *curr = stack.head;
        head= new Node(curr->data);
        Node * last =head;
        curr=curr->next;

        while (curr) {
            Node *NewNode=new Node(curr->data);
            last->next=NewNode;
            last=NewNode;
            curr = curr->next;
        }
        last->next= nullptr;
    }
}



#endif //SELF_DATASTRUCTURE_OWN_IMPLEMENTATION_STACK_LIST_H
