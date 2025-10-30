//
// Created by Fatma on 10/30/2025.
//

#ifndef SELF_DATASTRUCTURE_OWN_IMPLEMENTATION_PRIORITY_H
#define SELF_DATASTRUCTURE_OWN_IMPLEMENTATION_PRIORITY_H
#include "../Binary Heap/MaxHeap/MaxHeap.h"
template<typename T>
class Priority {

    public:
        struct Pair{
            int key;
            T value;
            bool operator > (const Pair& b){
                if(this->key > b.key) return true;
                return false;
            }
            bool operator < (const Pair& b) {
                if(this->key < b.key) return true;
                return false;
            }
            bool operator >= (const Pair& b) {
                if(this->key >= b.key) return true;
                return false;
            }
            bool operator <= (const Pair& b) {
                if(this->key <= b.key) return true;
                return false;
            }
            Pair& operator = (const Pair& b) {
                this->key=b.key;
                this->value=b.value;
                return *this;
            }

        };
        Priority()=default;
        void insert (int key,T value );
        T pop ();
        bool isEmpty();
        ~Priority()=default;

    private:
        MaxHeap<Pair> heap;
        int size{};




};

#include "Priority.tpp"
#endif //SELF_DATASTRUCTURE_OWN_IMPLEMENTATION_PRIORITY_H
