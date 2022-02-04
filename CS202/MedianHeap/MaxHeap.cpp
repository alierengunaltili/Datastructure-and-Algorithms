/*
* Title : Heaps and AVL Trees
* Author : Ali Eren Günaltýlý
* ID : 21801897
* Section : 01
* Assignment : 3
* Description : MaxHeap Implementation
*/

#include "MaxHeap.h"

MaxHeap::MaxHeap() {
	Size = 0;
	constSize = 100;
}


void MaxHeap::insert(int value) {
	cout << "Inserted value to max heap " << value << endl;
	arr[Size] = value;

	// Trickle new item up to its proper position
	int place = Size;
	int parent = (place - 1) / 2;
	while ((place > 0) && (arr[place] > arr[parent])) {
		int temp = arr[parent];
		arr[parent] = arr[place];
		arr[place] = temp;
		place = parent;
		parent = (place - 1) / 2;
	}
	++Size;
}

//print method for maxHeap
void MaxHeap::print() {
	cout << "-----MaxHeap-----------" << endl;
	for (int i = 0; i < Size; i++) {
		cout << i  << ": " << arr[i] << endl;
	}
	cout << "----------------------" << endl;
}

int MaxHeap::extractMax() {
	if (Size == 0) {
		cout << "Heap is empty" << endl;
		return -1;
	}
	else {
		int rootItem = arr[0];
		arr[0] = arr[--Size];
		rebuild(0);
		return rootItem;
	}
}
int MaxHeap::peek() {
	return arr[0];
}


void MaxHeap::rebuild(int root) {
	int child = 2 * root + 1; 	// index of root's left child, if any
	if (child < Size) {
		// root is not a leaf so that it has a left child
		int rightChild = child + 1; 	// index of a right child, if any
		// If root has right child, find larger child
		if ((rightChild < Size) &&
			(arr[rightChild] > arr[child]))
			child = rightChild; 	// index of larger child

		// If root’s item is smaller than larger child, swap values
		if (arr[root] < arr[child]) {
			int temp = arr[root];
			arr[root] = arr[child];
			arr[child] = temp;

			// transform the new subtree into a heap
			rebuild(child);
		}
	}
}


int MaxHeap::size() {
	return this->Size;
}