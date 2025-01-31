//
// Created by Fatma on 1/31/2025.
//

#ifndef SELF_DATASTRUCTURE_SINGLY_LINKED_LIST_H
#define SELF_DATASTRUCTURE_SINGLY_LINKED_LIST_H

#include <iostream>
#include <vector>
using namespace std;

template  <class T>
struct Node{
    T data{};
    Node*next{};

    Node(T data){this->data=data;}
    ~Node(){cout<<"The Node "<<this<<" with data "<<data<<" is destructed\n";}
};

template  <class T>
class Singly_Linked_List {

private:

   Node<T> * head{};
   Node<T> *tail{};
   int length{};

   // for debug purpose
   vector<Node<T>*> debug_vec;

   void delete_node(Node<T> *node);//
   void add_node(Node<T> *node);//

   // for debug purpose
   void add_debug(Node<T>* node);//
   void remove_debug(Node<T>* node);//

public:

    Singly_Linked_List()=default;

    void print();//
    void insert_back(T val);//
    void insert_front(T val);//
    void insert(T val,int idx);//-->
    int search(T val);//

    /** The idea of the function to get the node in the index n and of time O(N) and memory O(1)
     * parameter is the index and one based
     * return is the Node itself
     **/
    Node<T>* get_nth(int n);//

    void delete_first();//
    void delete_last();//

    /** The idea of the function is deleting the nth node also one based its time of O(N) and memory O(1)
     * parameter is the index only
     * there is no return
     **/
    void delete_nth(int n);//

    /** the idea is to delete the node after the passed one its time of O(1) and memory of O(1)
     * the parameter is the prev node to delete the next one to it
     * there is no return
     **/
    void delete_nxt(Node<T>*prev);//

    /** the idea is to compare between two lists weather they are equal to each other or not
     * the parameter is the second list to compare with
     * the return is the boolean weather is false or true
     * */
    bool is_same(const Singly_Linked_List<T> & list);//

    /** Preventing the copy constructor and the assignment operator */
    Singly_Linked_List(const Singly_Linked_List<T> &)=delete;
    Singly_Linked_List& operator=(const Singly_Linked_List<T> &)=delete;

    ~Singly_Linked_List();//

};


#endif //SELF_DATASTRUCTURE_SINGLY_LINKED_LIST_H
