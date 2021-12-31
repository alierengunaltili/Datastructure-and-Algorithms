//Ali Eren Günaltýlý 21801897
//Date: 26/10/21 
//Section 01 Assignment 01
//Sorting cpp for sort methods and performance analysis
#include "sorting.h"
#include <iostream>
#include <string.h>
#include <time.h>
#include <ctime>
#include <cstdlib>
using namespace std;

void sorting::insertionSort(int* arr, int size, int& compCount, int& moveCount) {
	int j;
	int* begin = arr;
	for (int i = 1; i < size; i++) {
		j = i - 1;
		int nextItem = arr[i];
		moveCount++;
		while (arr[j] > nextItem && j > -1) {
			arr[j + 1] = arr[j];
			moveCount++;
			j--;
		}
		arr[j + 1] = nextItem;
		moveCount++;
		compCount = (size * (size - 1)) / 2;
	}
}

void sorting::partition(int* arr, int first, int last, int& pivotIndex, int& compCount, int& moveCount) {
	int pivot = arr[first];
	// initially, everything but pivot is in unknown
	int lastS1 = first; // index of last item in S1
	int firstUnknown = first + 1; // index of first item in unknown

	// move one item at a time until unknown region is empty
	while (firstUnknown <= last) {
		// move item from unknown to proper region
		if (arr[firstUnknown] < pivot) {
			++lastS1;
			swap(arr[firstUnknown], arr[lastS1]);
			moveCount = moveCount + 3;
		}// else belongs to S2
		compCount++; // compares in the parameter
		firstUnknown++;
	}
	// place pivot in proper position and mark its location
	swap(arr[first], arr[lastS1]);
	moveCount = moveCount + 3;
	pivotIndex = lastS1;
}

void sorting::quickSort(int* arr, int first, int last, int& compCount, int& moveCount) {
	int pivotIndex = 0;

	if (first < last) {
		// create the partition: S1, pivot, S2
		partition(arr, first, last, pivotIndex, compCount, moveCount);
		// sort regions S1 and S2
		quickSort(arr, first, pivotIndex - 1, compCount, moveCount);
		quickSort(arr, pivotIndex + 1, last, compCount, moveCount);

	}
}
void sorting::mergeSort(int* arr, int first, int last, int& compCount, int& moveCount) {
	int mid;
	if (first < last) {
		mid = (first + last) / 2;
		mergeSort(arr, first, mid, compCount, moveCount);
		mergeSort(arr, mid + 1, last, compCount, moveCount);
		merge(arr, first, mid, last, compCount, moveCount);
	}
}

void sorting::merge(int* a, int l, int mid, int h, int& comp, int& move) {

	int tempArray[30000]; 	// temporary array
	int first1 = l; 	// beginning of first subarray
	int last1 = mid; 		// end of first subarray
	int first2 = mid + 1;	// beginning of second subarray
	int last2 = h;		// end of second subarray
	int index = first1; // next available location in tempArray

	for (; (first1 <= last1) && (first2 <= last2); ++index) {
		if (a[first1] < a[first2]) {
			tempArray[index] = a[first1];
			move++;
			++first1;
		}
		else {
			tempArray[index] = a[first2];
			move++;
			++first2;
		}
		comp++;
	}
	// finish off the first subarray, if necessary
	for (; first1 <= last1; ++first1, ++index) {
		tempArray[index] = a[first1];
		move++;
	}

	// finish off the second subarray, if necessary
	for (; first2 <= last2; ++first2, ++index) {
		tempArray[index] = a[first2];
		move++;
	}

	// copy the result back into the original array
	for (index = l; index <= h; ++index) {
		a[index] = tempArray[index];
		move++;
	}
}
void sorting::countSort(int arr[], int n, int exp)
{
	int* output = new int[n]; // output array
	int i, count[10] = { 0 };

	// Store count of occurrences in count[]
	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;

	// Change count[i] so that count[i] now contains actual
	//  position of this digit in output[]
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	// Build the output array
	for (i = n - 1; i >= 0; i--) {
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	// Copy the output array to arr[], so that arr[] now
	// contains sorted numbers according to current digit
	for (i = 0; i < n; i++)
		arr[i] = output[i];
}

// The main function to that sorts arr[] of size n using
// Radix Sort
void sorting::radixSort(int* arr, int n)
{
	// Find the maximum number to know number of digits
	int m = getMax(arr, n);

	// Do counting sort for every digit. Note that instead
	// of passing digit number, exp is passed. exp is 10^i
	// where i is current digit number
	for (int exp = 1; m / exp > 0; exp *= 10)
		countSort(arr, n, exp);
}

//get max method for radixSort
int sorting::getMax(int* arr, int n) {
	int tmp = arr[0];

	for (int i = 0; i < n; i++) {
		if (arr[i] > tmp) {
			tmp = arr[i];
		}
	}
	return tmp;
}


void sorting::printArray(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void sorting::performanceAnalysis() {
	//randomly and dynamically created arrays with predecided size.
	int* arr_2000 = new int[2000];
	int* arr_6000 = new int[6000];
	int* arr_10000 = new int[10000];
	int* arr_14000 = new int[14000];
	int* arr_18000 = new int[18000];
	int* arr_22000 = new int[22000];
	int* arr_26000 = new int[26000];
	int* arr_30000 = new int[30000];
	int* m2000 = new int[2000];
	int* m6000 = new int[6000];
	int* m10000 = new int[10000];
	int* m14000 = new int[14000];
	int* m18000 = new int[18000];
	int* m22000 = new int[22000];
	int* m26000 = new int[26000];
	int* m30000 = new int[30000];

	int* r2000 = new int[2000];
	int* r6000 = new int[6000];
	int* r10000 = new int[10000];
	int* r14000 = new int[14000];
	int* r18000 = new int[18000];
	int* r22000 = new int[22000];
	int* r26000 = new int[26000];
	int* r30000 = new int[30000];

	createArray(arr_2000, m2000, 2000);
	createArray(arr_6000,m6000, 6000);
	createArray(arr_10000, m10000, 10000);
	createArray(arr_14000, m14000, 14000);
	createArray(arr_18000,m18000, 18000);
	createArray(arr_22000,m22000, 22000);
	createArray(arr_26000,m26000, 26000);
	createArray(arr_30000,m30000, 30000);

	createArray(arr_2000, r2000, 2000);
	createArray(arr_6000, r6000, 6000);
	createArray(arr_10000, r10000, 10000);
	createArray(arr_14000, r14000, 14000);
	createArray(arr_18000, r18000, 18000);
	createArray(arr_22000, r22000, 22000);
	createArray(arr_26000, r26000, 26000);
	createArray(arr_30000, r30000, 30000);
	int sizes[8] = { 2000,6000, 10000, 14000, 18000,22000,26000,30000 };
	int* arrs[8] = { arr_2000, arr_6000, arr_10000, arr_14000, arr_18000,arr_22000,arr_26000, arr_30000 };
	int* rs[8] = { r2000, r6000, r10000, r14000, r18000, r22000, r26000, r30000 };
	int* ms[8] = { m2000, m6000, m10000, m14000, m18000, m22000, m26000, m30000 };
	int comp = 0;
	int move = 0;
	int k = 0;
	string sorts[3];
	sorts[0] = "insertion";
	sorts[1] = "merge";
	sorts[2] = "quick";
	for (int i = 0; i < 4; i++) {
		if (i == 0) {
			cout << "Part A: Time Analysis of Insertion Sort " << endl;
		}
		else if (i == 1) {
			cout << "Part B: Time Analysis of Merge Sort" << endl;
		}
		else if (i == 2) {
			cout << "Part C: Time Analysis of Quick Sort" << endl;
		}
		else if (i == 3) {
			cout << "Part D: Time Analysis of Radix Sort" << endl;
		}
		cout << "Array Size" << "\t" << "Time Elapsed" << "\t" << "compCount" << "\t" << "moveCount" << endl;
		for (int j = 0; j < 8; j++) {
			if (i == 0) {
				comp = 0;
				move = 0;
				double duration1;
				clock_t startTime21 = clock();
				for (int k = 0; k < 10; k++) {
					insertionSort(arrs[j], sizes[j], comp, move);
				}
				duration1 = 100 * double(clock() - startTime21) / CLOCKS_PER_SEC;
				if (j == 0) {
					cout << sizes[j] << "\t\t" << duration1 << "ms" << "\t" << comp << "\t\t\t" << move << endl;
				}
				else {
					cout << sizes[j] << "\t\t" << duration1 << "ms" << "\t" << comp << "\t\t" << move << endl;
				}
			}
			else if (i == 1) {
				move = 0;
				comp = 0;
				double duration2;
				clock_t startTime22 = clock();
				for (int k = 0; k < 10; k++) {
					mergeSort(arrs[j], 0, sizes[j] - 1, comp, move);
				}
				duration2 = 100 * double(clock() - startTime22) / CLOCKS_PER_SEC;
				cout << sizes[j] << "\t\t" << duration2 << "ms" << "\t" << comp << "\t\t" << move << endl;
			}
			else if(i == 2) {
				comp = 0;
				move = 0;
				double duration3;
				clock_t startTime23 = clock();
				quickSort(ms[j], 0, sizes[j] - 1, comp, move);
				duration3 = 1000 * double(clock() - startTime23) / CLOCKS_PER_SEC;
				cout << sizes[j] << "\t\t" << duration3 << "ms" << "\t" << comp << "\t\t" << move << endl;
			}
			else if (i == 3) {
				comp = 0;
				move = 0;
				double duration4;
				clock_t startTime24 = clock();
				for (int k = 0; k < 10; k++) {
					radixSort(rs[j], sizes[j]);
				}
				duration4 = 100 * double(clock() - startTime24) / CLOCKS_PER_SEC;
				cout << sizes[j] << "\t\t" << duration4 << "ms" << "\t" << comp << "\t\t" << move << endl;
			}
		}
		cout << "----------------------------------------------------------------------" << endl;
	}
}

void sorting::createArray(int* &arr,int* & tmp, int n){
	//random array function for filled two arrays with same randomly generated values.
		//arr = new int[n];
		int v1 = 0;
		for (int i = 0; i < n; i++) {
			v1 = rand() % 2000;
			arr[i] = v1;
		}
		for (int i = 0; i < n; i++) {
			tmp[i] = arr[i];
		}
        //return arr;
}

void sorting::swap(int& x, int& y) {
		int temp = x;
		x = y;
		y = temp;
}