/**************************************************************************************************
 * Defining the Graph's methods
 **************************************************************************************************/

#include "Graph.h"

using namespace std;

// Construtor
Graph::Graph()
{
    this->firstNode = this->lastNode = nullptr;
    this->nodeIdCounter = 0;
}

// Destrutor
Graph::~Graph()
{
    Node *nextNode = this->firstNode;

    while (nextNode != nullptr)
    {
        Node *auxNode = nextNode->getNextNode();
        delete nextNode;
        nextNode = auxNode;
    }

    this->nodeIdCounter = 0;
    this->firstNode = nullptr;
    this->lastNode = nullptr;
}

// Getters

int Graph::getNodeIdCounter()
{
    return this->nodeIdCounter;
}

Node *Graph::getFirstNode()
{
    return this->firstNode;
}
Node *Graph::getLastNode()
{
    return this->lastNode;
}

Node *Graph::insertNode(string tag)
{
    Node *newNode = new Node(nodeIdCounter++, tag);
    if (lastNode == nullptr)
    {
        firstNode = newNode;
        lastNode = newNode;
    }
    else
    {
        lastNode->setNextNode(newNode);
        lastNode = newNode;
    }
    return newNode;
}

void Graph::insertEdge(Node *sourceNode, Node *targetNode, string direction)
{
    if (sourceNode != nullptr && targetNode != nullptr)
    {
        int sourceNodeId = sourceNode->getId();
        int targetNodeId = targetNode->getId();
        sourceNode->insertEdge(sourceNodeId, targetNodeId, direction);
        targetNode->insertEdge(sourceNodeId, targetNodeId, direction);
        sourceNode->incrementDegree();
        targetNode->incrementDegree();
    }
}

bool Graph::searchNode(int id)
{
    return this->getNodeById(id) != nullptr;
}

Node *Graph::getNodeById(int id)
{
    Node *nextNode = this->firstNode;
    while (nextNode != nullptr)
    {
        if (nextNode->getId() == id)
            return nextNode;

        nextNode = nextNode->getNextNode();
    }
    return nullptr;
}