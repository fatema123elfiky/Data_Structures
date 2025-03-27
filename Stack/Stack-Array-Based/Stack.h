//
// Created by Fatma on 3/27/2025.
//

#ifndef SELF_DATASTRUCTURE_OWN_IMPLEMENTATION_STACK_H
#define SELF_DATASTRUCTURE_OWN_IMPLEMENTATION_STACK_H

template<typename T>
class Stack {
private:
    int size{};
    int top{};
    T * array{};
public:
    Stack(int size);
    bool IsFull();
    bool IsEmpty();
    void push(T val);
    T pop();
    T peek();
    ~Stack();

};

template<typename T>
class Two_Stack{
private:
    int size{};
    int top_1{};
    int top_2{};
    T * array{};
public:
    Two_Stack(int size);
    void push(int id , T val);
    T pop(int id);
    T peek(int id);
    bool isFull();
    ~Two_Stack();

};


#endif //SELF_DATASTRUCTURE_OWN_IMPLEMENTATION_STACK_H
