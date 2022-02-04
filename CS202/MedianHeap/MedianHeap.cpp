/*
* Title : Heaps and AVL Trees
* Author : Ali Eren Günaltýlý
* ID : 21801897
* Section : 01
* Assignment : 3
* Description : Median Heap implementation
*/

#include "MedianHeap.h"


MedianHeap::MedianHeap() {
	size = 0;
}


void MedianHeap::insert(int value) {
	cout << "Inserted value " << value << endl;
	if (size == 0) {
		max.insert(value);
		size++;
		median[0] = value;
	}
	else if (median[0] < value) {
		if (min.size() <= max.size()) {
			min.insert(value);
		}
		else {
			int tmp = min.extractMin();
			min.insert(value);
			max.insert(tmp);
		}
	}
	else if (median[0] > value) {
		if (max.size() <= min.size()) {
			max.insert(value);
		}
		else {
			int tmp = max.extractMax();
			max.insert(value);
			min.insert(tmp);
		}
	}

	if (size != 0) {
		if (max.size() > min.size()) {
			median[0] = max.peek();
		}
		else if (min.size() > max.size()) {
			median[0] = min.peek();
		}
		else {
			median[0] = (min.peek() + max.peek()) / 2;
		}
	}
}


int MedianHeap::findMedian() {
	max.print();
	min.print();
	cout << "Median of two heaps : ";
	return median[0];
}