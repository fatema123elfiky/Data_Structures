//
// Created by Fatma on 5/6/2025.
//

#ifndef SELF_DATASTRUCTURE_OWN_IMPLEMENTATION_QUEUE_H
#define SELF_DATASTRUCTURE_OWN_IMPLEMENTATION_QUEUE_H


// Circular queue //

template<typename T>
class queue {
private :
    int front{};
    int end{};
    int added_elements{};
    int sz{};
    T * arr;
    int next(int idx);
public:
    queue(int sz);// O(1) --> time complex.
    void enqueue(int val);// O(1)--> time complex.
    T dequeue();// O(1)--> time complex.
    bool isEmpty();// O(1)--> time complex.
    bool isFull();// O(1)--> time complex.
    void clear();// O(1)--> time complex.


};


#endif //SELF_DATASTRUCTURE_OWN_IMPLEMENTATION_QUEUE_H
