#ifndef LINKEDLIST
#define LINKEDLIST

#include "LinkedList.h"

template <typename T>
LinkedList<T>::LinkedList() : m_first(NULL), m_last(NULL) {};

template <typename T>
LinkedList<T>::LinkedList(T * arr, size_t size) : m_first(NULL), m_last(NULL) {
    for (size_t i = 0; i < size; i++, arr++) {
        add(*arr);
    }
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T> & other) {
    for (Node<T> * n = other.m_first; n != NULL; n = n->m_next) {
        add(n->m_value);
    }
}

template <typename T>
LinkedList<T> & LinkedList<T>::operator=(const LinkedList<T> & rhs) {
    clear();
    for (Node<T> * n = rhs.m_first; n != NULL; n = n->m_next) {
        add(n->m_value);
    }
    return *this;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

template <typename T>
T & LinkedList<T>::at(int index) {
    if (size() < index) {
        std::cout << "Index out of bounds \n";
    }

    Node<T> * currentNode = m_first;
    for (size_t i = 0; i < index; i++) {
        currentNode = currentNode->m_next;
    }

    return currentNode->m_value;
}

template <typename T>
const T & LinkedList<T>::at(int index) const {
    if (size() < index) {
        std::cout << "Index out of bounds \n";
    }

    Node<T> * currentNode = m_first;
    for (size_t i = 0; i < index; i++) {
        currentNode = currentNode->m_next;
    }

    return currentNode->m_value;
}

template <typename T>
T & LinkedList<T>::operator[](int index) {
    return at(index);
}

template <typename T>
const T & LinkedList<T>::operator[](int index) const {
    return at(index);
}

template <typename T>
int LinkedList<T>::indexOf(const T & value) const {
    if (empty()) return -1;

    int i = 0;
    for (Node<T> * n = m_first; n != NULL; n = n->m_next, i++) {
        if (n->m_value == value) {
            return i;
        }
    }
    return -1;
}

template <typename T>
void LinkedList<T>::add(const T & value) {
    if (size() == 0) {
        Node<T> * n = new Node<T>(value);
        m_first = n;
        m_last = n;
    }
    else {
        Node<T> * n = new Node<T>(value);
        m_last->m_next = n;
        m_last = m_last->m_next;
    }
};

template <typename T>
void LinkedList<T>::insert(const T & value, int index) {
    if (size() < index) {
        std::cout << "Index out of bounds \n";
        return;
    }

    if (index == size()) {
        add(value);
    }
    else {
        Node<T> * currentNode = m_first;
        for (size_t i = 0; i < index - 1; i++) {
            currentNode = currentNode->m_next;
        }

        Node<T> * newNode = new Node<T>(value);
        newNode->m_next = currentNode->m_next;
        currentNode->m_next = newNode;
    }
};

template <typename T>
T LinkedList<T>::removeAt(int index) {
    size_t count = size();
    T val = T();

    if (index >= count) {
        std::cout << "Index out of bounds \n";
        return val;
    }

    Node<T> * removedNode;
    if (index == 0) {
        removedNode = m_first;
        val = m_first->m_value;
        m_first = m_first->m_next;
    }
    else {
        Node<T> * currentNode = m_first;
        for (size_t i = 0; i < index - 1; i++) {
            currentNode = currentNode->m_next;
        }
        removedNode = currentNode->m_next;
        if (removedNode == m_last) {
            m_last = currentNode;
        }
        val = removedNode->m_value;
        currentNode->m_next = currentNode->m_next->m_next;
    }

    delete removedNode;
    return val;
}

template <typename T>
T LinkedList<T>::remove(const T & value) {
    T val = T();
    Node<T> * removedNode = NULL;

    if (size() == 0) {
        std::cout << "Index out of bounds \n";
        return val;
    }
   
    if (m_first->m_value == value) {
        removedNode = m_first;
        val = m_first->m_value;
        m_first = m_first->m_next;
    }
    else {
        Node<T> * currentNode = m_first;
        while (currentNode->m_next != NULL && currentNode->m_next->m_value != value) {
            currentNode = currentNode->m_next;
        }
        removedNode = currentNode->m_next;
        if (removedNode == NULL) {
            std::cout << value << " could not be found \n";
            return val;
        }
        val = removedNode->m_value;
        currentNode->m_next = currentNode->m_next->m_next;
    }

    delete removedNode;
    return val;
}

template <typename T>
void LinkedList<T>::clear() {
    while (m_first != NULL) {
        Node<T> * previous = m_first;
        m_first = m_first->m_next;
        delete previous;
    } 
}

template <typename T>
size_t LinkedList<T>::size() const {
    size_t count = 0;
    for (Node<T> * n = m_first; n != NULL; n = n->m_next, count++);
    return count;
}

template <typename T>
bool LinkedList<T>::full() const {
    return false;
}

template <typename T>
bool LinkedList<T>::empty() const {
    return size() == 0;
}

template <typename T>
void LinkedList<T>::serialize(std::ostream & os) const {
    os << "{";
    for (Node<T> * n = m_first; n != NULL; n = n->m_next) {
        os << n->m_value;
        if (n->m_next != NULL) {
            os << ", ";
        }
    }
    os << "}";
}

#endif