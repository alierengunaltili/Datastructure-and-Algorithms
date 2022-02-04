#include <iostream>
#include <string.h>
using namespace std;
#pragma once

typedef string TreeItemType;
/**
* Title: Trees
* Author: Ali Eren Günaltýlý
* ID: 21801897
* Assignment: 2
* Description: TreeNode header for node of NgramTree
*/

//typedef data TreeItemType;
class TreeNode {// node in the tree
private:
    TreeItemType item;
    TreeNode() {};
    TreeNode(const TreeItemType& nodeItem,
        TreeNode* left = NULL,
        TreeNode* right = NULL)
        :item(nodeItem), leftChildPtr(left), rightChildPtr(right), count(0), index(0) {};

    int index;
    TreeNode* leftChildPtr;  // pointer to left child
    TreeNode* rightChildPtr; // pointer to right child
    int count;
    friend class NgramTree;
};