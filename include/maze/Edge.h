/**************************************************************************************************
 * Implementation of the TAD Edge
 **************************************************************************************************/

#ifndef EDGE_H
#define EDGE_H

#include <string>

using namespace std;

// Definição da classe Edge (Aresta)
class Edge
{
private:
    // attributes
    int sourceId;
    int targetId;
    int direction;
    Edge *nextEdge;

public:
    // Construtor
    Edge(int sourceId, int targetId);

    // Destrutor
    ~Edge();

    // Getters
    int getSourceId();
    int getTargetId();
    Edge *getNextEdge();
    int getDirection();

    // Setters
    void setNextEdge(Edge *edge);
    void setDirection(int direction);
};

// Construtor
Edge::Edge(int sourceId, int targetId)
{
    this->sourceId = sourceId;
    this->targetId = targetId;
    this->nextEdge = nullptr;
    this->direction = -1;
}

// Destrutor
Edge::~Edge()
{
    this->sourceId = -1;
    this->targetId = -1;
    this->nextEdge = nullptr;
    this->direction = -1;
}

// Getters
int Edge::getSourceId() { return this->sourceId; }
int Edge::getTargetId() { return this->targetId; }
Edge *Edge::getNextEdge() { return this->nextEdge; }
int Edge::getDirection() { return this->direction; }

// Setters
void Edge::setNextEdge(Edge *edge) { this->nextEdge = edge; }
void Edge::setDirection(int direction) { this->direction = direction; }

#endif // EDGE_H
