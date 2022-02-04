/*
* Title : Heaps and AVL Trees
* Author : Ali Eren Günaltılı
* ID : 21801897
* Section : 01
* Assignment : 3
* Description : main.cpp for testing max, min and median heaps
*/


#include <iostream>
#include "MaxHeap.h"
#include "MinHeap.h"
#include "MedianHeap.h"

int main()
{
    MaxHeap heap;
    heap.insert(11);
    heap.insert(19);
    heap.insert(7);
    heap.insert(5);
    heap.insert(32);
    heap.insert(16);
    heap.insert(64);
    heap.print();
    cout << "MaxHeap peek " << heap.peek() << endl;
    cout << "Extracted max " << heap.extractMax() << endl;
    cout << "After Extraction " << endl;
    heap.print();

    MinHeap minHeap;
    minHeap.insert(11);
    minHeap.insert(19);
    minHeap.insert(7);
    minHeap.insert(5);
    minHeap.insert(32);
    minHeap.insert(16);
    minHeap.insert(64);
    minHeap.print();
    cout << "MinHeap peek " << minHeap.peek() << endl;
    cout << "Extracted min " << minHeap.extractMin() << endl;
    cout << "After Extraction " << endl;
    minHeap.print();

    cout << "------Median---Heap------" << endl;
    MedianHeap med;
    med.insert(14);
    med.insert(3);
    med.insert(19);
    med.insert(6);
    med.insert(1);
    med.insert(20);
    med.insert(9);
    cout << med.findMedian() << endl;
}