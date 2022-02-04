/*
* Title : Heaps and AVL Trees
* Author : Ali Eren Günaltýlý
* ID : 21801897
* Section : 01
* Assignment : 3
* Description : Median Heap header
*/

#include <iostream>
#include <string.h>
#include "MaxHeap.h"
#include "MinHeap.h"
using namespace std;

#pragma once
class MedianHeap
{
public:
	MedianHeap();
	void insert(int value);
	int findMedian();

private:
	MaxHeap max;
	MinHeap min;
	int median[1];
	int size;
};

