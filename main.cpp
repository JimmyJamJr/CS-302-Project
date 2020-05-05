// CS 302 - Final Project
// 4/29/20

#include <iostream>
#include <fstream>
#include <ios>
#include <memory>
#include <string>
#include <sstream>
#include "Graph.h"

const int COST_PER_MILE = 40;
const int CITY_COUNT = 5;

void createGraph(std::shared_ptr<Graph<std::string> > graph);


int main() {
    std::shared_ptr<Graph<std::string> > graph = std::make_shared<Graph<std::string> >();
    createGraph(graph);

    std::cout << graph->getVertex(0)->getValue() << "\n";
    for (int i = 0; i < graph->getVertex(0)->getEdgeCount(); i++) {
        std::cout << graph->getVertex(0)->getEdge(i)->getDest()->getValue() << " " << graph->getVertex(0)->getEdge(i)->getCost() << "\n";
    }
}

void createGraph(std::shared_ptr<Graph<std::string> > graph) {
    std::ifstream file("data.txt");
    std::cout << "Reading data file...\n";
    std::string line;

    // Set up vertexes
    while (std::getline(file, line)) {
        std::string startingCity(line);
        graph->addVertex(std::make_shared<Vertex<std::string> >(line));

        for (int i = 0; i < CITY_COUNT; i++) {
            std::getline(file, line);
        }

    }

    file.clear();
    file.seekg(0, std::ios::beg);

    while (!file.eof()) {
        std::getline(file, line);
        std::shared_ptr<Vertex<std::string> > v = graph->getVertex(line);

        for (int i = 0; i < CITY_COUNT - 1; i++) {
            std::getline(file, line);
            std::stringstream ss;
            int distance;

            std::string temp;
            std::stringstream lineStream(line);
            while (lineStream >> temp) {
                try {
                    distance = std::stoi(temp);
                }
                catch (std::invalid_argument const & e) {
                    ss << ((ss.str().length() == 0) ? temp : " " + temp);
                }
            }
            
            std::shared_ptr<Edge<std::string> > edge(new Edge<std::string>(distance * COST_PER_MILE, graph->getVertex(ss.str())));
            v->addEdge(edge);

        }

        std::getline(file, line);
    }

}

