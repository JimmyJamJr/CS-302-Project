#ifndef EDGE_H
#define EDGE_H

#include "Vertex.h"

template <class T> class Vertex;

template <class T>
class Edge
{
public:
	Edge(int cost, Vertex<T>* dest);

	Vertex<T>* getDest() const;
	int getCost() const;

	void setDest(Vertex<T>* newDest);
	void setCost(int newCost);

private:
	int cost;
	Vertex<T>* dest;
};

#include "Edge.cpp"
#endif