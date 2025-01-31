//
// Created by Fatma on 1/31/2025.
//

#include "Singly_Linked_List.h"
#include <cassert>

template<class T>
void Singly_Linked_List<T>::print(){

    for (Node<T> * cur = head; cur ; cur=cur->next) {
        cout<<cur<<data<<' ';
    }
    cout<<'\n';

}

template<class T>
void Singly_Linked_List<T>::insert_back(T val){

    Node<T>*item=new Node (val);
    add_node(item);

    if(length==1){
        head=tail=item;
    }else{
         tail->next=item;
         tail=item;
    }
}

template<class T>
void Singly_Linked_List<T>::insert_front(T val){

    Node<T>*item=new Node(val);
    add_node(item);

    if(length==1)
        head=tail=item;
    else{
        item->next=head;
        head=item;
    }

}

template<class T>
void Singly_Linked_List<T>::add_node(Node<T> *node) {

    length++;
    add_debug(node);

}

template<class T>
void Singly_Linked_List<T>::add_debug(Node<T> *node) {
    debug_vec.push_back(node);
}

template<class T>
void Singly_Linked_List<T>:: insert(T val,int idx){

    if(idx>length||idx<=0)
        return ;

    if(idx==1){
        insert_front(val);
    }else if(idx==length){
        insert_back(val);
    }else{

        Node<T>*node=new Node(val);
        Node<T>*prev= get_nth(idx-1);
        node->next=prev->next;
        prev->next=node;
        add_debug(node);
    }




}

template<class T>
Node<T>* Singly_Linked_List<T>::get_nth(int n){

    if(n<=0||n>length)
        return nullptr;

    int cntr=0;
    for (Node<T>* node = head; node  ; node=node->next) {
        if(++cntr==n)
            return node;
    }
}

template<class T>
int Singly_Linked_List<T>::search(T val){

    int cntr=1;

    for (Node<T>* node = head; node ; cntr++,node=node->next) {
        if(node->data==val)
            return cntr;
    }

    return -1;
}

template<class T>
void Singly_Linked_List<T>::delete_first(){

    if(!length)
        return;

    Node<T>*cur=head;
    head=head->next;

    delete_node(cur);

    if (!head)
        tail = nullptr;

}

template<class T>
void Singly_Linked_List<T>::delete_node(Node<T> *node){

    length--;
    remove_debug(node);
    delete node;

}

template<class T>
void Singly_Linked_List<T>::remove_debug(Node<T>* node){

    auto it=find(debug_vec.begin(),debug_vec.end(),node);

    if (it == debug_vec.end())
        cout << "Node does not exist\n";
    else
        debug_vec.erase(it);

}

template<class T>
void Singly_Linked_List<T>::delete_last(){

    if(head){

        if(!head->next){
            delete_first();
        }else{
            Node<T> * prev= get_nth(length-1);
            prev->next= nullptr;
            delete_node(tail);
            tail=prev;
        }


    }
}

template<class T>
Singly_Linked_List<T>::~Singly_Linked_List(){

    for (Node<T>* cur = head,*prev=head; cur ; ) {
        cur=cur->next;
        delete prev;
        prev=cur;
    }

}

template<class T>
bool Singly_Linked_List<T>::is_same(const Singly_Linked_List<T> & list){

    Node<T>* first,*second ;

    for( first=head,  second=list.head ; first&&second ; second=second->next,first=first->next) {
        if(first->data!=second->data)
            return false;
    }

    return !first && !second;
}

template <class T>
void Singly_Linked_List<T>::delete_nxt(Node<T>* prev){


    if(!prev||prev==tail)
        assert(false);

    Node<T>* nxt= prev->next;
    prev->next=nxt->next;

    bool Tail = (nxt==tail);
    delete_node(nxt);

    if(Tail)
        tail=prev;
}

template <class T>
void Singly_Linked_List<T>::delete_nth(int n){

    if(n<=0||n>length)
        assert(false);

    if(n==1)
        delete_first();
    else if(n==length)
        delete_last();
    else{
        Node<T>*prev= get_nth(n-1);
        delete_nxt(prev);
    }

}
