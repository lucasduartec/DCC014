/**************************************************************************************************
 * Implementation of the TAD Edge
 **************************************************************************************************/

#ifndef EDGE_H
#define EDGE_H

#include <string>

using namespace std;

class Edge
{
private:

    int sourceId; //Id do nó de origem
    int targetId;   //Id do nó destino
    int direction;  //Cima, baixo, esquerda ou direita
    Edge *nextEdge; // Ponteiro para pŕoxima aresta

public:
    Edge(int sourceId, int targetId);
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
