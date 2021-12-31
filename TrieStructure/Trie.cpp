#include "Trie.h"

Trie::Trie() {
	this->root = new Node;
	root->c = '\0';
	for (int i = 0; i < 26; i++) {
		root->child[i] = NULL;
	}
	root->isWord = false;
	root->isLeaf = true;
	root->englishWord = "null";
	root->parent = NULL;
	root->prefix = "";
	root->childCount = 0;
}


void Trie::insert(string dothrak, string eng) {
	int count = 0;
	Node* tmp = root;
	int asci = 97;
	int value = 0;
	for (int i = 0; i < dothrak.length(); i++) {
		value = dothrak[i] - asci;
		if (tmp->child[value] != NULL) {
			tmp->isLeaf = false;
			tmp->child[value]->parent = tmp;
			tmp->child[value]->prefix = tmp->prefix + dothrak[i];
			tmp = tmp->child[value];
			count++;
		}
		else {
			tmp->child[value] = new Node();
			tmp->child[value]->childCount = 0;
			tmp->child[value]->c = dothrak[i];
			tmp->isLeaf = false;
			tmp->childCount++;
			tmp->child[value]->parent = tmp;
			tmp->child[value]->prefix = tmp->prefix + dothrak[i];
			tmp = tmp->child[value];
		}
	}
	if (count == dothrak.length()) {
		if (eng == tmp->englishWord) {
			cout << '"' << tmp->prefix << '"'  << " already exists " << endl;
		}
		else {
			tmp->englishWord = eng;
			cout << '"' << tmp->prefix << '"' << " is updated" << endl;
		}
	}
	else {
		cout << '"' << tmp->prefix << '"'  <<   " was added " << endl;
		tmp->isWord = true;
		tmp->englishWord = eng;
		tmp->isLeaf = true;
		for (int i = 0; i < 26; i++) {
			if (tmp->child[i] != NULL) {
			tmp->isLeaf = false;
			}
		}
	}

}


void Trie::print() {
	printPriv(this->root);
}


void Trie::printPriv(Node* tmp) {
	if (tmp == NULL) {
		cout << "Trie is empty" << endl;
		return;
	}
	printRecursive(root,"", 0);
}


bool Trie::search(string word) {
	Node* tmp = root;
	int asci = 97;
	int value = -1;
	value = word[0] - asci;
	int count = 0;
	if (tmp->child[value] == NULL) {
		cout << "No record " << endl;
		return false;
	}
	else {
		count++;
		tmp = tmp->child[value];
	}

	for (int i = 1; i < word.length(); i++) {
		value = word[i] - asci;
		if (tmp->child[value] == NULL) {
			cout << "Incorrect Dothraki word " << endl;
			return false;
		}
		tmp = tmp->child[value];
	}
	if (tmp->englishWord == "") {
		cout << "Not enough Dothraki word " << endl;
	}
	else {
		cout << "The english equivalent of " << '"' << tmp->prefix << '"'  << " is " << '"'  <<  tmp->englishWord << '"'  <<  endl;
		return true;
	}
}

bool Trie::deleteWord(string word) {
	Node* tmp = root;
	int asci = 97;
	int value = -1;
	value = word[0] - asci;
	int count = 0;
	if (tmp->child[value] == NULL) {
		cout << "No record " << endl;
		return false;
	}
	else {
		count++;
		tmp = tmp->child[value];
	}

	for (int i = 1; i < word.length(); i++) {
		value = word[i] - asci;
		if (tmp->child[value] == NULL) {
			cout << "Incorrect Dothraki word " << endl;
			return false;
		}
		tmp = tmp->child[value];
	}
	if (tmp->englishWord == "") {
		cout << "Not enough Dothraki word " << endl;
	}
	else {
		if (tmp->childCount >= 1) {
			tmp->englishWord = "";
			cout << '"' << tmp->prefix << '"' << " deletion is successful " << endl;
			return true;
		}
		else {
			cout << '"' << tmp->prefix << '"' << " deletion is successful " << endl;
			deleteNode(root, tmp->prefix, 0);
			return true;
		}
		//delete the node
	}
}

bool Trie::isEmpty(Node* root)
{
	for (int i = 0; i < 26; i++)
		if (root->child[i])
			return false;
	return true;
}

Trie::Node* Trie::deleteNode(Node* tmp, string key, int depth) {

	// If tree is empty
	if (!tmp)
		return NULL;

	if (depth == key.size()) {

		if (tmp->isLeaf)
			tmp->isLeaf = false;

		if (isEmpty(tmp)) {
			tmp->parent->childCount--;
			delete (tmp);
			tmp = NULL;
		}

		return tmp;
	}


	int index = key[depth] - 'a';
	tmp->child[index] = deleteNode(tmp->child[index], key, depth + 1);

	if (isEmpty(tmp) && root->isLeaf == false) {
		tmp->parent->childCount--;
		delete (tmp);
		tmp = NULL;
	}
	return tmp;
}

void Trie::printRecursive(Node* tmp, string prefix, int length) {
	/*char* newPrefix = new char[length + 2];
	for (int i = 0; i < length; i++) {
		newPrefix[i] = prefix[i];
	}
	newPrefix[length + 1] = ' ';

	*/
		string newPrefix = new char[length + 2];
		for (int i = 0; i < length; i++) {
			newPrefix[i] = prefix[i];
		}
		newPrefix[length + 1] = '\0';
		if (tmp->englishWord != "") {
			string str;
			for (int i = 0; i < length; i++) {
				str += prefix[i];
			}
			cout << "DOTHRAK: " << tmp->prefix << ", ENG:" << tmp->englishWord << " " << tmp->childCount << endl;
		}

		for (int i = 0; i < 26; i++) {
			if (tmp->child[i] != NULL) {
				newPrefix[length] = i;
				printRecursive(tmp->child[i], newPrefix, length + 1);
			}
		}
}

void Trie::travel() {
	string str = "-";
	traverse(root, str);
}

void Trie::traverse(Node* tmp, string str) {
	if (root == NULL) {
		cout << "Trie is empty " << endl;
		return;
	}
	if (tmp->childCount > 1 && tmp != root) {
		cout << str << tmp->prefix;
		str += '   ';
		if (tmp->englishWord != "") {
			cout << "(" << tmp->englishWord << ")" << endl;
		}
		else {
			cout << endl;
		}
	}
	if (tmp->isLeaf) {
		cout << str << tmp->prefix << "(" << tmp->englishWord << ")" << endl;
		str = "-";
	}
	//cout << tmp->c << " " << tmp->childCount <<  endl;
	for (int i = 0; i < 26; i++) {
		if (tmp->child[i] != NULL) {
			traverse(tmp->child[i], str);
		}
	}
	
}

Trie::~Trie(){
}
