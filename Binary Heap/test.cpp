//
// Created by Fatma on 10/30/2025.
//
#include "MaxHeap/MaxHeap.h"
#include <iostream>
#include <vector>

using namespace std;

int main(){

    /// Heap part
    MaxHeap<int>heap= MaxHeap<int>();
    int* arr1 = new int [4]{10,-1,8,5};
    vector<int>v{1,2,8,-1,10,-5,20};
    for (int i = 0; i < v.size(); ++i)
        heap.push(v[i]);
    cout<<heap.top()<<'\n';
    cout<<heap.pop()<<'\n';
    cout<<heap.Min()<<'\n';
    cout<<heap.ExtractMin()<<'\n';
    for (int i = 0; i < 4; ++i)
        cout<<arr1[i]<<' ';
    heap.HeapSort(arr1,4);
    cout<<'\n';
    for (int i = 0; i < 4; ++i)
        cout<<arr1[i]<<' ';
    cout<<'\n';
    while(!heap.isEmpty())
        cout<<heap.pop()<<' ';

    /// Priority part


}