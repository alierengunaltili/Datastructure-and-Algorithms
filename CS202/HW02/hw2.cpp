#include <iostream>
#include <string.h>
#include <cstring>
#include <cstdlib>
using namespace std;
#include "NgramTree.h"

// CS202_Hw02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/**
* Title: Trees
* Author: Ali Eren Günaltýlý
* ID: 21801897
* Assignment: 2
* Description: my main function
*/


int main(int argc, char** argv)
{
    NgramTree tree;
    string fileName(argv[1]);
    int n = atoi(argv[2]);
    tree.generateTree(fileName, n);
    cout << "\nTotal " << n << "-gram count: " << tree.getTotalNgramCount() << endl;
    cout << tree << endl;
    cout << n << "-gram tree is complete: " << (tree.isComplete() ? "Yes" : "No") << endl;
    cout << n << "-gram tree is full: " << (tree.isFull() ? "Yes" : "No") << endl;
    // Before insertion of new n-grams
    cout << "\nTotal " << n << "-gram count: " << tree.getTotalNgramCount() << endl;
    tree.addNgram("samp");
    tree.addNgram("samp");
    tree.addNgram("zinc");
    tree.addNgram("aatt");
    cout << "\nTotal " << n << "-gram count: " << tree.getTotalNgramCount() << endl;
    cout << tree << endl;
    cout << n << "-gram tree is complete: " << (tree.isComplete() ? "Yes" : "No") << endl;
    cout << n << "-gram tree is full: " << (tree.isFull() ? "Yes" : "No") << endl;
    cout << "---------------------------" << endl;
    return 0;
}
