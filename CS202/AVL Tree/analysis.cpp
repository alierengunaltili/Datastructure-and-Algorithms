/*
* Title : Heaps and AVL Trees
* Author : Ali Eren Günaltýlý
* ID : 21801897
* Section : 01
* Assignment : 3
* Description : analysis class for calling rotationAnalysis method
*/

#include "analysis.h"
#include <stdlib.h>

analysis::analysis() {

}

void analysis::rotationAnalysis() {
	//boundary 1-100.000
	int arr[10];
	int rand_rotations[10];
	int asc_rotations[10];
	int desc_rotations[10];
	for (int i = 0; i < 10; i++) {
		rand_rotations[i] = 0;
		asc_rotations[i] = 0;
		desc_rotations[i] = 0;
	}

	AVLTree randTree;
	AVLTree ascTree;
	AVLTree descTree;
	for (int i = 0; i < 10; i++) {
		arr[i] = (i + 1) * 1000;
	}
	int rand_val = 0;
	int asc_val = 1;
	int desc_val = 100000;
	int incrementVolume = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < arr[i]; j++) {
			incrementVolume = 99000 / arr[i];
			desc_val = desc_val - incrementVolume;
			asc_val = asc_val + incrementVolume;
			rand_val = rand() % 100000 + 1;
			randTree.insert(rand_val);
			ascTree.insert(asc_val);
			descTree.insert(desc_val);
		}
		rand_rotations[i] = randTree.getNumberOfRotations();
		asc_rotations[i] = ascTree.getNumberOfRotations();
		desc_rotations[i] = descTree.getNumberOfRotations();
		randTree.deleteTree();
		ascTree.deleteTree();
		descTree.deleteTree();
	}

	cout << "Array Size \t" << "Random \t" << "Ascending \t" << "Descending" << endl;
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << "\t\t" << rand_rotations[i] << "\t\t" << asc_rotations[i] << "\t\t" << desc_rotations[i] << endl;
	}
}

