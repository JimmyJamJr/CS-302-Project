// Jimson Huang
// CS 302 - 1001
// Project 2
// 2/17/2020

#ifndef NODE
#define NODE

#include "Node.h"

template <typename T>
Node<T>::Node() : m_next(NULL), m_value(NULL) {}

template <typename T>
Node<T>::Node(const T & val) : m_next(NULL), m_value(val) {}

template <typename T>
Node<T>::Node(const Node<T> * node) : m_next(node->m_next), m_value(node->m_value) {}

#endif