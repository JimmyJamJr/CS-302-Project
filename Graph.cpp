#ifndef GRAPH_CPP
#define GRAPH_CPP
#include "Graph.h"

template <class T>
Graph<T>::Graph()
{

}

template <class T>
Vertex<T>& Graph<T>::getVertex(int i) const { return vertices[i]; }

template <class T>
void Graph<T>::addVertex(const Vertex<T>& v)
{
	vertices.add(v);
}

template <class T>
void Graph<T>::addVertex(const T data)
{
	Vertex<T> v(data);
	addVertex(v);
}

template <class T>
int Graph<T>::verticesLength() const 
{ 
	return vertices.size(); 
}

template <class T>
void Graph<T>::setupEdges() 
{  
	for (int i = 0; i < vertices.size(); i++)
	{

	}
}

template <class T>
double Graph<T>::getCost(int one, int two)
{
	
}

#endif