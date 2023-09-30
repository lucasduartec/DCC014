/**************************************************************************************************
 * Defining the Edge's methods
 **************************************************************************************************/

#include "Edge.h"
#include <iostream>

using namespace std;

// Construtor
Edge::Edge(int sourceId, int targetId, string direction)
{
    this->sourceId = sourceId;
    this->targetId = targetId;
    this->nextEdge = nullptr;
    this->direction = direction;
}

// Destrutor
Edge::~Edge()
{
    this->sourceId = -1;
    this->targetId = -1;
    this->nextEdge = nullptr;
    this->direction = "";
}

// Getters
int Edge::getSourceId() { return this->sourceId; }
int Edge::getTargetId() { return this->targetId; }
Edge *Edge::getNextEdge() { return this->nextEdge; }
string Edge::getDirection() { return this->direction; }

// Setters
void Edge::setNextEdge(Edge *edge) { this->nextEdge = edge; }
void Edge::setDirection(string direction) { this->direction = direction; }
