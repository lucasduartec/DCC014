/**************************************************************************************************
 * Implementation of the TAD Node
 **************************************************************************************************/

#ifndef TREENODE_H
#define TREENODE_H

#include <list>
#include "../maze/Edge.h"

using namespace std;

// Definição da classe nó

class TreeNode
{

private:
    int id;
    TreeNode *father; // Ponteiro para estado pai
    TreeNode *topChild;
    TreeNode *leftChild;
    TreeNode *downChild;
    TreeNode *rightChild;

    Edge *usedEdge; // Aresta usada para chegar naquele nó

    Edge *availableRules[4]; // Regras disponíveis aplicáveis a partir daquele nó

    bool backtracked; // Flag para saber se o nó realizou backtracking

    bool final; // Flag para saber se o estado é o final

    double cost;

public:
    TreeNode(int id);
    ~TreeNode();

    // Getters
    int getId() { return this->id; };
    TreeNode *getFather();
    TreeNode *getTopChild();
    TreeNode *getLeftChild();
    TreeNode *getDownChild();
    TreeNode *getRightChild();
    Edge *getUsedEdge();
    Edge **getAvailableRules();
    bool getBacktracked();
    bool isFinal();
    double getCost();

    // Setters
    void setFather(TreeNode *node);
    void setTopChild(TreeNode *node);
    void setLeftChild(TreeNode *node);
    void setDownChild(TreeNode *node);
    void setRightChild(TreeNode *node);
    void setUsedEdge(Edge *usedEdge);
    void setAvailableRules(Edge *rules[4]);
    void setBacktracked(bool backtracked);
    void setFinal();
    void setCost(double cost);
};

// Construtor
TreeNode::TreeNode(int id)
{
    this->id = id;
    this->usedEdge = nullptr;
    for (int i = 0; i < 4; i++)
        availableRules[i] = nullptr;

    this->backtracked = false;
}

// Destrutor
TreeNode::~TreeNode()
{
    this->id = -1;
    this->father = nullptr;
    this->topChild = nullptr;
    this->leftChild = nullptr;
    this->downChild = nullptr;
    this->rightChild = nullptr;
    this->usedEdge = nullptr;
    this->backtracked = false;
    for (int i = 0; i < 4; i++)
        availableRules[i] = nullptr;
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

Edge *TreeNode::getUsedEdge()
{
    return this->usedEdge;
}

Edge **TreeNode::getAvailableRules()
{
    return availableRules;
}

bool TreeNode::getBacktracked()
{
    return this->backtracked;
}

bool TreeNode::isFinal()
{
    return this->final;
}

double TreeNode::getCost()
{
    return this->cost;
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

void TreeNode::setUsedEdge(Edge *usedEdge)
{
    this->usedEdge = usedEdge;
}

void TreeNode::setAvailableRules(Edge *rules[4])
{
    for (int i = 0; i < 4; i++)
    {
        if (rules[i] == usedEdge)
            continue;
        availableRules[i] = rules[i];
    }
}

void TreeNode::setBacktracked(bool backtracked)
{
    this->backtracked = backtracked;
}

void TreeNode::setFinal()
{
    this->final = true;
}

void TreeNode::setCost(double cost)
{
    this->cost = cost;
}

#endif // TREENODE_H
