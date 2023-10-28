/**************************************************************************************************
 * Defining the Node's methods
 **************************************************************************************************/

#include "Node.h"
#include <iostream>

using namespace std;

// Construtor
Node::Node(){};

// Destrutor
Node::~Node()
{
    this->setFather = nullptr;
    this->setTopChild = nullptr;
    this->setLeftChild = nullptr;
    this->setDownChild = nullptr;
    this->setRightChild = nullptr;
};

// Getters
Node *Node::getFather()
{
    return this->father;
}

Node *Node::getTopChild()
{
    return this->topChild;
}

Node *Node::getLeftChild()
{
    return this->leftChild;
}

Node *Node::getDownChild()
{
    return this->downChild;
}

Node *Node::getRightChild()
{
    return this->rightChild;
}

// Setters

void Node::setFather(Node *newFather)
{
    this->father = newFather;
}

void Node::setTopChild(Node *newTopChild)
{
    this->topChild = newTopChild;
}

void Node::setLeftChild(Node *newLeftChild)
{
    this->leftChild = newLeftChild;
}

void Node::setDownChild(Node *newDownChild)
{
    this->downChild = newDownChild;
}

void Node::setRightChild(Node *newRightChild)
{
    this->rightChild = newRightChild;
}