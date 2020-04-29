#ifndef STACK
#define STACK

#include "Stack.h"

template <typename T>
Stack<T>::Stack() : m_top(NULL) {}

template <typename T>
Stack<T>::Stack(const Stack<T> & other) : m_top(new Node<T>(other.m_top->m_value)) {
    Node<T> * currentNode = m_top;
    for (Node<T> * n = other.m_top->m_next; n != NULL; n = n->m_next, currentNode = currentNode->m_next) {
        currentNode->m_next = new Node<T>(n->m_value);
    }
}

template <typename T>
Stack<T> & Stack<T>::operator=(const Stack<T> & rhs) {
    clear();
    m_top = new Node<T>(rhs.m_top->m_value);

    Node<T> * currentNode = m_top;
    for (Node<T> * n = rhs.m_top->m_next; n != NULL; n = n->m_next, currentNode = currentNode->m_next) {
        currentNode->m_next = new Node<T>(n->m_value);
    }

    return *this;
}

template <typename T>
Stack<T>::~Stack() {
    clear();
}

template <typename T>
void Stack<T>::push(const T & newDataItem) {
    Node<T> * newNode = new Node<T>(newDataItem);
    newNode->m_next = m_top;
    m_top = newNode;
}

template <typename T>
T Stack<T>::peek() const {
    return m_top->m_value;
}

template <typename T>
void Stack<T>::pop() {
    Node<T> * popNode = m_top;
    m_top = m_top->m_next;
    delete popNode;
}

template <typename T>
void Stack<T>::clear() {
    while (m_top != NULL) {
        pop();
    }
}

template <typename T>
bool Stack<T>::isEmpty() const {
    return m_top == NULL;
}

template <typename T>
bool Stack<T>::isFull() const {
    return false;
}

template <typename T>
void Stack<T>::serialize(std::ostream & os) const {
    os << "{";
    for (Node<T> * n = m_top; n != NULL; n = n->m_next) {
        os << n->m_value;
        if (n->m_next != NULL) {
            os << ", ";
        }
    }
    os << "}";
}

#endif