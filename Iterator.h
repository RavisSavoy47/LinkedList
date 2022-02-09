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
	if (m_current->next == nullptr)
		return Iterator<T>(m_current);
	else
		return Iterator<T>(m_current = m_current->next);
}

/// <summary>
/// iterates to the previous node
/// </summary>
template<typename T>
inline Iterator<T> Iterator<T>::operator--()
{
	if (m_current->previous == nullptr)
		return Iterator<T>(m_current);
	else
		return Iterator<T>(m_current = m_current->previous);
}

/// <summary>
/// sets the iter current to be equal to the current
/// </summary>
template<typename T>
inline const bool Iterator<T>::operator==(const Iterator<T>& iter)
{
	return m_current->data == iter.m_current->data &&
		m_current->next == iter.m_current->next &&
		m_current->previous == iter.m_current->previous;
}

/// <summary>
/// checks if the iter current is not equal to current
/// </summary>
template<typename T>
inline const bool Iterator<T>::operator!=(const Iterator<T>& iter)
{
	return !(m_current->data == iter.m_current->data &&
		m_current->next == iter.m_current->next &&
		m_current->previous == iter.m_current->previous);
}

/// <summary>
/// derefences the currents data
/// </summary>
template<typename T>
inline T Iterator<T>::operator*()
{
	return m_current->data;
}
