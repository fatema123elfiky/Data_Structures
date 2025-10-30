//
// Created by Fatma on 10/30/2025.
//

#include <iostream>
#include <vector>
#include "priorityMaxheap.h"
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
}