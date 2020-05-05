#ifndef EDGE_H
#define EDGE_H

#include "Vertex.h"

template <class T> class Vertex;

template <class T>
struct Edge
{
public:
	Edge(int cost, std::shared_ptr<Vertex<T> > dest);

	std::shared_ptr<Vertex<T> > getDest() const;
	int getCost() const;

	void setDest(std::shared_ptr<Vertex<T> > newDest);
	void setCost(int newCost);

private:
	int cost;
	std::shared_ptr<Vertex<T> > dest;
};

#include "Edge.cpp"
#endif