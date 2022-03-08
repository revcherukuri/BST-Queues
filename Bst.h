#pragma once
/*
 @Lab: Lab 5 Binary Search Tree
 @Authors: Casey Merritt, Revanth Cherukuri
 @Purpose: Show our Knowledge of a BST
 */

#include "BstNode.h"
#include "queue.h"
#include <iostream>
#include <fstream>

template <typename T>
class Bst {
public:
	int count;
	BstNode<T>* root;

	Bst() {//constructor
		count = 0;
		root = NULL;
	}

	~Bst() {//destructor
		if (root != NULL) {
			emptyBst(root);
		}
	}
	/*
	 Pre:Takes in an outstream for file output
	 Post:
	 Return: returns a BstNode Ptr
	 */
	BstNode<T>* GetRoot(std::ostream& ofile);
	/*
	Pre: Takes in an outstream for file output, a BstNode ptr that points to the root and Data
	Post:
	Return: returns a BstNode Ptr
	*/
	BstNode<T>* insert(T data, BstNode<T>* base, std::ostream& ofile);
	/*
	Pre: Takes in an outstream for file output, a BstNode ptr that points to the root and Data
	Post:
	Return: returns a BstNode Ptr
	*/
	BstNode<T>* remove(T data, BstNode<T>* base, std::ostream& ofile);
	/*
	Pre: Takes in an outstream for file output and Data
	Post:
	Return: true or false based on search algorithm
	*/
	bool search(T data, std::ostream& ofile);
	/*
	Pre:
	Post:
	Return: returns count
	*/
	int	getCount();
	/*
	Pre: Takes in BstNode Ptr
	Post:
	Return:
	*/
	void emptyBst(BstNode<T>* base);
	/*
	Pre: Takes in an outstream for file output and a BstNode ptr that points to the root
	Post:
	Return:
	*/
	void printBst(BstNode<T>* b, std::ostream& ofile);
	/*
	Pre: Takes in an outstream for file output and a BstNode ptr that points to the root
	Post:
	Return:
	*/
	void inOrder(BstNode<T>* base, std::ostream& ofile);
	/*
	Pre: Takes in an outstream for file output and a BstNode ptr that points to the root
	Post:
	Return:
	*/
	void breadthFirst(BstNode<T>* base, std::ostream& ofile);
	/*
	Pre: Takes in an outstream for file output and a BstNode ptr that points to the root
	Post:
	Return:
	*/
	void preOrder(BstNode<T>* base, std::ostream& ofile);
	/*
	Pre: Takes in an outstream for file output and a BstNode ptr that points to the root
	Post:
	Return:
	*/
	void postOrder(BstNode<T>* base, std::ostream& ofile);
	/*
	Pre: Takes in a BstNode ptr
	Post:
	Return: Returns a BstNode Ptr
	*/
	BstNode<T>* getMinValue(BstNode<T>* base);
};

/*
 -- Returns root node
 */
template <typename T>
BstNode<T>* Bst<T>::GetRoot(std::ostream& ofile) {
	std::cout << "Root is: " << root << std::endl;
	ofile << "Root is: " << root << std::endl;
	return root;
}

/*
 -- Inserts data into Bst
 */
template <typename T>
BstNode<T>* Bst<T>::insert(T data, BstNode<T>* base, std::ostream& ofile) {
	if (root == NULL) {//check for empty bst
		root = new BstNode<T>();
		root->SetData(data);
		count++;
	}
	else {
		if (base == NULL) {//if base node is null we know to add a new node
			base = new BstNode<T>();
			base->data = data;
			count++;
		}
		else if (data < base->data) {
			base->left = insert(data, base->left, ofile);//moving left if smaller data
		}
		else if (data > base->data) {
			base->right = insert(data, base->right, ofile);//moving right if bigger data
		}
		else if (data == base->data) {
			std::cout << "Sorry That Value Is Already In The Tree" << std::endl;
			ofile << "Sorry That Value Is Already In The Tree" << std::endl;
		}
	}
	return base;
}

template <typename T>
BstNode<T>* Bst<T>::getMinValue(BstNode<T>* base) {//finding min
	while ((base && base->left) != NULL) {
		base = base->left;//moving left for smallest
	}
	return base;
}


/*
 -- Removes data from bst
 */
template <typename T>
BstNode<T>* Bst<T>::remove(T data, BstNode<T>* base, std::ostream& ofile) {
	if (root == NULL) {//empty check
		std::cout << "There is no data to remove";
	}
	else if (search(data, ofile) == false) {//initial search before removal
		std::cout << "Data is not in Bst" << std::endl;
	}
	else {
		if (data < base->data) {//first case
			base->left = remove(data, base->left, ofile);//move left if less
		}
		else if (data > base->data) {//second case
			base->right = remove(data, base->right, ofile);//move right if greater
		}
		else if (data == base->data) {//last case
			if (base->left == NULL && base->right != NULL) {//one child case right
				BstNode<T>* temp = base->right;
				if (base == root) {//if we are removing root we have to reset the node
					root = temp;
				}
				delete base;
				return temp;
			}
			else if (base->right == NULL && base->left != NULL) {//one child case left
				BstNode<T>* temp = base->left;
				if (base == root) {//if we are removing root we have to reset the node
					root = temp;
				}
				delete base;
				return temp;
			}
			else if (base->left == NULL && base->right == NULL) {//No children case
				if (base == root) {//if we are removing root we have to reset the node
					root = NULL;
				}
				delete base;
				return NULL;
			}

			BstNode<T>* temp = getMinValue(base->right);
			base->data = temp->data;
			base->right = remove(temp->data, base->right, ofile);
		}
	}
	return base;
}

/*
 -- Finds data in bst
 */
template <typename T>
bool Bst<T>::search(T data, std::ostream& ofile) {
	BstNode<T>* temp = new BstNode<T>;//setting temporary node equal to root
	temp = root;

	while (temp != NULL) {//loops through the tree until temp is equal to value being searched for (data)
		if (temp->data == data) {//current temp value is equal to data
			return true;
		}
		else if (temp->data > data) {//current temp value is larger than data value, so temp becomes the value on its left
			temp = temp->left;
		}
		else if (temp->data < data) {//current temp value is smaller than data value, so temp becomes the value on its right
			temp = temp->right;
		}

	}
	return false;


}


/*
 -- Returns the count of the Bst
 */
template <typename T>
int Bst<T>::getCount() {
	return count;//simple enough don't think I need to explain this one
}

/*
 -- Empties the Bst
 */
template <typename T>
void Bst<T>::emptyBst(BstNode<T>* base) {
	if (root == NULL) {
		//do nothing cuz empty
	}
	else {
		if (base == NULL) {
			return;
		}
		emptyBst(base->left);//traversing similarly to the in order I think
		emptyBst(base->right);
		delete base;
		count--;
		if (count == 0) {//root wasn't being set to null so heres this
			root = NULL;
		}
	}
}

/*
 -- Prints the Bst
 */
template <typename T>
void Bst<T>::printBst(BstNode<T>* b, std::ostream& ofile) {
	//print baby
	std::cout << "Breadth First Print: " << std::endl;
	ofile << "Breadth First Print: " << std::endl;
	breadthFirst(b, ofile);
	std::cout << std::endl;
	ofile << std::endl;
	std::cout << std::endl;
	ofile << std::endl;
	std::cout << "In Order Print: " << std::endl;
	ofile << "In Order Print: " << std::endl;
	inOrder(b, ofile);
	std::cout << std::endl;
	ofile << std::endl;
	std::cout << std::endl;
	ofile << std::endl;
	std::cout << "Pre Order Print: " << std::endl;
	ofile << "Pre Order Print: " << std::endl;
	preOrder(b, ofile);
	std::cout << std::endl;
	ofile << std::endl;
	std::cout << std::endl;
	ofile << std::endl;
	std::cout << "Post Order Print: " << std::endl;
	ofile << "Post Order Print: " << std::endl;
	postOrder(b, ofile);
}

/*
 -- Performs inOrder search/print I guess
 */
template <typename T>
void Bst<T>::inOrder(BstNode<T>* base, std::ostream& ofile) {
	if (root == NULL) {//empty check
		std::cout << "Bst is Empty" << std::endl;
		ofile << "Bst is Empty" << std::endl;
	}
	else {
		if (base == NULL) {
			return;
		}

		inOrder(base->left, ofile);//moving left
		std::cout << base->data << " ";
		ofile << base->data << " ";
		inOrder(base->right, ofile);//moving right
	}

}

/*
 -- Performs breadth-first search
 */
template <typename T>
void Bst<T>::breadthFirst(BstNode<T>* base, std::ostream& ofile) {
	if (root == NULL) {//empty check
		std::cout << "Tree is empty" << std::endl;
		ofile << "Tree is empty" << std::endl;
	}
	else {
		if (base == NULL) {//base check
			return;
		}
		queue<BstNode<currency>*> *q = new queue<BstNode<currency>*>();//need to use a queue for this one
		q->enqueue(base);

		while (q->isEmpty() == 1) {
			BstNode<currency>* first = q->peekFront()->GetData();
			std::cout << first->GetData() << " ";
			ofile << first->GetData() << " ";
			if (first->left != NULL) {//left check
				q->enqueue(first->left);//enque left
			}
			if (first->right != NULL) {//right check
				q->enqueue(first->right);//enque right
			}

			q->dequeue();//remove that B
		}
	}
}

/*
 -- Performs pre-order search
 */
template <typename T>
void Bst<T>::preOrder(BstNode<T>* base, std::ostream& ofile) {
	if (root == NULL) {//empty check
		std::cout << "Tree is empty" << std::endl;
		ofile << "Tree is empty" << std::endl;
	}
	else {
		if (base == NULL) {//base check
			return;
		}
		std::cout << base->data << " ";
		ofile << base->data << " ";
		preOrder(base->left, ofile);//moving ledt
		preOrder(base->right, ofile);//mmoving right
	}
}

/*
 -- Performs post-Order search
 */
template <typename T>
void Bst<T>::postOrder(BstNode<T>* base, std::ostream& ofile) {
	if (root == NULL) {//empty check
		std::cout << "Tree is empty" << std::endl;
		ofile << "Tree is empty" << std::endl;
	}
	else {
		if (base == NULL) {//base check
			return;
		}
		postOrder(base->left, ofile);//moving left
		postOrder(base->right, ofile);//moving right
		std::cout << base->data << " ";
		ofile << base->data << " ";
	}
}
