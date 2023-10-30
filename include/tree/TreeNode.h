/**************************************************************************************************
 * Implementation of the TAD Node
 **************************************************************************************************/

#ifndef TREENODE_H
#define TREENODE_H

#include <list>
#include "Edge.h"

using namespace std;

// Definição da classe nó

class TreeNode
{

private:
    int state;
    TreeNode *father;
    TreeNode *topChild;
    TreeNode *leftChild;
    TreeNode *downChild;
    TreeNode *rightChild;

    // Regra usada para chegar naquele nó
    int usedRule;

    // Regras disponíveis aplicáveis a partir daquele nó
    Edge *availableRules[4];

public:
    // Construtor
    TreeNode(int state);

    // Destrutor
    ~TreeNode();

    // Getters
    TreeNode *getFather();
    TreeNode *getTopChild();
    TreeNode *getLeftChild();
    TreeNode *getDownChild();
    TreeNode *getRightChild();
    int getUsedRule();
    Edge **getAvailableRules();

    // Setters
    void setFather(TreeNode *node);
    void setTopChild(TreeNode *node);
    void setLeftChild(TreeNode *node);
    void setDownChild(TreeNode *node);
    void setRightChild(TreeNode *node);
    void setUsedRule(int usedRule);
    void setAvailableRules(Edge *rules[4]);
};

// Construtor
TreeNode::TreeNode(int state)
{
    this->state = state;
}

// Destrutor
TreeNode::~TreeNode()
{
    this->state = -1;
    this->father = nullptr;
    this->topChild = nullptr;
    this->leftChild = nullptr;
    this->downChild = nullptr;
    this->rightChild = nullptr;
    this->usedRule = -1;
}

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

int TreeNode::getUsedRule()
{
    return this->usedRule;
}

Edge **TreeNode::getAvailableRules()
{
    return availableRules;
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

void TreeNode::setUsedRule(int usedRule)
{
    this->usedRule = usedRule;
}

void TreeNode::setAvailableRules(Edge *rules[4])
{
    for (int i = 0; i < 4; i++)
    {
        availableRules[i] = rules[i];
    }
}

#endif // TREENODE_H
