#pragma once
/*
@Lab: Lab 5 Binary Search Tree
@Authors: Casey Merritt, Revanth Cherukuri
@Purpose: Show our Knowledge of Queues
*/

#ifndef queue_h
#define queue_h

#include "linkedlist.h"
#include <iostream>

template <typename T>
class queue : LinkedList<T> {
private:
	LinkedNode<T> *front, *rear;
	int count;

public:
	queue() {
		front = NULL;
		rear = NULL;
		count = 0;
	}

	~queue() {
		if (front == NULL && rear == NULL) {//empty check

		}
		else {
			std::cout << "Deleting Queue" << std::endl;
			clearQueue();//clears queue if not already empty
		}
	}
	/*Pre:
	 Post:
	 Return: Function returns first node in queue of type LinkedNode<T> without removing
	 */
	LinkedNode<T>* peekFront();
	/*Pre:
	 Post:
	 Return:Returns last node in queue of type LinkedNode<T> without removing
	 */
	LinkedNode<T>* peekRear();
	/*
	 Pre:gets passed data value of type T to add to queue
	 Post:Calls SetNext and passes node n, calls SetData and passes data value
	 Return:
	 */
	void enqueue(T data);
	/*
	 Pre:
	 Post:
	 Return:
	 */
	void dequeue();
	/*
	 Pre:
	 Post:
	 Return:
	 */
	void clearQueue();
	/*
	 Pre:
	 Post:
	 Return:
	 */
	void printQueue();
	/*
	 Pre:gets passed data value of type T to locate its position
	 Post:
	 Return:
	 */
	void findValInQueue(T data);
	/*
	 Pre:gets passed specific data value of type T to remove from queue
	 Post:
	 Return:
	 */
	void removeVal(T data);

	bool isEmpty();
};


/*
-- Adds a node to the front
*/
template <typename T>
void queue<T> ::enqueue(T data) {

	LinkedNode<T>* n = new LinkedNode<T>;
	n->SetData(data);

	if (front == NULL && rear == NULL) {//empty check
		front = n;//if empty set both rear and front to new node
		rear = n;
		count++;
	}
	else {
		rear->SetNext(n);//in queue setup nodes are placed behind the rear node
		rear = n;//new node has been added so new rear has been created
		count++;
	}
}

/*
-- Removes a node from the end
*/
template <typename T>
void queue<T> ::dequeue() {
	if (front == NULL && rear == NULL) {//empty check
		std::cout << "Queue is empty" << std::endl;
	}
	else if (front == rear) {//check for single node
		delete front;//if its a single value we have to set rear to null and front to null to indicate an empty queue
		front = NULL;
		rear = NULL;
		count = 0;
	}
	else {
		LinkedNode<T>* temp = front->GetNext();//save next node
		delete front;//remove front node
		front = temp;//set front to next node
		count--;//reduce size
	}
}

/*
-- Peeks at the front of the queue
*/
template <typename T>
LinkedNode<T>* queue<T> ::peekFront() {
	if (front == NULL && rear == NULL) {//empty check
		std::cout << "Queue is empty" << std::endl;
	}
	else if (front == NULL) {//random break check
		std::cout << "Front node isn't set" << std::endl;
	}
	else {//display
//		std::cout << "Front node value is: " << front->GetData() << std::endl;
		return front;
	}
	return NULL;
}

/*
-- Peeks at the rear of the queue
*/
template <typename T>
LinkedNode<T>* queue<T> ::peekRear() {
	if (rear == NULL && front == NULL) {//empty check
		std::cout << "Queue is empty" << std::endl;
	}
	else if (rear == NULL) {//random break check
		std::cout << "Rear node isn't set" << std::endl;
	}
	else {//display
		std::cout << "Ending node value is: " << rear->GetData() << std::endl;
		return rear;
	}
	return NULL;
}

/*
-- Clears the queue
*/
template <typename T>
void queue<T> ::clearQueue() {
	if (front == NULL && rear == NULL) {//empty check
		std::cout << "Queue is empty" << std::endl;
	}
	else {
		LinkedNode<T>* n = front;
		for (int i = 0; i < count; i++) {
			LinkedNode<T>* temp = n->GetNext();//save next node
			delete n;
			n = temp;//after deletion setting to next node
		}
		front = NULL;//prob still need some sort of check here
		rear = NULL;
		count = 0;
	}
}
/*
-- Prints entire queue
*/
template <typename T>
void queue<T>::printQueue() {
	if (front == NULL && rear == NULL) {//empty check
		std::cout << "Queue is empty" << std::endl;
	}
	else {
		LinkedNode<T>* n = front;
		for (int i = 0; i < count; i++) {
			std::cout << "Value at position " << i + 1 << ": " << n->GetData() << std::endl;
			n = n->GetNext();//increment forward
		}
	}
}

/*
-- Removes specific value from queue
@notes: Not working rn, not part of hw tho so unneccessary
*/
template <typename T>
void queue<T>::removeVal(T data) {
	if (front == NULL && rear == NULL) {//empty check
		std::cout << "Queue is empty" << std::endl;
	}
	else {
		LinkedNode<T>* n = front;
		for (int i = 0; i < count; i++) {
			if (n->GetData() == data) {
				if (n == front) {
					//in theory this would delete like a normal dequeue
				}
				else {
					//not sure if this is possible in a queue setup without previous data
					//could probably set up a previous holder
				}
			}
			else {
				n = n->GetNext();//increment forward
			}
		}
	}
}

/*
-- Finds position of value specified
*/
template <typename T>
void queue<T>::findValInQueue(T data) {
	if (front == NULL && rear == NULL) {//empty check
		std::cout << "Queue is empty" << std::endl;
	}
	else {
		LinkedNode<T>* n = front;
		for (int i = 0; i < count; i++) {
			if (n->GetData() == data) {//check for value
				std::cout << "Value found @ position " << i + 1 << std::endl;
				i = count;//loop break
			}
			else if (i == (count - 1)) {
				std::cout << "Value not found in queue" << std::endl;
			}
			n = n->GetNext();//getting next value
		}
	}
}

template <typename T>
bool queue<T>::isEmpty() {//checks if queue is empty, needed to loop through queue for breadth traversal
	if (count > 0) {
		return true;//returns true if not empty
	}
	else {
		return false;//returns false if empty
	}
}
#endif /* queue_h */

