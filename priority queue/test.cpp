//
// Created by Fatma on 10/30/2025.
//

#include <iostream>

#include "priorityMaxheap.h"
#include "Priority.h"
using namespace std;

int main(){

    /// Priority part
    priorityMaxheap<int> pq = priorityMaxheap<int>();
    pq.insert(1,1131);
    pq.insert(3,31111);
    pq.insert(2,2211);
    pq.insert(3,3161);
    pq.insert(7,7761);

    cout<<pq.pop()<<'\n';
    cout<<pq.pop()<<'\n';

    pq.insert(1,1535);
    pq.insert(2,2815);
    pq.insert(3,3845);
    pq.insert(3,3145);
    while(!pq.isEmpty())
        cout<<pq.pop()<<' ';

cout<<"////////////////////////////\n";
    /// Priority part
    Priority<int> p = Priority<int>();
    p.insert(1,1131);
    p.insert(3,31111);
    p.insert(2,2211);
    p.insert(3,3161);
    p.insert(7,7761);

    cout<<p.pop()<<'\n';
    cout<<p.pop()<<'\n';

    p.insert(1,1535);
    p.insert(2,2815);
    p.insert(3,3845);
    p.insert(3,3145);
    while(!p.isEmpty())
        cout<<p.pop()<<' ';



}