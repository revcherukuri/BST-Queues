/*
@Lab: Lab 5 Binary Search Tree
@Authors: Casey Merritt, Revanth Cherukuri
@Purpose: Show our Knowledge of Linked Lists
*/

#ifndef linkedlist_h
#define linkedlist_h

#include "linkednode.h"
#include <iostream>

using namespace std;

template <typename T>
class LinkedList {
private:
	LinkedNode<T> *start, *end;
	int count;

public:
	LinkedList() {//constructor
		start = NULL;
		end = NULL;
		count = 0;
	}

	~LinkedList() {//destructor
		//I think there will be a memory leak here if we dont iterate through and delete everything
		//idk tho i'll look into it more

		if (start != NULL) {
			emptyList();//nvm this should work I think LOL
		}
	}

	//getters
	/*
	 Pre:
	 Post:
	 Return:function returns first node of type LinkedNode<T>*
	 */
	LinkedNode<T>* GetStart();
	/*
	 Pre:
	 Post:
	 Return:function returns last node of type LinkedNode<T>*
	 */
	LinkedNode<T>* GetEnd();
	/*
	 Pre:
	 Post:
	 Return:returns count value as integer
	 */
	int GetCount();

	/*
	 Pre:gets passed data value of type T
	 Post:Calls SetData and passes data value, calls SetNext and passes a temporary variable holding starting node
	 Return:
	 */
	void insert_start(T data);
	/*
	 Pre:gets passed data value of type T
	 Post:Calls SetData and passes data value, calls SetNext and passes a temporary variable holding ending node
	 Return:
	 */
	void insert_end(T data);
	/*
	 Pre:gets passes data value of type T and position value of type integer
	 Post:Calls SetData and passes data value, calls SetNext and passes node n, and another time passing value next of start
	 Return:
	 */
	void insert_pos(T data, int pos);
	/*
	 Pre:gets passed position value of type integer
	 Post:
	 Return:
	 */
	void remove(int pos);
	/*
	 Pre:gets passed data value of type T
	 Post:
	 Return:
	 */
	void findData(T data);
	/*
	 Pre:
	 Post:
	 Return:
	 */
	bool isListEmpty();
	/*
	 Pre:
	 Post:
	 Return:
	 */
	void emptyList();
	/*
	 Pre:
	 Post:
	 Return:
	 */
	void printList();
};

/*
-- Gets start ptr
*/
template <typename T>
LinkedNode<T>* LinkedList<T>::GetStart() {
	return start;
}

/*
-- Gets end ptr
*/
template <typename T>
LinkedNode<T>* LinkedList<T>::GetEnd() {
	return end;
}

/*
-- Gets count
*/
template <typename T>
int LinkedList<T>::GetCount() {
	return count;
}

/*
-- Inserts value @ Start of list
*/
template <typename T>
void LinkedList<T>::insert_start(T data) {
	LinkedNode<T> *n = new LinkedNode<T>();
	n->SetData(data);

	if (start == NULL) {
		start = n;
		end = n;
	}
	else {
		LinkedNode<T>* temp = start;
		start = n;
		n->SetNext(temp);
	}
	count++;
}

/*
-- Inserts value @ End of list
*/
template <typename T>
void LinkedList<T>::insert_end(T data) {
	LinkedNode<T> *n = new LinkedNode<T>();
	n->SetData(data);

	if (start == NULL) {
		end = n;
		start = n;
	}
	else {
		LinkedNode<T>* temp = end;
		temp->SetNext(n);
		end = n;
	}
	count++;
}

/*
 --Finds the position of data inside the list
 */
template <typename T>
void LinkedList<T>::findData(T data) {
	if (start == NULL) {
		std::cout << "List Is Empty, Or Start Pointer Isn't Set" << std::endl;
	}
	else {
		LinkedNode<T>* n = start;//getting start
		for (int i = 0; i < count; i++) {
			T x = n->GetData();//get that data
			if (x == data) {//data check
				std::cout << "Data Found @ Position " << count << std::endl;
				i = count;
			}
			else if (i == (count - 1)) {//only needed if we want to print if its not found
				std::cout << "Data Not Found In List" << std::endl;
			}
			n = n->GetNext();//set to next value
		}
	}

}

/*
 --Returns true or false based on whether the list is empty or not
 */
template <typename T>
bool LinkedList<T>::isListEmpty() {
	if (start == NULL) {
		std::cout << "True" << endl;//for testing purposes
		return true;
	}
	else {
		std::cout << "False" << endl;//for testing purposes
		return false;
	}
}

/*
 --Iterates through and deletes every node.
 */
template <typename T>
void LinkedList<T>::emptyList() {
	if (start == NULL) {
		std::cout << "List Is Empty, Or Start Pointer Isn't Set" << std::endl;
	}
	else {
		LinkedNode<T>* n = start;//getting start
		for (int i = 0; i < count; i++) {//Recursion Might Be Better here I'll have to see gonna just use this for now
			LinkedNode<T>* temp = n->GetNext();//saving next node before deletion
			delete n;
			n = temp;//setting to next
		}
		start = NULL;//probably need some check to make sure it actually deleted everything
		end = NULL;
	}

}

/*
 --Iterates through and prints every node's value
 */
template <typename T>
void LinkedList<T>::printList() {
	if (start == NULL) {
		std::cout << "List Is Empty, Or Start Pointer Isn't Set" << std::endl;
	}
	else {
		LinkedNode<T>* n = start;//getting start
		for (int i = 0; i < count; i++) {//Recursion Might Be Better here I'll have to see gonna just use this for now
			T x = n->GetData();//getting data
			std::cout << "Data @ Position " << i + 1 << ": " << x << std::endl;
			n = n->GetNext();//set to next
		}
	}
}

/*
-- Inserts a value @ specified position
*/
template <typename T>
void LinkedList<T>::insert_pos(T data, int pos) {
	LinkedNode<T> *n = new LinkedNode<T>();
	n->SetData(data);
	LinkedNode<T>* temp = start;
	int i = 0;
	while (i < (pos - 1)) {
		if ((temp->GetNext()) != NULL) {
			temp = temp->GetNext();
		}
		else {
			cout << "\nCannot enter at this position\n";
		}
		i++;
	}
	if ((temp->GetNext()) != NULL) {
		LinkedNode<T>* temp2 = temp->GetNext();
		temp->SetNext(n);
		n->SetNext(temp2);
	}
	else {
		end->SetNext(n);
		end = n;
	}
	count++;
}

/*
-- Removes value @ specified position
*/
template <typename T>
void LinkedList<T>::remove(int pos) {
	LinkedNode<T>* temp0 = NULL;
	if (pos < count) {
		if (start == NULL) {
			std::cout << "List is empty, or start has not been set" << std::endl;
		}
		else {
			LinkedNode<T>* temp = start;
			int i = 0;
			if (pos == 0) {
				start = temp->GetNext();
				delete temp;
			}
			else {
				while (i < (pos - 1)) {
					temp0 = temp;
					temp = temp->GetNext();
					i++;
				}
				if (temp != end) {
					LinkedNode<T>* temp2 = temp->GetNext();
					temp->SetNext(temp2->GetNext());
					delete temp2;
				}
				else {
					end = temp0;
					delete temp;
				}
			}
		}
		count--;
	}
	else {
		cout << "Nothing to remove at this position: " << pos << endl;
	}
}



#endif /* linkedlist_h */
