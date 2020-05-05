#ifndef GRAPH_CPP
#define GRAPH_CPP
#include "Graph.h"

template <class T>
Graph<T>::Graph()
{

}

template <class T>
std::shared_ptr<Vertex<T> > Graph<T>::getVertex(int i) { return vertices[i]; }

template <class T>
std::shared_ptr<Vertex<T> > Graph<T>::getVertex(const T data) {
	for (int i = 0; i < vertices.size(); i++) {
		if (vertices[i]->getValue() == data) {
			return vertices[i];
		}
	}
	throw std::runtime_error("Vertex with the given data not found");
}

template <class T>
void Graph<T>::addVertex(const std::shared_ptr<Vertex<T> > v)
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