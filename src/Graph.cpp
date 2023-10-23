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

Node *Graph::insertNode(string tag, string position)
{
    Node *newNode = new Node(nodeIdCounter++, tag, position);
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

void Graph::insertEdge(Node *sourceNode, Node *targetNode, int direction)
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

void Graph::displayGraph()
{
    Node *currentNode = firstNode;
    while (currentNode != nullptr)
    {
        cout << "Node ID: " << currentNode->getId() << ", Tag: " << currentNode->getTag() << endl;

        Edge *currentEdge = currentNode->getFirstEdge();
        while (currentEdge != nullptr)
        {
            cout << "  -> Edge: Source ID: " << currentEdge->getSourceId() << ", Target ID: " << currentEdge->getTargetId() << ", Direction: " << currentEdge->getDirection() << endl;
            currentEdge = currentEdge->getNextEdge();
        }

        currentNode = currentNode->getNextNode();
    }
}

void Graph::generateLabyrinth()
{
    Node *node0 = this->insertNode("inicial", "");
    Node *node1 = this->insertNode("intermediario");
    Node *node2 = this->insertNode("intermediario");
    Node *node3 = this->insertNode("intermediario");
    Node *node4 = this->insertNode("intermediario");
    Node *node5 = this->insertNode("intermediario");
    Node *node6 = this->insertNode("intermediario");
    Node *node7 = this->insertNode("intermediario");
    Node *node8 = this->insertNode("intermediario");
    Node *node9 = this->insertNode("intermediario");
    Node *node10 = this->insertNode("intermediario");
    Node *node11 = this->insertNode("intermediario");
    Node *node12 = this->insertNode("intermediario");
    Node *node13 = this->insertNode("intermediario");
    Node *node14 = this->insertNode("intermediario");
    Node *node15 = this->insertNode("intermediario");
    Node *node16 = this->insertNode("intermediario");
    Node *node17 = this->insertNode("intermediario");
    Node *node18 = this->insertNode("intermediario");
    Node *node19 = this->insertNode("intermediario");
    Node *node20 = this->insertNode("intermediario");
    Node *node21 = this->insertNode("intermediario");
    Node *node22 = this->insertNode("intermediario");
    Node *node23 = this->insertNode("intermediario");
    Node *node24 = this->insertNode("intermediario");
    Node *node25 = this->insertNode("intermediario");
    Node *node26 = this->insertNode("intermediario");
    Node *node27 = this->insertNode("intermediario");
    Node *node28 = this->insertNode("intermediario");
    Node *node29 = this->insertNode("intermediario");
    Node *node30 = this->insertNode("intermediario");
    Node *node31 = this->insertNode("intermediario");
    Node *node32 = this->insertNode("intermediario");
    Node *node33 = this->insertNode("intermediario");
    Node *node34 = this->insertNode("intermediario");
    Node *node35 = this->insertNode("intermediario");
    Node *node36 = this->insertNode("intermediario");
    Node *node37 = this->insertNode("intermediario");
    Node *node38 = this->insertNode("intermediario");
    Node *node39 = this->insertNode("intermediario");
    Node *node40 = this->insertNode("final");

    // 0 -- cima
    // 1 -- esq
    // 2 -- baixo
    // 3 -- direita

    this->insertEdge(node0, node1, 3);
    this->insertEdge(node1, node2, 2);
    this->insertEdge(node2, node3, 1);
    this->insertEdge(node0, node4, 2);
    this->insertEdge(node4, node5, 3);
    this->insertEdge(node5, node6, 2);
    this->insertEdge(node6, node7, 3);
    this->insertEdge(node7, node8, 0);
    this->insertEdge(node8, node9, 3);
    this->insertEdge(node6, node10, 1);
    this->insertEdge(node10, node11, 2);
    this->insertEdge(node11, node12, 3);
    this->insertEdge(node12, node13, 0);
    this->insertEdge(node13, node14, 3);
    this->insertEdge(node14, node15, 2);
    this->insertEdge(node15, node16, 3);
    this->insertEdge(node14, node17, 0);
    this->insertEdge(node17, node18, 3);
    this->insertEdge(node18, node19, 2);
    this->insertEdge(node19, node20, 3);
    this->insertEdge(node17, node21, 0);
    this->insertEdge(node21, node22, 1);
    this->insertEdge(node22, node23, 0);
    this->insertEdge(node23, node24, 3);
    this->insertEdge(node24, node25, 2);
    this->insertEdge(node25, node26, 3);
    this->insertEdge(node26, node27, 2);
    this->insertEdge(node27, node28, 3);
    this->insertEdge(node28, node29, 0);
    this->insertEdge(node26, node30, 0);
    this->insertEdge(node30, node31, 3);
    this->insertEdge(node31, node32, 2);
    this->insertEdge(node32, node33, 1);
    this->insertEdge(node33, node34, 2);
    this->insertEdge(node34, node35, 3);
    this->insertEdge(node35, node36, 0);
    this->insertEdge(node34, node37, 1);
    this->insertEdge(node37, node38, 2);
    this->insertEdge(node38, node39, 1);
    this->insertEdge(node38, node40, 3);
}
