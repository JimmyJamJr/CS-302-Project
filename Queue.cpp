#ifndef QUEUE
#define QUEUE

#include "Queue.h"

template <typename T>
Queue<T>::Queue() : m_front(NULL), m_back(NULL) {}

template <typename T>
Queue<T>::Queue(const Queue<T> & other) : m_front(NULL), m_back(NULL) {
    for (Node<T> * n = other.m_front; n != NULL; n = n->m_next) {
        enqueue(n->m_value);
    }
}

template <typename T>
Queue<T>::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}

template <typename T>
bool Queue<T>::enqueue(const T & item) {
    if (isEmpty()) {
        m_back = new Node<T>(item);
        m_front = m_back;
    }
    else {
        m_back->m_next = new Node<T>(item);
        m_back = m_back->m_next;
    }
    return true;
}

template <typename T>
bool Queue<T>::dequeue() {
    if (isEmpty()) return false;
    Node<T> * n = m_front;
    m_front = m_front->m_next;
    delete n;
    return true;
}

template <typename T>
bool Queue<T>::isEmpty() const {
    return m_front == NULL;
}

template <typename T>
int Queue<T>::count() const {
    if (isEmpty()) return 0;
    int count = 0;
    for (Node<T> * n = m_front; n != NULL; n = n->m_next) {
        count++;
    }
    return count;
}

template <typename T>
T Queue<T>::peekFront() const {
    if (!isEmpty()) {
        return m_front->m_value;
    }
    else {
        throw "Queue is empty!";
    }
}

template <typename T>
void Queue<T>::serialize(std::ostream & os) const {
    for (Node<T> * n = m_front; n != NULL; n = n->m_next) {
        os << n->m_value << "\n";
    }
}

#endif