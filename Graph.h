#ifndef GRAPH_H
#define GRAPH_H
#include "Vertex.h"

template <class T> class Vertex;

template <class T>
class Graph
{
public:
	Graph();

	// Returns the vertex at vertices[i].
	Vertex<T>& getVertex(int i) const;

	// Adds vertex to vertices.
	void addVertex(const Vertex<T>& v);
	void addVertex(const T data);

	// Returns the length of vertices list.
	int verticesLength() const;

	// Should be called after all vertices are entered into Graph.
	void setupEdges();

	// Returns the cost of the path from vertices[one] to vertices[two].
	double getCost(int one, int two);

private:
	LinkedList<Vertex<T>> vertices;
};

#include "Graph.cpp"
#endif