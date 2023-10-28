/**************************************************************************************************
 * Defining the Edge's methods
 **************************************************************************************************/

#include "Edge.h"
#include <iostream>

using namespace std;

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
