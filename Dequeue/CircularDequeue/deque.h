//
// Created by Fatma on 5/6/2025.
//

#ifndef SELF_DATASTRUCTURE_OWN_IMPLEMENTATION_DEQUE_H
#define SELF_DATASTRUCTURE_OWN_IMPLEMENTATION_DEQUE_H

template<typename T>
class deque {
    private :
        int front{};
        int end{};
        int added_elements{};
        int sz{};
        T * arr;
        int next(int idx);
        int back(int idx);
    public:
        deque(int size);// O(1) --> time complex.

        void enqueue_back(T val);// O(1)--> time complex.
        T dequeue_front();// O(1)--> time complex.
        void enqueue_front(T val);// O(1)--> time complex.
        T dequeue_back();// O(1)--> time complex.

        bool isEmpty();// O(1)--> time complex.
        bool isFull();// O(1)--> time complex.
        void clear();// O(1)--> time complex.

        T Front();
        T Back();

        void display();

};


#endif //SELF_DATASTRUCTURE_OWN_IMPLEMENTATION_DEQUE_H
