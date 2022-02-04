/**
* Author : Ali Eren Günaltýlý
* ID: 21801897
* Section : 01
* Assignment : 4
*/
#include <iostream>
using namespace std;

#pragma once
class HashTable
{
public:
	enum CollisionStrategy
	{
		LINEAR, QUADRATIC,DOUBLE 
	};
	HashTable(const int tableSize, const CollisionStrategy option);
	~HashTable();
	bool insert(const int item);
	bool search(const int item, int& numProbes);
	bool remove(const int item);
	void display();
	int getSize();
	void analyze(int& numSuccProbes, int& numUnsuccProbes);
private:
	int findPrime(int border);
	CollisionStrategy strategy;
	int* table;
	int table_size;
	int prime;
};

