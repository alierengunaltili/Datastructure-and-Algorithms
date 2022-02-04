/*
* Title : Heaps and AVL Trees
* Author : Ali Eren Günaltýlý
* ID : 21801897
* Section : 01
* Assignment : 3
* Description : AVLTree header 
*/

#include <iostream>
using namespace std;
#pragma once
class AVLTree
{
public:
	AVLTree();
	void insert(int value);
	int getNumberOfRotations();
	void deleteTree();
	void print();
	void printRoot(); //for better testing rotation methods.
private:
	int size;
	int rotation_count;
	struct Node
	{
		Node* right;
		Node* left;
		int item;
		int height;
		bool isLeaf;
	};
	Node* root;
	void del(Node* root);
	void giveHeight(Node* &root, int val);
	Node* rebuild(Node* &root);
	Node* LL(Node* &root);
	Node* LR(Node* &root);
	Node* RL(Node* &root);
	Node* RR(Node* &root);
	int calculate(Node* root);
	void myInorder(Node* head, int& count);
	int calculateHeightDifference(Node* root);
};

