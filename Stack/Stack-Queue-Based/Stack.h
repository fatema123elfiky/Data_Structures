//
// Created by Fatma on 5/6/2025.
//

#ifndef SELF_DATASTRUCTURE_OWN_IMPLEMENTATION_STACK_H
#define SELF_DATASTRUCTURE_OWN_IMPLEMENTATION_STACK_H
#include "../../Queue/QueueCircular/queue.h"
template<typename T>
class Stack {

    private:
        int added_elements{};
        queue<T> data;
        void insertfront(T val );
    public:
        Stack(int size);
        bool IsFull();
        bool IsEmpty();
        void push(T val);
        T pop();
        T peek();
        ~Stack();


};


#endif //SELF_DATASTRUCTURE_OWN_IMPLEMENTATION_STACK_H
