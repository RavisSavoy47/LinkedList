#pragma once
#include "Iterator.h"
#include <iostream>

template <typename T>
class List
{
public:
	List();
	List(const List<T>& other);
	~List();

	/// <summary>
	/// Delets all nodes in the list
	/// </summary>
	void destroy();

	/// <summary>
	/// Returns an iterator pointing to the first node in the list
	/// </summary>
	/// <returns></returns>
	const Iterator<T> begin() const;

	/// <summary>
	/// returns the next item after the last node in the list
	/// </summary>
	/// <returns></returns>
	const Iterator<T> end() const;

	/// <summary>
	/// checks to see if the given item is in the list
	/// </summary>
	/// <param name="object"></param>
	/// <returns></returns>
	bool contains(const T object) const;

	/// <summary>
	/// adds a new node to the beginning of the list
	/// </summary>
	/// <param name="value"></param>
	void pushFront(const T& value);

	/// <summary>
	/// adds a new node to the end of the list
	/// </summary>
	/// <param name="value"></param>
	void pushBack(const T& value);

	/// <summary>
	/// adds a new node at the given index
	/// </summary>
	/// <param name="value"></param>
	/// <param name="index"></param>
	/// <returns></returns>
	bool insert(const T& value, int index);

	/// <summary>
	/// remove all nodes with the given value
	/// </summary>
	/// <param name="value"></param>
	/// <returns></returns>
	bool remove(const T& value);

	/// <summary>
	/// prints the values for all the nodes
	/// </summary>
	void print() const;

	/// <summary>
	/// set the default values for the first node pointer, the last node pointer, and the node count
	/// </summary>
	void intialize();

	/// <summary>
	/// returns whether or not the list has any nodes in it
	/// </summary>
	/// <returns></returns>
	bool isEmpty() const;

	/// <summary>
	/// sets the given iterator to point to a node at the given index
	/// </summary>
	/// <param name="iter"></param>
	/// <param name="index"></param>
	/// <returns></returns>
	bool getData(Iterator<T>& iter, int index);

	/// <summary>
	/// returns the amount of nodes in the list
	/// </summary>
	/// <returns></returns>
	int getLength() const;

	const List<T>& operator=(const List<T>& otherList);

	void sort();

private:
	Node<T>* m_first;
	Node<T>* m_last;
	int m_nodeCount;

};

/// <summary>
/// sets the first and last to null pointer
/// sets the nodeCounter back to 0
/// </summary>
template<typename T>
inline List<T>::List()
{
	m_nodeCount = 0;
	m_first = nullptr;
	m_last = nullptr;
}

template<typename T>
inline List<T>::List(const List<T>& other)
{
	
}

/// <summary>
/// the deconstructor to remove all nodes
/// </summary>
template<typename T>
inline List<T>::~List()
{
	destroy();
}

/// <summary>
/// destroys all the nodes 
/// </summary>
template<typename T>
inline void List<T>::destroy()
{
	//makes a new node and a temp and removes the temp 
	for (Node<T>* iter = m_first; iter != nullptr;)
	{
		Node<T>* temp = iter;
		iter = iter->next;
		delete temp;
	}
	
	//resets the values
	intialize();
}

/// <summary>
/// the start of the list
/// </summary>
template<typename T>
inline const Iterator<T> List<T>::begin() const
{
	return Iterator<T>(m_first);
}

/// <summary>
/// the end of the list
/// </summary>
template<typename T>
inline const Iterator<T> List<T>::end() const
{
	return Iterator<T>(m_last->next);
}

/// <summary>
/// checks if the oblect is in the list
/// </summary>
template<typename T>
inline bool List<T>::contains(const T object) const
{
	//creates a iterator 
	for (Iterator<T> iter = begin(); iter != end(); ++iter)
	{
		//makes the iterator an object
		if (*iter == object)
			return true;
	}

	return false;
}

/// <summary>
/// pushes the node in front of the first
/// </summary>
template<typename T>
inline void List<T>::pushFront(const T& value)
{
	/// <summary>
	/// creates a new node
	/// sets the first's previous to be node
	/// sets the node's next to be first 
	/// sets node to be first
	/// </summary>
	Node<T>* node = new Node<T>(value);
	
	m_first->previous = node;
	node->next = m_first;
	m_first = node;

	m_nodeCount++;
}

/// <summary>
/// pushes the node back 
/// </summary>
template<typename T>
inline void List<T>::pushBack(const T& value)
{
	/// <summary>
	/// creates a new node
	/// sets the last's previous to be the node
	/// sets the node's next to be last
	/// sets last to be the node
	/// </summary>
	Node<T>* node = new Node<T>(value);

	m_last->previous = node;
	node->next = m_last;
	m_last = node;

	m_nodeCount++;
}

/// <summary>
/// adds a new node to the list
/// </summary>
template<typename T>
inline bool List<T>::insert(const T& value, int index)
{
	if (index < 0 || index >= m_nodeCount)
		return false;

	//creates a new node
	//gets the oldNode to be the first
	Node<T>* newNode = new Node<T>(value);
	Node<T>* oldNode = m_first;

	//iterates through the index
	for (int i = 0; i < index; i++)
	{
		//sets the oldnode next to always be oldnode next
		if (oldNode->next)
			oldNode = oldNode->next;
	}

	//sets the oldnode previous next to be the newnode
	if (oldNode->previous)
		oldNode->previous->next = newNode;

	/// <summary>
	/// sets the newnodes previous to be the oldnode previous
	/// sets the oldnode previous to be the newnode
	/// sets the newnode next to be the oldnode
	/// </summary>
	newNode->previous = oldNode->previous;
	oldNode->previous = newNode;
	newNode->next = oldNode;

	m_nodeCount++;

	//sets the first to be the newnode
	if (index == 0)
		m_first = newNode;
	//sets the last to be newnode
	else if (index == m_nodeCount - 1)
		m_last = newNode;

	return true;
}

/// <summary>
/// removes the node from the list
/// </summary>
template<typename T>
inline bool List<T>::remove(const T& value)
{
	Node<T>* nodeToRemove = m_first;

	//removes the node and resets its values 
	if (m_first->data == value && m_nodeCount == 1)
	{
		delete nodeToRemove;
		intialize();
		return true;
	}

	bool nodeisRemoved = false;

	//iterates through the node count
	for (int i = 0; i < m_nodeCount; i++)
	{
		//iterates through the nodes data
		if (nodeToRemove->data == value)
		{
			//sets its node previous's next to be the nodes nexst
			if (nodeToRemove->previous)
				nodeToRemove->previous->next = nodeToRemove->next;
			//sets its node next's previous to be the nodes previous
			if (nodeToRemove->next)
				nodeToRemove->next->previous = nodeToRemove->previous;

			//sets the last to be the nodes next
			if (nodeToRemove == m_last)
				m_last = nodeToRemove->next;
			//sets the first to be the nodes previous
			else if (nodeToRemove == m_first)
				m_first = nodeToRemove->previous;

			nodeisRemoved = true;
			break;
		}

		//sets the nodes next to be the nodes next
		if (nodeToRemove->next)
			nodeToRemove = nodeToRemove->next;
	}
	//deletes the node
	if (nodeisRemoved)
	{
		delete nodeToRemove;
		m_nodeCount--;
	}

	return nodeisRemoved;
}

/// <summary>
/// prints to the screen
/// </summary>
template<typename T>
inline void List<T>::print() const
{
	if (m_nodeCount <= 0) return;

	for (Iterator<T> iter = begin(); iter != end(); ++iter)
		std::cout << *iter << std::endl;
}

/// <summary>
/// iniatlize the values
/// </summary>
template<typename T>
inline void List<T>::intialize()
{
	m_nodeCount = 0;
	m_first = nullptr;
	m_last = nullptr;
}

//checks if the node count is empty
template<typename T>
inline bool List<T>::isEmpty() const
{
	return m_nodeCount <= 0;
}

/// <summary>
/// gets the data from the index
/// </summary>
template<typename T>
inline bool List<T>::getData(Iterator<T>& iter, int index)
{
	if (index < 0 || index >= m_nodeCount)
		return false;

	for (int i = 0; i < index; i++)
		++iter;


	return true;
}

template<typename T>
inline int List<T>::getLength() const
{
	return m_nodeCount;
}

template<typename T>
inline const List<T>& List<T>::operator=(const List<T>& otherList)
{
	m_first = otherList.m_first;
	m_last = otherList.m_last;
}

template<typename T>
inline void List<T>::sort()
{
	//bubble scort
}
