/**************************************************************************************************
 * Defining the TreeNode's methods
 **************************************************************************************************/

#include "TreeNode.h"
#include <iostream>

using namespace std;

// Construtor
TreeNode::TreeNode(){};

// Destrutor
TreeNode::~TreeNode()
{
    this->father = nullptr;
    this->topChild = nullptr;
    this->leftChild = nullptr;
    this->downChild = nullptr;
    this->rightChild = nullptr;
};

// Getters
TreeNode *TreeNode::getFather()
{
    return this->father;
}

TreeNode *TreeNode::getTopChild()
{
    return this->topChild;
}

TreeNode *TreeNode::getLeftChild()
{
    return this->leftChild;
}

TreeNode *TreeNode::getDownChild()
{
    return this->downChild;
}

TreeNode *TreeNode::getRightChild()
{
    return this->rightChild;
}

// Setters

void TreeNode::setFather(TreeNode *node)
{
    this->father = node;
}

void TreeNode::setTopChild(TreeNode *node)
{
    this->topChild = node;
}

void TreeNode::setLeftChild(TreeNode *node)
{
    this->leftChild = node;
}

void TreeNode::setDownChild(TreeNode *node)
{
    this->downChild = node;
}

void TreeNode::setRightChild(TreeNode *node)
{
    this->rightChild = node;
}