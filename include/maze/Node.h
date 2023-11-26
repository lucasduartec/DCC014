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
    bool visited;
    string tag;      // inicial ou final
    string position; // posição para o graphviz
    double heuristic;

public:
    // Constructor
    Node(int id, string tag, string position, double heuristic);

    // Destructor
    ~Node();

    // Getters
    Edge *getFirstEdge();
    Edge *getLastEdge();
    int getId() const;
    int getVisited();
    Node *getNextNode();
    string getTag();
    string getPosition();
    double getHeuristic();

    // Setters
    void setNextNode(Node *node);
    void setVisited();

    // Other methods

    // Manipulation methods
    void insertEdge(int sourceId, int targetId, int direction);
};

// Construtor
Node::Node(int id, string tag, string position, double heuristic)
{
    this->id = id;
    this->visited = false;
    this->firstEdge = nullptr;
    this->nextNode = nullptr;
    this->tag = tag;
    this->position = position;
    this->heuristic = heuristic;

    // cout << "Node " << this->id << " -> " << this->heuristic << endl;
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
    this->visited = false;
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

int Node::getVisited()
{
    return this->visited;
}

Node *Node::getNextNode()
{
    return this->nextNode;
}

string Node::getTag()
{
    return this->tag;
}

double Node::getHeuristic()
{
    return this->heuristic;
}

// Setters
void Node::setNextNode(Node *nextNode)
{
    this->nextNode = nextNode;
}

// Other Methods
void Node::setVisited()
{
    this->visited = true;
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
