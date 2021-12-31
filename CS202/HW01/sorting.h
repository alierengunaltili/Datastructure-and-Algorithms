//Ali Eren Günaltýlý 21801897
//Date: 26/10/21 
//Section 01 Assignment 01
//Sorting.h for definitons of methods and variables.
#include <iostream>
using namespace std;
#pragma once
class sorting
{
public:
	void insertionSort(int* arr, int arraysize, int& compCount, int& moveCount);
	void quickSort(int* arr, int first, int last, int& compCount, int& moveCount);
	void mergeSort(int* arr, int first, int last, int& compCount, int& moveCount);
	void radixSort(int* arr, int arraySize);
	void printArray(int* arr, int arraySize);
	void performanceAnalysis();
	void swap(int& x, int& y);
	void printRow(int size, double time, int comp, int move);
	void printHeaders();
private:
	void createArray(int* &arr,int* &tmp, int size);
	int getMax(int* arr, int n);
	void merge(int* a, int l, int mid, int h, int& comp, int& move);
	void partition(int* a, int l, int h, int& pivInt, int& comp, int& move);
	void countSort(int* arr, int n, int exp);
};

