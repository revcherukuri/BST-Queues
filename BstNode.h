#pragma once
/*
@Lab: Lab 5 Binary Search Tree
@Authors: Casey Merritt, Revanth Cherukuri
@Purpose: Show our Knowledge of a BST
*/

#include <iostream>

template <typename T>
class BstNode {
public:
	T data;
	BstNode<T>* left;
	BstNode<T>* right;

	BstNode() {//constructor
		left = NULL;
		right = NULL;
	}

	~BstNode() {//destructor

	}

	//getters
	/*
	 Pre:
	 Post:
	 Return:returns data value reference of type T
	 */
	T& GetData();
	/*
	 Pre:
	 Post:
	 Return:returns Left node value of type type BstNode<T>*
	 */
	BstNode<T>* GetLeft();
	/*
	 Pre:
	 Post:
	 Return:returns Right node value of type type BstNode<T>*
	 */
	BstNode<T>* GetRight();
	//setters
	/*
	 Pre:gets passed data value of type T as reference
	 Post:
	 Return:
	 */
	void SetData(T& data);
	/*
	 Pre:gets passed pointer to next node value of type BstNode<T>
	 Post:
	 Return:
	 */
	void SetLeft(BstNode<T> *left);
	/*
	 Pre:gets passed pointer to next node value of type BstNode<T>
	 Post:
	 Return:
	 */
	void SetRight(BstNode<T> *right);
};

/*
-- Returns Data
*/
template <typename T>
T& BstNode<T>::GetData() {
	return data;
}

/*
-- Returns left
*/
template <typename T>
BstNode<T>* BstNode<T>::GetLeft() {
	return left;
}

/*
-- Returns right
*/
template <typename T>
BstNode<T>* BstNode<T>::GetRight() {
	return right;
}

/*
-- Sets Data
*/
template <typename T>
void BstNode<T>::SetData(T& x) {
	data = x;
}

/*
-- Sets Left Node
*/
template <typename T>
void BstNode<T>::SetLeft(BstNode<T> *x) {
	left = x;
}

/*
-- Sets Right Node
*/
template <typename T>
void BstNode<T>::SetRight(BstNode<T> *x) {
	right = x;
}
