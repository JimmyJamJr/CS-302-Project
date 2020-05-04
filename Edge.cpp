#ifndef EDGE_CPP
#define EDGE_CPP

#include "Edge.h"

template <class T>
Edge<T>::Edge(int cost, Vertex<T>* dest)
{
	setDest(dest);
	setCost(cost);
}

template<class T>
Vertex<T>* Edge<T>::getDest() const { return dest; }

template<class T>
int Edge<T>::getCost() const { return cost; }

template<class T>
void Edge<T>::setCost(int newCost) { cost = newCost; }

template<class T>
void Edge<T>::setDest(Vertex<T>* newDest) { dest = newDest; }

#endif