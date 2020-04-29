#ifndef NODE_H
#define NODE_H

#include <iostream>

template <typename T>
class Node {
    public:
        Node();
        Node(const T & val);
        Node(const Node<T> * node);

        Node<T> * m_next;
        T m_value;
};

#include "Node.cpp"

#endif