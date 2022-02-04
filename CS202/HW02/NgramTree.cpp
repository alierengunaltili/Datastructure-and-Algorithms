#include "NgramTree.h"

/**
* Title: Trees
* Author: Ali Eren Günaltýlý
* ID: 21801897
* Assignment: 2
* Description: NgramTree class to create NgramTree by argument parsing.
*/

NgramTree::NgramTree() {
	maxIndex = 0;
	this_n = 0;
	root = NULL;
	size = 0;
}

NgramTree::~NgramTree() {
	dest(root);
	//destructor
}

//as our operator overload directly calls the copy constructor
//I use myIn traversal print method inside of my copy constructor.
NgramTree::NgramTree(const NgramTree& t) {
	copyItem(t.root, this->root);
	myin(this->root);
}


void NgramTree::dest(TreeNode* ptr) {
	if (ptr != NULL) {
		//cout << "DEST FUNCT" << endl;
		dest(ptr->leftChildPtr);
		dest(ptr->rightChildPtr);
		delete ptr;
		ptr = NULL;
	}
}


//copying every item of TreeNode to another
void NgramTree::copyItem(TreeNode* ptr, TreeNode*& newPtr) {
	if (ptr != NULL) {
		newPtr = new TreeNode(ptr->item, NULL, NULL);
		newPtr->count = ptr->count;
		newPtr->index = ptr->index;
		copyItem(ptr->leftChildPtr, newPtr->leftChildPtr);
		copyItem(ptr->rightChildPtr, newPtr->rightChildPtr);
	}
}
//add nGram method is also use createTree method as create tree method takes string and put it into the proper place in our NgramTree.
void NgramTree::addNgram(string ngram) {
	createTree(ngram, getN());
}

//calculating total elements inside the tree by preordering and increment every time we call new recursive function.
int NgramTree::getTotalNgramCount() {
	int beginnig = 0;
	mypre(root, beginnig);
	this->size = beginnig;
	return beginnig;
}

//Gives proper index values to tree's every node. 
//Complete tree shouldn't have any gap from left to right.
//we check this condition by finding the max index and whether to total sum of all valid index in our tree satisfy the 
//total sum. If our max index is 9. 9 x 10 / 2 = 45. Total sum of our indices must be 45 otherwise tree is not complete.
bool NgramTree::isComplete() {
	int index = 1;
	int max = 0;
	int total = 0;
	calcIndex(root, index);
	findMax(root, max);
	getTotalIndex(root, total);
	return findComp(max, total);
}

bool NgramTree::findComp(int max, int total) {
	int max_total = max * (max + 1) / 2;
	if (max != max_total) {
		return false;
	}
	else {
		return true;
	}
}

void NgramTree::getTotalIndex(TreeNode* ptr, int& total){
	if (ptr != NULL) {
		total = total + ptr->index;
		getTotalIndex(ptr->leftChildPtr, total);
		getTotalIndex(ptr->rightChildPtr, total);
	}

}

//comparing the leaf and internal nodes. Internal and leaf nodes are decided inside the insert.
//As if some node has children it means it is not leaf it is internal node.
bool NgramTree::isFull() {
	int leaf = size - internal;
	if (leaf == (internal + 1)) {
		return true;
	}
	else {
		return false;
	}
}
//overloading operator calls destructor directly. To eliminate that we use the copied TreeNode.
ostream& operator<<(ostream& out, NgramTree tree) {
	return out;
}

void NgramTree::generateTree(string filename, int n) {
	setN(n);
	string str;
	ifstream input;
	input.open(filename.c_str());
	while (input >> str) {
		if (str.length() >= n) {
			createTree(str, n);
		}
	}
}

//generate a tree from passing string parameter inside to function.
//words come one by one to this function. Thýs function checks whether the given words is alreadyThere or not.
//Then puts it into right place.
void NgramTree::createTree(string str, int n) {
	if (str.length() >= n) {
		string tmp;
		bool flag = false;
		int k = 0;
		if (root == NULL) {
			root = new TreeNode(str.substr(0, n), NULL, NULL);
			root->count++;
			for (int i = 1; i <= str.length() - n; i++) {
				tmp = str.substr(i, n);
				flag = isAlreadyThere(root, tmp);
				if (!flag) {
					insert(root, tmp);
				}
			}
		}
		else {
			TreeNode* head = root;
			for (int i = 0; i <= str.length() - n; i++) {
				tmp = str.substr(i, n);
				flag = isAlreadyThere(root, tmp);
				if (!flag) {
					insert(head, tmp);
				}
			}
		}
	}
}

//preorder traversal method
void NgramTree::mypre(TreeNode* ptr, int& x) {
	if (ptr != NULL) {
		x++;
		mypre(ptr->leftChildPtr,x);
		mypre(ptr->rightChildPtr, x);
	}
}

//finding max index of the tree to calculate what should be the sum of indices if the tree is complete with that max index value.
void NgramTree::findMax(TreeNode* ptr,int& max) {
	if (ptr != NULL) {
		if (ptr->index > max) {
			max = ptr->index;
		}
		findMax(ptr->leftChildPtr, max);
		findMax(ptr->rightChildPtr, max);
	}
}

//calculating index with pre order traversal. Left child index = parent index * 2, right child = parent index * 2 + 1
void NgramTree::calcIndex(TreeNode* ptr, int index) {
	if (ptr != NULL) {
		ptr->index = index;
		calcIndex(ptr->leftChildPtr, 2 * index);
		calcIndex(ptr->rightChildPtr, 2 * index + 1);
	}
}

void NgramTree::myin(TreeNode* ptr) {
	if (ptr != NULL) {
		myin(ptr->leftChildPtr);
		cout << "\"" << ptr->item << "\"" << " appers " << ptr->count << " time(s) " << endl;
		myin(ptr->rightChildPtr);
	}
}

int NgramTree::getN() {
	return this->this_n;
}

void NgramTree::setN(int n) {
	this->this_n = n;
}

bool NgramTree::isAlreadyThere(TreeNode*& ptr, string str) {
	if (ptr != NULL) {
		if (ptr->item == str) {
			ptr->count++;
			return true;
		}
		else if (str < ptr->item) {
			isAlreadyThere(ptr->leftChildPtr, str);
		}
		else {
			isAlreadyThere(ptr->rightChildPtr, str);
		}
	}
	return false;
}

void NgramTree::insert(TreeNode* ptr, string str) {
	TreeNode* tmp = NULL;
	TreeNode* r = NULL;
	while (ptr != NULL) {
		r = ptr;
		if (ptr->item == str) {
			return;
		}
		else {
			if (str > ptr->item) {
				ptr = ptr->rightChildPtr;
			}
			else {
				ptr = ptr->leftChildPtr;
			}
		}
	}
	tmp = new TreeNode(str, NULL, NULL);
	tmp->count++;
	if (tmp->item < r->item) {
		r->leftChildPtr = tmp;
		if (r->rightChildPtr == NULL) {
			internal++;
		}
	}
	else {
		r->rightChildPtr = tmp;
		if (r->leftChildPtr == NULL) {
			internal++;
		}
	}
}


//operator overload ostream.