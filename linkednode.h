/*
@Lab: Lab 5 Binary Search Tree
@Author: Casey Merritt, Revanth Cherukuri
@Purpose: Show our Knowledge of LinkedNodes
*/

#ifndef linkednode_h
#define linkednode_h

#include <iostream>

template <typename T>
struct LinkedNode {
private:
	T m_data;
	LinkedNode<T> *m_pNext;

public:
	LinkedNode() {//constructor
		m_pNext = NULL;
	}

	~LinkedNode() {//destructor
		//delete m_data; ----------- This broke on my computer because its not deleteing a pointer plus idk if we need anything here
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
	 Return:returns next node value of type type LinkedNode<T>*
	 */
	LinkedNode<T>* GetNext();
	//setters
	/*
	 Pre:gets passed data value of type T as reference
	 Post:
	 Return:
	 */
	void SetData(T& data);
	/*
	 Pre:gets passed pointer to next node value of type LinkedNode<T>
	 Post:
	 Return:
	 */
	void SetNext(LinkedNode<T> *next);

};

/*
-- Returns Data
*/
template <typename T>
T& LinkedNode<T>::GetData() {
	return m_data;
}

/*
-- Returns Next Node
*/
template <typename T>
LinkedNode<T>* LinkedNode<T>::GetNext() {
	return m_pNext;
}

/*
-- Sets Data
*/
template <typename T>
void LinkedNode<T>::SetData(T& data) {
	m_data = data;
}

/*
-- Sets Next Node
*/
template <typename T>
void LinkedNode<T>::SetNext(LinkedNode<T> *next) {
	m_pNext = next;
}



#endif /* linkednode_h */
