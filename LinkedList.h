#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <memory>
#include "Node.h"

template <typename T>
class LinkedList {
    public:
        LinkedList();
        LinkedList(T * arr, size_t size);
        LinkedList(const LinkedList<T> & other);
        ~LinkedList();

        LinkedList<T> & operator=(const LinkedList<T> & rhs);

        // Access Methods
        T & at(int index);
        T & operator[](int index);
        const T & at(int index) const;
        const T & operator[](int index) const;

        // Add a new item to the list
        void add(const T & value);
        // Insert a item at a specific index
        void insert(const T & value, int index);
        // Remove the item at a specific index
        T removeAt(int index);
        // Removes the first occurance of a value
        T remove(const T & value);
        // Remove all items from the list
        void clear();

        // Returns the index of the first occurance of the value, -1 if not found
        int indexOf(const T & value) const;
        // Returns the number of items in the list
        size_t size() const;
        // Returns whether or not the list is full, always false (kept for compatibility)
        bool full() const;
        // Returns true if the list is empty
        bool empty() const;
        // Displays all items in the list to an output stream
        void serialize(std::ostream & os) const;
        friend std::ostream & operator<<(std::ostream & os, const LinkedList<T> & list) {
            list.serialize(os);
            return os;
        }
    private:
        std::shared_ptr<Node<T> > m_first;
        std::shared_ptr<Node<T> > m_last;
};

#include "LinkedList.cpp"

#endif
