#ifndef STACK_H
#define STACK_H

#include "Node.h"

template <typename T>
class Stack {
    public:
        Stack();
        Stack(const Stack<T> & other);

        Stack<T> & operator=(const Stack<T> & rhs);

        ~Stack();

        void push(const T & newDataItem);
        T peek() const;
        void pop();
        void clear();

        bool isEmpty() const;
        bool isFull() const;

        void serialize(std::ostream & os) const;
        friend std::ostream & operator<<(std::ostream & os, const Stack<T> & stack) {
            stack.serialize(os);
            return os;
        }
    private:
        Node<T> * m_top;
};

#include "Stack.cpp"

#endif