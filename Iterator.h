#pragma once
#include "Node.h"

template <typename T>
class Iterator
{
public:
	Iterator();
	Iterator(Node<T>* node);

	Iterator<T> operator++();
	Iterator<T> operator--();
	const bool operator==(const Iterator<T>& iter);
	const bool operator!=(const Iterator<T>& iter);
	T operator*();

private:
	Node<T>* m_current;
};

/// <summary>
/// sets current to a null pointer
/// </summary>
template<typename T>
inline Iterator<T>::Iterator()
{
	m_current = nullptr;
}

/// <summary>
/// sets current to be a node
/// </summary>
template<typename T>
inline Iterator<T>::Iterator(Node<T>* node)
{
	m_current = node;
}

/// <summary>
/// iterates to the next node
/// </summary>
template<typename T>
inline Iterator<T> Iterator<T>::operator++()
{
	return *this = Iterator<T>(m_current->next);
}

/// <summary>
/// iterates to the previous node
/// </summary>
template<typename T>
inline Iterator<T> Iterator<T>::operator--()
{
	return *this = Iterator<T>(m_current->previous);
}

/// <summary>
/// sets the iter current to be equal to the current
/// </summary>
template<typename T>
inline const bool Iterator<T>::operator==(const Iterator<T>& iter)
{
	return iter.m_current == m_current;
}

/// <summary>
/// checks if the iter current is not equal to current
/// </summary>
template<typename T>
inline const bool Iterator<T>::operator!=(const Iterator<T>& iter)
{
	return iter.m_current != m_current;
}

/// <summary>
/// derefences the currents data
/// </summary>
template<typename T>
inline T Iterator<T>::operator*()
{
	return m_current->data;
}
