/*
* Title : Heaps and AVL Trees
* Author : Ali Eren Günaltýlý
* ID : 21801897
* Section : 01
* Assignment : 3
* Description : MinHeap header
*/

#include <iostream>
#include <string.h>
using namespace std;

#pragma once
class MinHeap
{
public:
	MinHeap();
	void insert(int value); // inserts integer into heap
	int peek(); // returns the value of the max element
	int extractMin(); // retrieves and removes the max element
	int size(); // returns the number of elements in the heap
	void print();
private:
	int Size;
	int arr[100];
	int constSize;
	void rebuild(int root);
};

