/**************************************************************************************************
 * Defining the Node's methods
 **************************************************************************************************/

#include "Node.h"
#include <iostream>

using namespace std;


// Construtor
Node::Node(int id, string tag)
{
    this->id = id;
    this->degree = 0;
    this->firstEdge = nullptr;
    this->nextNode = nullptr;
    this->tag = tag;
};

// Destrutor
Node::~Node()
{
    Edge *nextEdge = this->firstEdge;

    while (nextEdge != nullptr)
    {
        Edge *auxEdge = nextEdge->getNextEdge();
        delete nextEdge;
        nextEdge = auxEdge;
    }

    this->id = -1;
    this->degree = 0;
    this->firstEdge = nullptr;
    this->nextNode = nullptr;
    this->tag = " ";
};

// Getters
Edge *Node::getFirstEdge()
{
    return this->firstEdge;
}

Edge *Node::getLastEdge()
{
    return this->lastEdge;
}

int Node::getId() const
{
    return this->id;
}

int Node::getDegree()
{
    return this->degree;
}

Node *Node::getNextNode()
{
    return this->nextNode;
}

string Node::getTag()
{
    return this->tag;
}

// Setters
void Node::setNextNode(Node *nextNode)
{
    this->nextNode = nextNode;
}

//Other Methods
void Node::incrementDegree()
{
    this->degree++;
}

void Node::insertEdge(int sourceId, int targetId, int direction)
{
    // Verifies whether there are at least one edge in the node
    if (this->firstEdge != nullptr)
    {
        // Allocating the new edge and keeping the integrity of the edge list
        Edge *edge = new Edge(sourceId, targetId);
        edge->setDirection(direction);
        this->lastEdge->setNextEdge(edge);
        this->lastEdge = edge;
    }
    else
    {
        // Allocating the new edge and keeping the integrity of the edge list
        this->firstEdge = new Edge(sourceId, targetId);
        this->firstEdge->setDirection(direction);
        this->lastEdge = this->firstEdge;
    }
}