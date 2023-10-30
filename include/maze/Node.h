/**************************************************************************************************
 * Implementation of the TAD Node
 **************************************************************************************************/

#ifndef NODE_H
#define NODE_H

#include "Edge.h"
#include <list>

using namespace std;

// Definição da classe nó

class Node
{
    // attributes
private:
    Edge *firstEdge;
    Edge *lastEdge;
    int id;
    Node *nextNode;
    unsigned int degree; // verificar se ele já tem o maximo de filhos (4)
    string tag;          // inicial ou final
    string position;     // posição para o graphviz

public:
    // Constructor
    Node(int id, string tag, string position);

    // Destructor
    ~Node();

    // Getters
    Edge *getFirstEdge();
    Edge *getLastEdge();
    int getId() const;
    int getDegree();
    Node *getNextNode();
    string getTag();
    string getPosition();

    // Setters
    void setNextNode(Node *node);

    // Other methods
    void incrementDegree();

    // Manipulation methods
    void insertEdge(int sourceId, int targetId, int direction);
};

// Construtor
Node::Node(int id, string tag, string position)
{
    this->id = id;
    this->degree = 0;
    this->firstEdge = nullptr;
    this->nextNode = nullptr;
    this->tag = tag;
    this->position = position;
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
    this->position = " ";
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

// Other Methods
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

string Node::getPosition()
{
    return this->position;
}

#endif // NODE_H
