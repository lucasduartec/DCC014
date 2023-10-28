/**************************************************************************************************
 * Defining the Tree's methods
 **************************************************************************************************/

#include "Tree.h"

using namespace std;

// Construtor
Tree::Tree()
{
    this->firstNode = this->lastNode = nullptr;
    this->nodeIdCounter = 0;
}

// Destrutor
Tree::~Tree()
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

int Tree::getNodeIdCounter()
{
    return this->nodeIdCounter;
}

Node *Tree::getFirstNode()
{
    return this->firstNode;
}
Node *Tree::getLastNode()
{
    return this->lastNode;
}

Node *Tree::insertNode(string tag, string position)
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

void Tree::insertEdge(Node *sourceNode, Node *targetNode, int direction)
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

bool Tree::searchNode(int id)
{
    return this->getNodeById(id) != nullptr;
}

Node *Tree::getNodeById(int id)
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

void Tree::displayTree()
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

void Tree::generateMaze()
{
    Node *node0 = this->insertNode("inicial", "0,4");
    Node *node1 = this->insertNode("intermediario", "2,4");
    Node *node2 = this->insertNode("intermediario", "2,3");
    Node *node3 = this->insertNode("intermediario", "1,3");
    Node *node4 = this->insertNode("intermediario", "0,2");
    Node *node5 = this->insertNode("intermediario", "1,2");
    Node *node6 = this->insertNode("intermediario", "1,1");
    Node *node7 = this->insertNode("intermediario", "2,1");
    Node *node8 = this->insertNode("intermediario", "2,2");
    Node *node9 = this->insertNode("intermediario", "3,2");
    Node *node10 = this->insertNode("intermediario", "0,1");
    Node *node11 = this->insertNode("intermediario", "0,0");
    Node *node12 = this->insertNode("intermediario", "3,0");
    Node *node13 = this->insertNode("intermediario", "3,1");
    Node *node14 = this->insertNode("intermediario", "4,1");
    Node *node15 = this->insertNode("intermediario", "4,0");
    Node *node16 = this->insertNode("intermediario", "5,0");
    Node *node17 = this->insertNode("intermediario", "4,2");
    Node *node18 = this->insertNode("intermediario", "5,2");
    Node *node19 = this->insertNode("intermediario", "5,1");
    Node *node20 = this->insertNode("intermediario", "6,1");
    Node *node21 = this->insertNode("intermediario", "4,3");
    Node *node22 = this->insertNode("intermediario", "3,3");
    Node *node23 = this->insertNode("intermediario", "3,4");
    Node *node24 = this->insertNode("intermediario", "5,4");
    Node *node25 = this->insertNode("intermediario", "5,3");
    Node *node26 = this->insertNode("intermediario", "6,3");
    Node *node27 = this->insertNode("intermediario", "6,2");
    Node *node28 = this->insertNode("intermediario", "7,2");
    Node *node29 = this->insertNode("intermediario", "7,3");
    Node *node30 = this->insertNode("intermediario", "6,4");
    Node *node31 = this->insertNode("intermediario", "9,4");
    Node *node32 = this->insertNode("intermediario", "9,3");
    Node *node33 = this->insertNode("intermediario", "8,3");
    Node *node34 = this->insertNode("intermediario", "8,1");
    Node *node35 = this->insertNode("intermediario", "9,1");
    Node *node36 = this->insertNode("intermediario", "9,2");
    Node *node37 = this->insertNode("intermediario", "7,1");
    Node *node38 = this->insertNode("intermediario", "7,0");
    Node *node39 = this->insertNode("intermediario", "6,0");
    Node *node40 = this->insertNode("final", "9,0");

    // 0 -- cima
    // 1 -- esquerda
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
