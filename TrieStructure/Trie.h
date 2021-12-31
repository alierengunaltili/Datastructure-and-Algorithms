#include <iostream>
using namespace std;
#include <string.h>
#pragma once
class Trie
{
public:
	Trie();
	~Trie();
	void insert(string doth, string eng);
	void list();
	bool search(string word);
	bool deleteWord(string word);
	void print();
	void travel();
private:
	struct Node{
		Node* child[26];
		char c;
		bool isWord;
		bool isLeaf;
		string englishWord;
		string prefix;
		Node* parent;
		int childCount;
	};
	Node* root; 
	void traverse(Node* tmp, string str);
	Node* deleteNode(Node* tmp, string key, int depth);
	void printPriv(Node* tmp);
	bool isEmpty(Node* root);
	void printRecursive(Node* tmp, string prefix, int length);
};

