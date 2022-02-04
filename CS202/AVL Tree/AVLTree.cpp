/*
* Title : Heaps and AVL Trees
* Author : Ali Eren Günaltýlý
* ID : 21801897
* Section : 01
* Assignment : 3
* Description : AVLTree implementation
*/

#include "AVLTree.h"

AVLTree::AVLTree() {
	root = NULL;
	size = 0;
	rotation_count = 0;
}

void AVLTree::deleteTree() {
	del(this->root);
	this->root = NULL;
}

int AVLTree::getNumberOfRotations() {
	return rotation_count;
}

void AVLTree::del(Node* ptr) {
	if (ptr != NULL) {
		del(ptr->left);
		del(ptr->right);
		delete ptr;
		ptr = NULL;
	}
}

int AVLTree::calculate(Node* tmp) {
	int he_l;
	int he_r;
	he_l = tmp && tmp->left ? tmp->left->height : 0;
	he_r = tmp && tmp->right ? tmp->right->height : 0;

	if (he_l > he_r) {
		return he_l + 1;
	}
	else {
		return he_r + 1;
	}
}
void AVLTree::giveHeight(Node* &tmp, int val) {
	if (tmp == NULL) {
		tmp = new Node;
		tmp->item = val;
		tmp->height = 0;
		tmp->left = NULL;
		tmp->right = NULL;
	}
	else {
		if (val > tmp->item) {
			giveHeight(tmp->right, val);
		}
		else {
			giveHeight(tmp->left, val);
		}
	}

	tmp->height = calculate(tmp);
	if (calculateHeightDifference(tmp) >= 2 || calculateHeightDifference(tmp) <= -2) {
		tmp = rebuild(tmp);
	}
}
	 
AVLTree::Node* AVLTree::rebuild(Node* &tmp) {
	if (calculateHeightDifference(tmp) == 2) {
		if (calculateHeightDifference(tmp->left) == 1) {
			Node* ptr = LL(tmp);
			return ptr;
		}
		else {
			Node* ptr = LR(tmp);
			return ptr;
		}
	}
	else if (calculateHeightDifference(tmp) == -2) {
		if (calculateHeightDifference(tmp->right) == -1) {
			Node* ptr = RR(tmp);
			return ptr;
		}
		else {
			Node* ptr = RL(tmp);
			return ptr;
		}
	}
	else {
		return NULL;
	}
}


void AVLTree::print() {
	int x = 0;
	myInorder(this->root, x);
}

void AVLTree::insert(int val) {
	giveHeight(this->root, val);
}

AVLTree::Node* AVLTree::LL(Node* &tmp) {
	Node* l = tmp->left;
	Node* r = l->right;

	l->right = tmp;
	tmp->left = r;
	tmp->height = calculate(tmp);
	l->height = calculate(l);

	if (root == tmp) {
		root = l;
	}
	rotation_count++;
	return l;
}


AVLTree::Node* AVLTree::RR(Node* &tmp) {
	Node* r = tmp->right;
	Node* l = tmp->right->left;
	r->left = tmp;
	tmp->right = l;
	tmp->height = calculate(tmp);
	r->height = calculate(r);

	if (root == tmp) {
		this->root = r;
	}
	rotation_count++;
	return r;
}
 
AVLTree::Node* AVLTree::LR(Node* &tmp) {
	Node* tmp_left = tmp->left;
	Node* tmp_left_right = tmp->left->right;

	tmp_left->right = tmp_left_right->left;
	tmp->left = tmp_left_right->right;

	tmp_left_right->left = tmp_left;
	tmp_left_right->right = tmp;

	tmp_left->height = calculate(tmp_left);
	tmp->height = calculate(tmp);
	tmp_left_right->height = calculate(tmp_left_right);

	if (tmp == root) {
		this->root = tmp_left_right;
	}
	rotation_count++;
	return tmp_left_right;

}

AVLTree::Node* AVLTree::RL(Node* &tmp) {
	Node* r = tmp->right;
	Node* rl = tmp->right->left;

	r->left = rl->right;
	tmp->right = rl->left;
	rl->right = r;
	rl->left = tmp;

	r->height = calculate(r);
	tmp->height = calculate(tmp);
	rl->height = calculate(rl);
	
	if (tmp == root) {
		this->root = rl;
	}
	rotation_count++;
	return rl;
}

void AVLTree::printRoot() {
	cout << "ROOT: " << this->root->item << endl;

}

void AVLTree::myInorder(Node* tmp, int& count) {
	if (tmp != NULL) {
		if (tmp->isLeaf) {
			count++;
		}
		myInorder(tmp->left, count);
		myInorder(tmp->right, count);
	}
}


int AVLTree::calculateHeightDifference(Node* tmp) {
	int he_l;
	int he_r;
	he_l = tmp && tmp->left ? tmp->left->height : 0;
	he_r = tmp && tmp->right ? tmp->right->height : 0;
	
	return (he_l - he_r);
	//negative means left rotation is needed
	//positive means right rotation is needed
}