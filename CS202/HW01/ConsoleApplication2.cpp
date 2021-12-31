// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Ali Eren Günaltýlý 21801897
//Date: 26/10/21 
//Section 01 Assignment 01
//Main method

#include <iostream>
#include "sorting.h"
using namespace std;



int main()
{
    sorting sort;
    int* arr1 = new int[16];
    int* arr2 = new int[16];
    int* arr3 = new int[16];
    int* arr4 = new int[16];
    int val = 0;
    int constantarr[16] = {7, 3, 6, 12, 13, 4, 1, 9, 15, 0, 11, 14, 2, 8, 10, 5} ;

    for (int i = 0; i < 16; i++) {
        arr1[i] = constantarr[i];
        arr3[i] = arr1[i];
        arr2[i] = arr1[i];
        arr4[i] = arr1[i];
    }
    int move = 0;
    int comp = 0;
    sort.insertionSort(arr1, 16, comp, move);
    sort.printArray(arr1, 16);
    sort.mergeSort(arr2, 0, 15, comp, move);
    sort.printArray(arr2, 16);
    sort.quickSort(arr3, 0, 15, comp, move);
    sort.printArray(arr3, 16);
    sort.radixSort(arr4, 16);
    sort.printArray(arr4, 16);
    cout << "-------------------------------------------------" << endl;
    sort.performanceAnalysis();
    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
