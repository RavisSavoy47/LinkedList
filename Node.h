#pragma once

template <typename T>
class Node
{
public:
	Node();
	Node(T value);

	Node<T>* next;
	Node<T>* previous;
	T data;
};

/// <summary>
/// sets the next and previous to a null pointer
/// </summary>
template<typename T>
inline Node<T>::Node()
{
	next = nullptr; 
	previous = nullptr;
}

/// <summary>
/// sets the next and previous to a null pointer
/// sets the data to be the values
/// </summary>
template<typename T>
inline Node<T>::Node(T value)
{
	data = value;
	next = nullptr;
	previous = nullptr;
}
