/**************************************************************************************************
 * Implementation of the TAD Node
 **************************************************************************************************/

#ifndef NODE_H
#define NODE_H

#include "Edge.h"
#include <list>

using namespace std;

class Node
{

private:
    int id;
    Node *nextNode;
    Edge *firstEdge;
    Edge *lastEdge;
    string tag;       // Tag -> (intermediário ou final)
    bool visited;     // Flag para saber se foi visitado
    string position;  // Posição do nó no grafo
    double heuristic; // Heurística do nó

public:
    Node(int id, string tag, string position, double heuristic);
    ~Node();

    // Getters
    int getId() const;
    Node *getNextNode();
    Edge *getFirstEdge();
    Edge *getLastEdge();
    string getTag();
    int getVisited();
    string getPosition();
    double getHeuristic();

    // Setters
    void setNextNode(Node *node);
    void setVisited();

    void insertEdge(int sourceId, int targetId, int direction, double weight);

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

void Node::insertEdge(int sourceId, int targetId, int direction, double weight)
{
    // Verifies whether there are at least one edge in the node
    if (this->firstEdge != nullptr)
    {
        // Allocating the new edge and keeping the integrity of the edge list
        Edge *edge = new Edge(sourceId, targetId, weight);
        edge->setDirection(direction);
        this->lastEdge->setNextEdge(edge);
        this->lastEdge = edge;
    }
    else
    {
        // Allocating the new edge and keeping the integrity of the edge list
        this->firstEdge = new Edge(sourceId, targetId, weight);
        this->firstEdge->setDirection(direction);
        this->lastEdge = this->firstEdge;
    }
}

string Node::getPosition()
{
    return this->position;
}

#endif // NODE_H
