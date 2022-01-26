#pragma once
#include "Iterator.h"
#include "Node.h"

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
	const Iterator<T> begin();

	/// <summary>
	/// returns the next item after the last node in the list
	/// </summary>
	/// <returns></returns>
	const Iterator<T> end();

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

template<typename T>
inline List<T>::List()
{
}

template<typename T>
inline List<T>::List(const List<T>& other)
{
}

template<typename T>
inline List<T>::~List()
{
}

template<typename T>
inline void List<T>::destroy()
{
}

template<typename T>
inline const Iterator<T> List<T>::begin()
{

	return Iterator<T>();
}

template<typename T>
inline const Iterator<T> List<T>::end()
{
	return Iterator<T>();
}

template<typename T>
inline bool List<T>::contains(const T object) const
{
	return false;
}

template<typename T>
inline void List<T>::pushFront(const T& value)
{
}

template<typename T>
inline void List<T>::pushBack(const T& value)
{
}

template<typename T>
inline bool List<T>::insert(const T& value, int index)
{
	return false;
}

template<typename T>
inline bool List<T>::remove(const T& value)
{
	return false;
}

template<typename T>
inline void List<T>::print() const
{
}

template<typename T>
inline void List<T>::intialize()
{
}

template<typename T>
inline bool List<T>::isEmpty() const
{
	return false;
}

template<typename T>
inline bool List<T>::getData(Iterator<T>& iter, int index)
{
	return false;
}

template<typename T>
inline int List<T>::getLength() const
{
	return m_nodeCount;
}

template<typename T>
inline const List<T>& List<T>::operator=(const List<T>& otherList)
{
	// TODO: insert return statement here
}

template<typename T>
inline void List<T>::sort()
{
	//bubble scort
}
