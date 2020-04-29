#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"

template <typename T>
class Queue {
    public:
        Queue();
        Queue(const Queue<T> & other);
        ~Queue();

        bool isEmpty() const;
        bool enqueue(const T & item);
        bool dequeue();
        T peekFront() const;
        int count() const;

        void serialize(std::ostream & os) const;
        friend std::ostream & operator<<(std::ostream & os, const Queue<T> & queue) {
            queue.serialize(os);
            return os;
        }

    private:
        Node<T> * m_front;
        Node<T> * m_back;
};

#include "Queue.cpp"

#endif