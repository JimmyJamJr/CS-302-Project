#ifndef VERTEX_H
#define VERTEX_H

#include "LinkedList.h"
#include "Edge.h"

template <class T> class Edge;

template <class T>
class Vertex
{
public:
	Vertex(T data);

	void addEdge(Edge<T>& newEdge);
	void clearEdges();

	void setValue(T data);

	T getValue() const;
	int getEdgeCount() const;
	Edge<T> getEdge(int i) const;

private:
	T m_value;
	LinkedList<Edge<T>> edges;
};

#include "Vertex.cpp"
#endif