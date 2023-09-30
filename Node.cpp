/**************************************************************************************************
 * Defining the Node's methods
 **************************************************************************************************/

#include "Node.h"
#include "Edge.h"
#include <iostream>

using namespace std;


// Construtor
Node::Node(int id)
{
    this->id = id;
    this->degree = 0;
    this->firstEdge = nullptr;
    this->nextNode = nullptr;
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
};

// Getters
Edge *Node::getFirstEdge()
{
    return this->firstEdge;
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

//TODO
// void Node::insertEdge(int sourceId, int targetId, string direction);

