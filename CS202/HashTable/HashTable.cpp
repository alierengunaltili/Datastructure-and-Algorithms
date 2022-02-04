/**
* Author : Ali Eren Günaltýlý
* ID: 21801897
* Section : 01
* Assignment : 4 
*/
#include "HashTable.h"



HashTable::HashTable(const int tableSize, const CollisionStrategy option) {
	this->table_size = tableSize;
	this->strategy = option;
	table = new int[table_size];
	for (int i = 0; i < table_size; i++) {
		table[i] = -9999;
	}
}

HashTable::~HashTable() {
}

bool HashTable::remove(const int item) {
	bool isFound = false;
	int ind = -1;
	for (int i = 0; i < table_size; i++) {
		if (table[i] == item) {
			ind = i;
			isFound = true;
		}
	}
	if (isFound) {
		table[ind] = -9999;
		cout << item << " in index " << ind << " is deleted. " << endl;
		return true;
	}
	else {
		cout << item << " is not on the hash table " << endl;
		return false;
	}
}

bool HashTable::search(const int item, int& probes) {
	//to avoid infinite loop 
	//we search till we see empty slot
	int ind = item % table_size;
	bool isFound = false;
	probes = 0;
	bool isFull = true;
	for (int i = 0; i < table_size; i++) {
		if (table[i] == -9999) {
			isFull = false;
		}
	}
	if (isFull) {
		return false;
	}

	if (strategy == LINEAR) {
		if (table[ind] == -9999) {
			probes++;
		}
		while (table[ind] != -9999) {
			//cout << " IND FOR LINEAR " << ind << " prob:" << probes << "-------" << item << endl;
			probes++;
			if (table[ind] == item) {
				isFound = true;
				break;
			}
			else {
				if (ind >= table_size) {
					ind = ind % table_size;
				}
				else {
					ind++;
				}
			}
			if (table[ind] == -9999) {
				probes++;
			}
		}
	}
	else if (strategy == QUADRATIC) {
		int i = 1;
		int incrementAmount = 0;
		int place = ind;
		bool flag = true;
		if (table[ind] == -9999) {
			probes++;
		}
		while (table[place] != -9999 && flag) {
			probes++;
			if (table[place] == item) {
				isFound = true;
				break;
			}
			else {
				incrementAmount = i * i;
				i++;
				//if (( (i * i) - ((i - 1) * (i - 1)) ) == table_size) {
					//flag = false;
				//}
				place = ind + incrementAmount;
				if (place >= table_size) {
					place = place % table_size;
				}
			}
		}
	}
	else if (strategy == DOUBLE) {
		int h2_place = 7 - (item % 7);
		int place = ind;
		probes = 0;
		int i = 1;
		if (table[place] == -9999) {
			probes++;
		}
		while (table[place] != -9999) {
			probes++;
			if (table[place] == item) {
				isFound = true;
				break;
			}
			else {
				place = ind + i * h2_place;
				if (place > table_size) {
					place = place % table_size;
				}
				i++;
			}
		}
	}
	else {
		cout << "Strategy is wrong " << endl;
	}

	if (isFound) {
		//cout << item << " is found after " << probes << " probes" << endl;
	}
	else {
		//cout << item << " is not found after " << probes << " probes" << endl;
	}
	return isFound;
}

bool HashTable::insert(const int item) {
	bool isFull = true;
	bool isAlreadyThere = false;
	for (int i = 0; i < table_size; i++) {
		if (table[i] == -9999) {
			isFull = false;
		}
		if (table[i] == item) {
			isAlreadyThere = true;
		}
	}
	if (!isFull && !isAlreadyThere) {
		if (strategy == LINEAR) {
			int ind = item % table_size;
			//case of place is available for new comer integer.
			if (table[ind] == -9999) {
				table[ind] = item;
			}
			else {
				int i = 0;
				int place = ind + i;
				while (table[place] != -9999) {
					place++;
					if (place >= table_size) {
						place = place % table_size;
					}
				}
				table[place] = item;
			}
		}
		else if (strategy == QUADRATIC) {
			int ind = item % table_size;
			if (table[ind] == -9999) {
				table[ind] = item;
			}
			else {
				int i = 1;
				int exp = 1;
				int place = ind;
				while (table[place] != -9999) {
					place = ind;
					exp = i * i;
					place = place + exp;
					if (place >= table_size) {
						place = place % table_size;
					}
					i++;
				}
				table[place] = item;
			}
		}
		else if (strategy == DOUBLE) {
			int ind = item % table_size;
			if (table[ind] == -9999) {
				table[ind] = item;
			}
			else {
				//ind  is the result of h1(x) we need h2(x) for double hashing.
				int h2_place = 7 - (item % 7);
				int place = ind;
				int i = 1;
				while (table[place] != -9999) {
					place = ind + (h2_place * i);
					if (place >= table_size) {
						place = place % table_size;
					}
					i++;
				}
				table[place] = item;
			}
		}
		else {
			//do nothing
		}
		return true;
	}
	else {
		return false;
	}
}

void HashTable::analyze(int& numSuccProbes, int& numUnsuccProbes) {
	int* notInTheHash = new int[table_size];
	for (int i = 0; i < table_size; i++) {
		notInTheHash[i] = 0;
	}
	int empty = 0;
	int k = 0;
	for (int i = 0; i < table_size * table_size;) {
		if (k < table_size) {
			bool isThere = search(i, empty);
			if (!isThere) {
				notInTheHash[k] = i;
				k++;
				i++;
			}
			else {
				i = i + table_size;
			}
		}
		else {
			break;
		}
	}
	int sucProb = 0;
	int unsucProb = 0;
	numSuccProbes = 0;
	numUnsuccProbes = 0;
	for (int i = 0; i < table_size; i++) {
		if (table[i] != -9999) {
			search(table[i], sucProb);
			numSuccProbes += sucProb;
			sucProb = 0;
			if (table[i] == i) {
				notInTheHash[i] = notInTheHash[i] + table_size;
			}
		}
	}
	//cout << "Not in the list array " << endl;
	//for (int i = 0; i < table_size; i++) {
		//cout << notInTheHash[i] << " " << endl;
	//}
	//cout << "--------------------------" << endl;
	for (int i = 0; i < table_size; i++ ) {
		search(notInTheHash[i], unsucProb);
		numUnsuccProbes += unsucProb;
		unsucProb = 0;
	}
}

int HashTable::findPrime(int border) {
	return 0;
}

int HashTable::getSize() {
	return this->table_size;
}

void HashTable::display() {
	for (int i = 0; i < table_size; i++) {
		if (table[i] != -9999) {
			cout << i << " : " << table[i] << endl;
		}
		else {
			cout << i << " : " << endl;
		}
	}
}