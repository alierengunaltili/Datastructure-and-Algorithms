#include <iostream>
#include <fstream>
#include <string.h>
#include "TreeNode.h"
using namespace std;

/**
* Title: Trees
* Author: Ali Eren Günaltýlý
* ID: 21801897
* Assignment: 2
* Description: Header of ngramtree class.
*/

#pragma once
class NgramTree {
public:
	NgramTree();
	~NgramTree();
	NgramTree(const NgramTree& t);
	void addNgram(string ngram);
	int getTotalNgramCount();
	bool isComplete();
	bool isFull();
	void generateTree(string fileName, int n);
private:
	void dest(TreeNode* ptr);
	void copyItem(TreeNode* ptr, TreeNode*& newPtr);
	bool findComp(int max, int total);
	void getTotalIndex(TreeNode* ptr, int& total);
	void findMax(TreeNode* ptr,int& max);
	void calcIndex(TreeNode* ptr, int index);
	int internal;
	void createTree(string str, int n);
	void insert(TreeNode* ptr, string str);
	void mypre(TreeNode* ptr, int& x);
	void myin(TreeNode* ptr);
	int getN();
	void setN(int n);
	int this_n;
	bool isAlreadyThere(TreeNode*& ptr, string str);
	TreeNode* root;
	int maxIndex;
	int size;
	// ...
	friend ostream& operator<<(ostream& out, NgramTree tree);
};
